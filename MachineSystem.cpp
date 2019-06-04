#include "Machine.h"
#include "Inventory.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

MachineSystem::MachineSystem()
{
	cout << "Initialize machines. Please wait..." << endl;
	readFile();
	cout << "Machines are ready." << endl;
}

void MachineSystem::readFile()
{
	ifstream infile;	      
	infile.open("machines.txt", ios::in);

	string model;
	int numMachines;
	int quarters, dimes, nickels;
	int numItems, itemID, quantity;		
	string selection;
	int count = 0;

	Inventory SystemProducts;

	if (!infile)
	{
		cout << "Cannot access machines.txt" << endl;
		exit(2);
	}
	else
	{
		while (infile >> model && model != "100D")
		{
			infile >> numMachines;
			
			for (int i = 0; i < numMachines; i++)
			{
				//create machine

				if (model == "100A")
				{
					pM[count] = new MachineA;
				}
				else if (model == "100B")
				{
					pM[count] = new MachineB;
				}
				else if (model == "100C")
				{
					pM[count] = new MachineC;
				}
				else
				{
					pM[count] = new Machine;

				}

				pM[count]->setModel(model);
				pM[count]->setMachineName(model, i);

				infile >> quarters >> dimes >> nickels;
				pM[count]->setCoins(quarters, dimes, nickels);
				pM[count]->initializeBalances();

				infile >> numItems;
				pM[count]->setNumItems(numItems);

				for (int i = 0; i < numItems; i++)
				{

					infile >> selection >> itemID >> quantity;

					Items OneInventory = SystemProducts.checkOut(itemID, quantity);
					pM[count]->setItem(selection, i, OneInventory);

				}
				count++;
				totalMachines++;
			}

		}
	}
		infile.close();
}

void MachineSystem::printAvaliable()
{
	cout << "Available machines: ";
	cout << pM[0]->getMachineName();
	for (int i = 0; i < totalMachines; i++)
	{
		cout << ", " << pM[i]->getMachineName();
	}
	cout << endl;
}

void MachineSystem::purchase()
{
	int MachineIndex, itemIndex;
	string MachineSelection, itemSelection;
	cout << "Select a machine--> ";
	cin >> MachineSelection;
	while (MachineSelection != SECRET_CODE)
	{
		MachineIndex = findMachine(MachineSelection);
		if (MachineIndex != -1)
		{
			pM[MachineIndex]->machineAccepts();
			pM[MachineIndex]->printAvailableItems();
			cout << "Select an item --> ";
			cin >> itemSelection;
			itemIndex = pM[MachineIndex]->findItem(itemSelection);
			if (itemIndex != -1)
			{
				pM[MachineIndex]->outputItemInfo(itemSelection);
				pM[MachineIndex]->acceptMoney(itemIndex);
			}
			else
			{
				cout << "Your selection is not avaliable in this machine" << endl;
			}
		}
		else
		{
			cout << "This Machine is not in the system" << endl;
		}

		cout << "\nSelect a machine--> ";
		cin >> MachineSelection;
	}
}


int MachineSystem::findMachine(string s)
{
	for (int i = 0; i < totalMachines; i++)
	{
		if (s == pM[i]->getMachineName())
		{
			return i;
		}
	}

	return -1;
}

void MachineSystem::printAllMachines()
{
	for (int i = 0; i < totalMachines; i++)
	{
		pM[i]->printMachine();
	}
}

MachineSystem::~MachineSystem()
{
	ofstream out("reports.txt");
	out.close();

	cout << "Report is generating..." << endl;
	for (int i = 0; i < totalMachines; i++)
	{
		delete pM[i];
		pM[i] = 0;
	}
	cout << "System is shutting down." << endl;
}
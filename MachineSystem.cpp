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
	ifstream infile;	      // Input file to read values into array
	infile.open("C:\\Users\\jessm\\Documents\\GitHub\\project4_CSCI140\\machines.txt", ios::in);

	string model;
	int numMachines;
	int quarters, dimes, nickels;
	int numItems, itemID, quantity;		// amount of items of that type that can be put into the machine
	string selection;
	int count = 0;

	// Change?
	Inventory SystemProducts;

	if (!infile)
	{
		cout << "Cannot access machines.txt" << endl;
		exit(2);
	}
	else
	{
		while (infile >> model)
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
				//else if (model == "100D")
				//{
				//	pM[count] = new MachineD;
				//}
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
					// create item object or struct

					infile >> selection >> itemID >> quantity;

					// SystemProducts.getDescription(itemID);

					Items OneInventory = SystemProducts.checkOut(itemID, quantity);
					//pM[count]->setProduct(selection, OneInventory, i);
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
	// Print the machines with two steps to deal with commas 
	// Print the first machine
	cout << pM[0]->getMachineName();
	// Print the rest
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
	while (MachineSelection != "spring19")
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
	ofstream out("machinesOutput.txt");
	out.close();

	cout << "Report is generating..." << endl;
	for (int i = 0; i < totalMachines; i++)
	{
		delete pM[i];
		pM[i] = 0;
	}
	cout << "System is shutting down." << endl;
}
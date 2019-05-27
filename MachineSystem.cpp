#include "MachineCopy.h"
#include "Inventory.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//Inventory Product;

void MachineSystem::setNewObject(Machine m, int index) // add object to array
{
	pM[index] = &m;
	cout << m.getModel() << endl;

	//system("pause");
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
		cout << "Cannot access file" << endl;
	}
	else
	{
		while (infile >> model)
		{
			//Machine m;
			//cout << "File accessed" << endl;
			//m.setModel(model);
			infile >> numMachines;
			cout << "Model: " << model << endl << "Number of machines: " << numMachines << endl;
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
				pM[count]->setMachineName(model);

				infile >> quarters >> dimes >> nickels;
				cout << "Quarters: " << quarters << endl;
				cout << "Dimes: " << dimes << endl;
				cout << "Nickels: " << nickels << endl;
				cout << endl;
				pM[count]->setCoins(quarters, dimes, nickels);

				infile >> numItems;
				pM[count]->setNumItems(numItems);

				for (int i = 0; i < numItems; i++)
				{
					// create item object or struct

					infile >> selection >> itemID >> quantity;

					cout << "Selection: " << selection << endl;
					cout << "Item ID: " << itemID << endl;
					cout << "Quantity: " << quantity << endl << endl;

					// SystemProducts.getDescription(itemID);

					Items OneInventory = SystemProducts.checkOut(itemID, quantity);
					//pM[count]->setProduct(selection, OneInventory, i);
					pM[count]->setItem(selection, i, OneInventory);

				}
				//setNewObject(m, count);
				count++;
				totalMachines++;
			}

		}
	}
		infile.close();
}

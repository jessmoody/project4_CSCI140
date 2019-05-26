#include "[Jessica]Machine - Copy.h"
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
	infile.open(/*"D:\\CSCI140\\Project 4\\Visual Studio Solution\\Project4\\Debug\\machines.txt", ios::in*/"machines.txt");

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


			if (model == "100A")
			{
				infile >> numMachines;
				cout << "Model: " << model << endl << "Number of machines: " << numMachines << endl;
				for (int i = 0; i < numMachines; i++)
				{
					//create machine
					pM[count] = new MachineA;
					pM[count]->setModel(model);

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

						Items OneInventory = SystemProducts.checkOut(itemID, quantity);
						//pM[count]->setProduct(selection, OneInventory, i);
						pM[count]->setItem(selection, i, OneInventory);

					}
					//setNewObject(m, count);
					count++;
					totalMachines++;
				}
			}
			else if (model == "100B")
			{
				infile >> numMachines;
				cout << "Model: " << model << endl << "Number of machines: " << numMachines << endl;
				for (int i = 0; i < numMachines; i++)
				{
					//create machine
					pM[count] = new MachineB;
					pM[count]->setModel(model);

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

						Items OneInventory = SystemProducts.checkOut(itemID, quantity);
						//pM[count]->setProduct(selection, OneInventory, i);
						pM[count]->setItem(selection, i, OneInventory);
					}
					//setNewObject(m, count);
					count++;
					totalMachines++;

				}
			}
			else if (model == "100C")
			{
				infile >> numMachines;
				cout << "Model: " << model << endl << "Number of machines: " << numMachines << endl;
				for (int i = 0; i < numMachines; i++)
				{
					//create machine
					pM[count] = new MachineC;
					pM[count]->setModel(model);

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

	}

	infile.close();
}

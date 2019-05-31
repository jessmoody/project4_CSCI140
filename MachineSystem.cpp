/*
5/30 
*/

#include "Machine.h"
#include "Inventory.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//Inventory Product;

void MachineSystem::readFile()
{
	ifstream infile;	      // Input file to read values into array
	infile.open(/*"C:\\Users\\jessm\\Documents\\GitHub\\project4_CSCI140\\machines.txt"*/"machines.txt", ios::in);

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
				else
				{
					pM[count] = new Machine;

				}

				pM[count]->setModel(model);
				pM[count]->setMachineName(model, i);

				infile >> quarters >> dimes >> nickels;
				pM[count]->setCoins(quarters, dimes, nickels);
				pM[count]->InitializeBalances();

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

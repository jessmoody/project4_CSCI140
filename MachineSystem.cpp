#include "Machine.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void MachineSystem::setNewObject(Machine &m, int index) // add object to array
{
	pM[index] = &m;
	cout << m.getModel() << endl;
}

void MachineSystem::readFile(Machine *mPtr[])
{
	ifstream infile;

	// filename based on computer used
	infile.open("C:\\Users\\jessm\\Documents\\GitHub\\project4_CSCI140\\machines.txt", ios::in);

	string model;
	int numMachines;
	int quarters, dimes, nickels;
	int numItems, itemID, quantity;
	string selection;
	int count = 0;

	if (!infile)
	{
		cout << "Cannot access file" << endl;
	}
	else
	{
		cout << "File accessed" << endl;
		while (infile >> model)
		{

			infile >> numMachines;

			cout << "Model: " << model << endl << "Number of machines: " << numMachines << endl;

			for (int i = 0; i < numMachines; i++)
			{
				cout << model << endl;
				mPtr[count]->setModel(model);
				infile >> quarters >> dimes >> nickels;
				infile >> numItems;

				mPtr[count]->setCoins(quarters, dimes, nickels);

				//cout << "Quarters: " << mPtr[count]->getQuarters() << endl;
				//cout << "Dimes: " << dimes << endl;
				//cout << "Nickels: " << nickels << endl;
				cout << endl;


				mPtr[count]->setNumItems(numItems);

				for (int i = 0; i < numItems; i++)
				{
					// create item object or struct

					infile >> selection >> itemID >> quantity;

					//cout << "Selection: " << selection << endl;
					//cout << "Item ID: " << itemID << endl;
					//cout << "Quantity: " << quantity << endl << endl;

					mPtr[count]->setItem(selection, itemID, quantity, i);
				}
				cout << "End of machine" << endl;
				//setNewObject(m, count);

				//cout << "Count: " << count << endl;

				count++;


			}

			if (!infile)
			{
				cout << "End of file." << endl;
			}
		}
	}

	setPtr(mPtr, count);
	setTotalMachines(count);

	infile.close();
}



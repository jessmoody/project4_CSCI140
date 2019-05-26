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

void MachineSystem::readFile(Machine arr[])
{
	ifstream infile;	      // Input file to read values into array
	infile.open("C:\\Users\\jessm\\Documents\\GitHub\\project4_CSCI140\\machines.txt", ios::in);

	string model;
	int numMachines;
	int quarters, dimes, nickels;
	int numItems, itemID, quantity;		// amount of items of that type that can be put into the machine
	string selection;
	int count = 0;

	if (!infile)
	{
		cout << "Cannot access file" << endl;
	}
	else
	{
		while (infile >> model)
		{

			cout << "File accessed" << endl;

			infile >> numMachines;

			//cout << "Model: " << model << endl << "Number of machines: " << numMachines << endl;

			for (int i = 0; i < numMachines; i++)
			{
				cout << model << endl;
				//mPtr[count]->setModel(model);
				arr[count].setModel(model);
				infile >> quarters >> dimes >> nickels;
				infile >> numItems;

				//mPtr[count]->setCoins(quarters, dimes, nickels);
				arr[count].setCoins(quarters, dimes, nickels);

				//cout << "Quarters: " << arr[count].getQuarters() << endl;
				//cout << "Dimes: " << dimes << endl;
				//cout << "Nickels: " << nickels << endl;
				//cout << endl;


				//mPtr[count]->setNumItems(numItems);
				arr[count].setNumItems(numItems);

				for (int i = 0; i < numItems; i++)
				{
					// create item object or struct

					infile >> selection >> itemID >> quantity;

					//cout << "Selection: " << selection << endl;
					//cout << "Item ID: " << itemID << endl;
					//cout << "Quantity: " << quantity << endl << endl;

					//mPtr[count]->setItem(selection, itemID, quantity, i);
					arr[count].setItem(selection, itemID, quantity, i);
				}
				cout << "End of machine" << endl;
				//setNewObject(m, count);
				//arr[count].printMachine();
				cout << "Count: " << count << endl;

				count++;


			}

			if (!infile)
			{
				cout << "End of file." << endl;
			}
		}

	}
	//m.setPtr(mPtr, count);
	setArray(arr, count);
	setTotalMachines(count);

	infile.close();
}

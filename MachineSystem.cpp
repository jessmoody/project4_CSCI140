#include "Machine.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void MachineSystem::setNewObject(Machine m, int index) // add object to array
{
	pM[index] = &m;
	cout << m.getModel() << endl;
}

void MachineSystem::readFile()
{
	ifstream infile;	      // Input file to read values into array
	infile.open("D:\\CSCI140\\Project 4\\Visual Studio Solution\\Project4\\Debug\\machines.txt", ios::in);

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
			Machine m;
			//cout << "File accessed" << endl;
			m.setModel(model);
			infile >> numMachines;

			cout << "Model: " << model << endl << "Number of machines: " << numMachines << endl;

			for (int i = 0; i < numMachines; i++)
			{
				//create machine
				infile >> quarters >> dimes >> nickels;
				infile >> numItems;

				cout << "Quarters: " << quarters << endl;
				cout << "Dimes: " << dimes << endl;
				cout << "Nickels: " << nickels << endl;
				cout << endl;

				for (int i = 0; i < numItems; i++)
				{
					// create item object or struct

					infile >> selection >> itemID >> quantity;

					cout << "Selection: " << selection << endl;
					cout << "Item ID: " << itemID << endl;
					cout << "Quantity: " << quantity << endl << endl;
				}
				setNewObject(m, count);
				count++;
			}


		}

	}

	infile.close();
}

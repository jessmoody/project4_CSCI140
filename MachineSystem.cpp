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

			for (int i = 0; i < numMachines; i++)
			{
				cout << model << endl;
				arr[count].setModel(model);
				infile >> quarters >> dimes >> nickels;
				infile >> numItems;

				arr[count].setCoins(quarters, dimes, nickels);
				arr[count].setNumItems(numItems);

				for (int i = 0; i < numItems; i++)
				{
					infile >> selection >> itemID >> quantity;

					arr[count].setItem(selection, itemID, quantity, i);
				}
				
				cout << "End of machine" << endl;
				count++;
			}
		}

	}
	
	setArray(arr, count);
	setTotalMachines(count);

	infile.close();
}

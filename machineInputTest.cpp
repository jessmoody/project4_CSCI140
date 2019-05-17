#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>


using namespace std;

int main()
{
	ifstream infile;	      // Input file to read values into array
	infile.open("C:\\Users\\jessm\\Documents\\GitHub\\project4_CSCI140\\testMachineA.txt", ios::in);

	string model;
	int numMachines;
	int quarters, dimes, nickels;
	int numItems, itemID, quantity;		// amount of items of that type that can be put into the machine
	string selection;	
	int number = 0;
	
	if (!infile)
	{
		cout << "Cannot access file" << endl;
	}
	else
	{
		while (!infile.eof())
		{
			//cout << "File accessed" << endl;

			infile >> model >> numMachines;

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

			}


		}
	}

	

	infile.close();

	return 0;
}
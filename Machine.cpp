#include "Machine.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

Machine::Machine()
{
	printf("This is machine\n");

	model = "0";
	//numMachines = 0;
	inputCoin.quarters = 0;
	inputCoin.dimes = 0;
	inputCoin.nickels = 0;
	numItems = 0;
	for (int i = 0; i < SIZE; i++)
	{
		items[i].itemID = 0;
		items[i].quantity = 0;
		items[i].selection = "0";
	}
}

void Machine::printAvailableItems()
{
	for (int i = 0; i < numItems; i++)
	{
		cout << items[i].selection << "\t"
			 << items[i].price << "\t"
			 << items[i].description << endl;
	}
}

void Machine::printMachine()
{
	cout << "Machine Model: " << model << endl;
	cout << "Quarters: " << inputCoin.quarters << endl;
	cout << "Dimes: " << inputCoin.dimes << endl;
	cout << "Nickels: " << inputCoin.nickels << endl;
	cout << "Number of items: " << numItems << endl << endl;
	cout << "Items: " << endl;
	for (int i = 0; i < numItems; i++)
	{
		cout << "Selection: " << items[i].selection << endl
			<< "Item ID: " << items[i].itemID << endl
			<< "Quantity: " << items[i].quantity << endl
			<< "Description: " << items[i].description << endl
			<< "Price: " << fixed << showpoint << setprecision(2)
			<< (items[i].price)/100 << endl << endl;
	}
}

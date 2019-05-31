#include "Machine.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

Machine::Machine()
{
	model = "0";

	inputCoin.quarters = 0;
	inputCoin.dimes = 0;
	inputCoin.nickels = 0;

	// *****Change 5/27*****
	initialDollars = currentDollars = 0;
	currentCoin = inputCoin;
	transactions = 0;
	totalCost = 0;
	//initialBalance = currentBalance = 0;

	numItems = 0;
	// *****Change 5/27*****
	for (int i = 0; i < SIZE; i++)
	{
		items[i].itemID = 0;
		items[i].initialQuantity = 0;
		items[i].currentQuantity = 0;
		items[i].selection = "0";
		items[i].description = "0";
		items[i].price = 0;
	}

}

void Machine::printAvailableItems()
{
	cout << "Available Items:" << endl;
	for (int i = 0; i < numItems; i++)
	{
		if (items[i].currentQuantity != 0)		// *****Change 5/27*****
		{
			cout << "    " << items[i].selection << " ";
			std::cout << std::setfill(' ') << std::setw(3) << std::right
				<< items[i].price << " " << items[i].description << endl;
		}
	}
}

void Machine::printMachine()
{
	cout << "Machine Model: " << model << endl;
	cout << "Machine Name: " << machineName << endl;
	cout << "Quarters: " << inputCoin.quarters << endl;
	cout << "Dimes: " << inputCoin.dimes << endl;
	cout << "Nickels: " << inputCoin.nickels << endl;
	cout << "Number of items: " << numItems << endl << endl;
	cout << "Items: " << endl;
	for (int i = 0; i < numItems; i++)
	{
		cout << "Selection: " << items[i].selection << endl
			<< "Item ID: " << items[i].itemID << endl
			<< "Quantity: " << items[i].currentQuantity << endl		// *****Change 5/27*****
			<< "Description: " << items[i].description << endl
			<< "Price: " << items[i].price << endl << endl;
	}
}

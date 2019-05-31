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

// ONLY call this in initialization
void Machine::setCoins(int q, int d, int n)
{
	inputCoin.quarters = q;
	inputCoin.dimes = d;
	inputCoin.nickels = n;

	// *****Change 5/27*****
	currentCoin = inputCoin;
}

void Machine::setItem(string s, int n, Items OneProd)
{
	items[n].itemID = OneProd.id;
	items[n].initialQuantity = OneProd.quantity;	// *****Change 5/27*****
	items[n].description = OneProd.menu;
	items[n].price = OneProd.price;
	items[n].selection = s;

	// *****Change 5/27*****
	items[n].currentQuantity = items[n].initialQuantity;
}

void Machine::setMachineName(string s1, int n)
{
	int a = n + 1;
	string s2;
	s2 = to_string(a);
	machineName = s1 + s2;
}

double Machine::InitializeBalances()
{
	// Maybe we can declare constants
	double balance = initialDollars + 0.25 * inputCoin.quarters + 0.10 * inputCoin.dimes + 0.05 * inputCoin.nickels;
	initialBalance = currentBalance = balance;
	return balance;
}

int Machine::findItem(string s)
{
	for (int i = 0; i < numItems; i++)
	{
		if (s == items[i].selection)
		{
			if (items[i].currentQuantity != 0)
			{
				return i;
			}
		}
	}
	return -1;
}

void Machine::outputItemInfo(string userInput)
{
	int index2;
	index2 = findItem(userInput);
	if (index2 != -1)
	{
		cout << "You selected \""
			<< items[index2].description << "\"." << endl
			<< "The cost of this item is " << items[index2].price
			<< " cents." << endl;
	}
	else
	{
		cout << "Item not found" << endl;
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

//TODO: remove this before submission
void Machine::printInventory()
{
	cout << "Machine inventory:\n"
		<< "Code        Id       Description             Initial     Current" << endl;
	for (int i = 0; i < numItems; i++)
	{
		cout << setw(4) << items[i].selection
			<< setw(10) << items[i].itemID << "       "
			<< left << setw(27) << items[i].description
			<< right << setw(2) << items[i].initialQuantity
			<< setw(12) << items[i].currentQuantity << endl;
	}
}

// Destructor
// Open a file and record the machine information
Machine::~Machine()
{
	ofstream outM;
	outM.open("machinesOutput.txt", ios::app);	// TO be closed
	if (!outM)
	{
		cout << "Error: Cannot open machinesOutput.txt" << endl;
		exit(3);
	}

	outM << "Machine: " << machineName << endl;
	outM << fixed << setprecision(2);
	outM << "Initial balance: $" << initialBalance /* << calcBalance(inputCoin, initialDollars)*/
		<< " (" << initialDollars << " $, " << inputCoin.quarters << " Q, "
		<< inputCoin.dimes << " D, " << inputCoin.nickels << " N)" << endl;
	outM << "Number of valid transactions: " << transactions << endl;
	outM << "Total cost: $" << totalCost << endl;
	outM << "Current balance: $" << currentBalance /*<< calcBalance(currentCoin, currentDollars)*/
		<< " (" << currentDollars << " $, " << currentCoin.quarters << " Q, "
		<< currentCoin.dimes << " D, " << currentCoin.nickels << " N)" << endl;
	outM << endl;

	// Print inventory
	outM << "Machine inventory:\n"
		<< "Code        Id       Description            Initial     Current" << endl;
	for (int i = 0; i < numItems; i++)
	{
		outM << setw(4) << items[i].selection
			<< setw(10) << items[i].itemID << "       "
			<< left << setw(25) << items[i].description
			<< right << setw(2) << items[i].initialQuantity
			<< setw(12) << items[i].currentQuantity << endl;
	}
	outM << endl;
	outM.close();
}

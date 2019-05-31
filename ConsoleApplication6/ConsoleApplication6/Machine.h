#pragma once
#include "Inventory.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include<cstdlib>


using namespace std;

const int SIZE = 8;

class Machine
{
protected:
	string model;
	string machineName;
	//int numMachines;
	struct Coins
	{
		int quarters;
		int dimes;
		int nickels;
	};
	Coins inputCoin;
	Coins currentCoin;

	int initialDollars = 0;
	int currentDollars = 0;

	int transactions = 0;
	double totalCost = 0; // In dollars
	double initialBalance = 0;
	double currentBalance = 0;
	int numItems;
	struct OneItem
	{
		string selection, description;
		int itemID, initialQuantity, currentQuantity, price;
	};
	OneItem items[SIZE];

public:
	Machine();
	void setModel(string m) { model = m; }
	void printAvailableItems();
	//void setNumMachines(int nm) { numMachines = nm; }
	void setCoins(int q, int d, int n)
	{
		inputCoin.quarters = q;
		inputCoin.dimes = d;
		inputCoin.nickels = n;
	}
	void setNumItems(int ni) { numItems = ni; }
	void setItem(string s, int n, Items OneProd)
	{
		items[n].itemID = OneProd.id;
		items[n].initialQuantity = OneProd.quantity;	// *****Change 5/27*****
		items[n].description = OneProd.menu;
		items[n].price = OneProd.price;
		items[n].selection = s;

		// *****Change 5/27*****
		items[n].currentQuantity = items[n].initialQuantity;
	}
	double InitializeBalances()
	{
		// Maybe we can declare constants
		double balance = initialDollars + 0.25 * inputCoin.quarters + 0.10 * inputCoin.dimes + 0.05 * inputCoin.nickels;
		initialBalance = currentBalance = balance;
		return balance;
	}
	void setMachineName(string s1, int n)
	{
		int a = n + 1;
		string s2;
		s2 = to_string(a);
		machineName = s1 + s2;
	}
	string getModel() { return model; }
	string getMachineName() { return machineName; }
	//int getNumMachines() { return numMachines; }
	int findItem(string s)
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
	// temporary function to print lines after 
	// "select an item" in user interface
	void outputItemInfo(string userInput)
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
	virtual void acceptMoney(int index)
	{
		cout << "acceptMoney in Machine class" << endl;
	}
	virtual void printMachine();
	void printAvailableItems();

	// Destructor
	// Open a file and record the machine information
	~Machine()
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


	//TODO: remove this before submission	
	void printInventory()
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
	
};

class MachineA : public Machine
{
private:

public:
	MachineA() { };
};

class MachineB : public Machine
{
private:

public:
	MachineB() { };
};

class MachineC : public Machine
{
private:
	string cardEntered;
public:
	MachineC() { };
	virtual void printMachine() override;
};

class MachineSystem
{
protected:
	Machine * pM[SIZE] = { 0 };
	int totalMachines = 0;

public:
	MachineSystem()
	{
		readFile();
	}
	void readFile();
	// function for user input in main - will be updated
	void purchase(string s)
	{
		int MachineIndex, itemIndex;
		string userInput;
		MachineIndex = findMachine(s);
		if (MachineIndex != -1)
		{
			pM[MachineIndex]->printAvailableItems();
			cout << "Select an item --> ";
			cin >> userInput;
			itemIndex = pM[MachineIndex]->findItem(userInput);
			if (itemIndex == -1)
			{
				cout << "Your selection is not avaliable in the machine" << endl;
				return;
			}
			pM[MachineIndex]->outputItemInfo(userInput);
		}
		else
		{
			cout << "Machine not found" << endl;
			return;
		}

		pM[MachineIndex]->acceptMoney(itemIndex);
	}
	int findMachine(string s)
	{
		for (int i = 0; i < totalMachines; i++)
		{
			if (s == pM[i]->getMachineName())
			{
				return i;
			}
		}

		return -1;
	}
	void printAllMachines()
	{
		for (int i = 0; i < totalMachines; i++)
		{
			pM[i]->printMachine();
		}
	}
	//~MachineSystem() 
	//{ 
	//	Machine m;
	//	for (int i = 0; i < SIZE; i++) 
	//	{
	//		delete pM[i];
	//		pM[i] = &m;
	//	}
	//}

	//TODO: remove this before submission	
	void printMInv()
	{
		pM[0]->printInventory();
	}

	~MachineSystem()
	{

		// TODO: remove this before submission
		ofstream out("machinesOutput.txt");
		out.close();

		cout << "Report is generating..." << endl;
		for (int i = 0; i < totalMachines; i++)
		{
			delete pM[i];
			pM[i] = 0;
		}
		cout << "System is shutting down." << endl;
	}
};

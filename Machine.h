#pragma once

#include "Inventory.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

const int SIZE = 8;

class Machine
{
protected:
	string model;
	string machineName;
	struct Coins
	{
		int quarters;
		int dimes;
		int nickels;
	};
	Coins initialCoin;
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
	void setModel(string m)
	{
		model = m;
	}
	void setCoins(int q, int d, int n);
	void setNumItems(int ni) { numItems = ni; }
	// ONLY call this in initialization
	void setItem(string s, int n, Items OneProd);
	void setMachineName(string s1, int n);
	// *****Change 5/27*****
	// Calculate the machine balance in dollars
	// Can calculate the initial and current balance
	// ***** Change 5/28: change it to virtual *****
	double InitializeBalances();
	string getModel(){	return model;	}
	string getMachineName() { return machineName; }
	int findItem(string s);
	// temporary function to print lines after 
	// "select an item" in user interface
	void outputItemInfo(string userInput);
	virtual void acceptMoney(int index)
	{
		cout << "acceptMoney in Machine class" << endl;
		return false;
	}
	virtual void printMachine();
	void printAvailableItems();
	//TODO: remove this before submission	
	void printInventory();
	// Destructor
	// Open a file and record the machine information
	~Machine();
};

class MachineA : public Machine
{
private:

public:
	MachineA()
	{
		/*printf("This is machineA\n")*/;
	}
	//virtual void acceptMoney() override;
	

};

class MachineB : public Machine
{
private:
	
public:
	MachineB()
	{
		/*printf("This is machineB\n")*/;

	}
	//virtual void acceptMoney() override;
};

class MachineC : public Machine
{
private:
	string cardEntered;
public:
	MachineC()
	{
		/*printf("This is machineC\n")*/;
	}
	//double calculateBalance(int totalCents);
	bool validateCreditCard(string n);
	virtual void acceptMoney(int index); /*override*/
	virtual double calcBalance(Coins c, int dollars);
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

		bool successfulTransaction = pM[MachineIndex]->acceptMoney(itemIndex);
		if (successfulTransaction)
		{
			cout << "Thank you! Please take your item." << endl;
		}

	}

	void purchase()
	{
		int MachineIndex, itemIndex;
		string MachineSelection, itemSelection;
		cout << "Select a machine--> ";
		cin >> MachineSelection;
		while (MachineSelection != "spring19")
		{
			MachineIndex = findMachine(MachineSelection);
			if (MachineIndex != -1)
			{
				pM[MachineIndex]->printAvailableItems();
				cout << "Select an item --> ";
				cin >> itemSelection;
				itemIndex = pM[MachineIndex]->findItem(itemSelection);
				if (itemIndex != -1)
				{
					pM[MachineIndex]->outputItemInfo(itemSelection);
					pM[MachineIndex]->acceptMoney(itemIndex);
				}
				else
				{
					cout << "Your selection is not avaliable in this machine" << endl;
				}
			}
			else
			{
				cout << "This Machine is not in the system" << endl;
			}

			cout << "\nSelect a machine--> ";
			cin >> MachineSelection;
		}
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
	~MachineSystem();
};

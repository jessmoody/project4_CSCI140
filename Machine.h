//outline of a potential class structure

#pragma once
#include <iostream>
#include <string>

using namespace std;

const int SIZE = 8;

class Machine
{
protected:
	string model;
	//int numMachines;
	struct Coins
	{
		int quarters;
		int dimes;
		int nickels;
	};
	Coins inputCoin;
	int numItems;
	struct OneItem
	{
		string selection;
		int itemID, quantity;
	};
	OneItem items[SIZE];

public:
	Machine() 
	{ 
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
	void setModel(string m)
	{
		model = m;
	}
	string getModel()
	{
		return model;
	}
	//void setNumMachines(int nm) { numMachines = nm; }
	void setCoins(int q, int d, int n)
	{
		inputCoin.quarters = q;
		inputCoin.dimes = d;
		inputCoin.nickels = n;
	}
	void setNumItems(int ni) { numItems = ni; }
	void setItem(string s, int id, int q, int n)
	{
		items[n].selection = s;
		items[n].itemID = id;
		items[n].quantity = q;
	}
	//int getNumMachines() { return numMachines; }
	int getNumItems() { return numItems; }
	int getQuarters()
	{
		return inputCoin.quarters;
	}
	virtual void printMachine()
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
				<< "Quantity: " << items[i].quantity << endl << endl;
		}
	}

	//// These are just my functions from Project 1 - some are modified
	//double calculateBalance(int totalCents);
	//bool validation(string userInput);
	//void print();
	//void printInstructions(double balance);
	//void printFinalReport(double balance, int totalCents);
	//// functions added for Project 4
	//int calculateTotalCents(Coin c);	// add up quarters, dimes and nickels
	//void getInventory();		// not actually void
};

class MachineA : public Machine
{
private:
	struct Coin
	{
		int quarters;
		int dimes;
		int nickels;
	};

public:
	MachineA() { ; }
	//bool makeChange(int amount, Coin &machine, Coin &back);
	//double calculateBalance(int totalCents, Coin c);
	
};

class MachineB : public Machine
{
private:
	struct Coin
	{
		int quarters;
		int dimes;
		int nickels;
	};
public:
	MachineB() { ; }
	//bool makeChange(int amount, Coin &machine, Coin &back);
	//double calculateBalance(int totalCents);
	
};

class MachineC : public Machine
{
private:
	string cardEntered;
public:
	MachineC() 
	{ 
		cout << "MachineC created" << endl; 
	}
	//double calculateBalance(int totalCents);
	//bool validateCreditCard(string n);
	virtual void printMachine() override
	{
		cout << "Machine Model: " << model << endl;
		cout << "No coins.  This machine takes credit cards only" << endl;
		cout << "Number of items: " << numItems << endl << endl;
		cout << "Items: " << endl;
		for (int i = 0; i < numItems; i++)
		{
			cout << "Selection: " << items[i].selection << endl
				<< "Item ID: " << items[i].itemID << endl
				<< "Quantity: " << items[i].quantity << endl << endl;
		}
	}
};

class MachineSystem
{
protected:
	MachineA *a;
	MachineB *b;
	MachineC *c;
	Machine *defaultMachine;
	Machine * pM[SIZE] = { a, a, b, c, c, defaultMachine };
	int totalMachines;

public:
	MachineSystem() { ; }
	void setNewObject(Machine &m, int index);
	void readFile(Machine *arr[]);
	virtual void printAllMachines()
	{
		for (int i = 0; i < totalMachines; i++)
		{
			pM[i]->printMachine();
		}
	}
	void setTotalMachines(int n)
	{
		totalMachines = n;
	}
	int getTotalMachines()
	{
		return totalMachines;
	}

	void setPtr(Machine *arr[], int n)
	{
		for (int i = 0; i < n; i++)
		{
			pM[i] = arr[i];
		}
	}


	void setArray(Machine arr[], int n)
	{
		for (int i = 0; i < n; i++)
		{
			pM[i] = &arr[i];
		}
	}
};
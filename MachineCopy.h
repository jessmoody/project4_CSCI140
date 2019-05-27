//outline of a potential class structure

#pragma once

#include "Inventory.h"
#include <iostream>
#include <string>

using namespace std;

const int SIZE = 8;

class Machine
{
protected:
	string model;
	int numMachines;
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

	struct OneProduct
	{
		string selection;
		Items OneInventory;
	};
	OneProduct ProductList[SIZE];

public:
	Machine()
	{
		printf("This is machine\n");
	}

	void setModel(string m)
	{
		model = m;
	}
	string getModel()
	{
		return model;
	}
	void setNumMachines(int nm) { numMachines = nm; }
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
	void setItem(string s, int n, Items OneProd)
	{
		// Missing price and menu
		items[n].itemID = OneProd.id;
		items[n].quantity = OneProd.quantity;
		items[n].selection = s;
	}
	void setProduct(string selection, Items OneInventory, int n)
	{
		ProductList[n].selection = selection;
		ProductList[n].OneInventory = OneInventory;
	}
	void printMachine()
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
	MachineA()
	{
		printf("This is machineA\n");
	}
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
	MachineB()
	{
		printf("This is machineB\n");

	}
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
		printf("This is machineC\n");

	}
	//double calculateBalance(int totalCents);
	//bool validateCreditCard(string n);

};

class MachineSystem
{
protected:
	Machine * pM[SIZE];
	int totalMachines = 0;


public:
	MachineSystem()
	{
		readFile();
	}
	void setNewObject(Machine m, int index);
	void readFile();
	void printAllMachines()
	{
		for (int i = 0; i < totalMachines; i++)
		{
			pM[i]->printMachine();
		}
	}
	~MachineSystem() { delete[] pM; }
};

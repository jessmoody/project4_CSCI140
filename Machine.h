// Changed initializeBalance
// New function: totalCoins

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
	int totalCoins(Coins c);	// Calculate how many cents in the coins
	double InitializeBalances();
	string getModel(){	return model;	}
	string getMachineName() { return machineName; }
	int findItem(string s);
	// temporary function to print lines after 
	// "select an item" in user interface
	void outputItemInfo(string userInput);
	virtual void machineAccepts();
	virtual bool acceptMoney(int index)
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
	Coins change;
public:
	MachineA()
	{
		/*printf("This is machineA\n")*/;
	}
	virtual void machineAccepts();
	virtual bool acceptMoney(int index);
	bool makeChangesOfdollar(int amount, Coins &machine, Coins &back);
	void printCoin(Coins c);

};

class MachineB : public Machine
{
private:
	Coins change;
	
public:
	MachineB()
	{
		/*printf("This is machineB\n")*/;

	}
	virtual void machineAccepts();
	virtual bool acceptMoney(int index);
	bool makeChangesOfCoins(int amount, int q, int d, int n, Coins &machine, Coins &back);
	void printCoin(Coins c);
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
	virtual void machineAccepts();
	virtual bool acceptMoney(int index); /*override*/
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
	void purchase();
	int findMachine(string s);
	void printAllMachines();
	void printMInv();
	void printAvaliable();
	~MachineSystem();
};

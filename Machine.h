// Rename function: totalCoins -> totalCents

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
const int QUARTER = 25,
			DIME = 10,
			NICKLE = 5,
			DOLLAR = 100;


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
	int totalCents(Coins c);	// Calculate how many cents in the coins
	double initializeBalances();
	string getModel(){	return model;	}
	string getMachineName() { return machineName; }
	int findItem(string s);
	void outputItemInfo(string userInput);
	virtual void machineAccepts();
	virtual bool acceptMoney(int index)
	{
		cout << "acceptMoney in Machine class" << endl;
		return false;
	}
	//bool acceptDollar(int index);
	//bool acceptCoin(int index);
	//bool acceptCard(int index);
	virtual void printMachine();
	void printAvailableItems();
	// Destructor
	// Open a file and record the machine information
	~Machine();
};

class MachineA : public Machine
{
protected:
	Coins change;
public:
	MachineA()
	{
		/*printf("This is machineA\n")*/;
	}
	virtual void machineAccepts();
	virtual bool acceptMoney(int index);
	bool makeChanges(int amount, Coins &machine, Coins &back);
	void printCoin(Coins c);
	virtual bool insertMoney(int money, int& totalInput);
	void completePurchase(int index, int purchase, int change_amount);
	bool transaction(int index, int totalInput, int purchase);
};

class MachineB : public MachineA
{
//private:
	
public:
	MachineB()
	{
		/*printf("This is machineB\n")*/;

	}
	virtual void machineAccepts();
	//virtual void acceptMoney() override;
	virtual bool insertMoney(int money, int& totalInput);
	virtual bool acceptMoney(int index);

};

class MachineC : public Machine
{
//private:
//	string cardEntered;
public:
	MachineC()
	{
		/*printf("This is machineC\n")*/;
	}
	//double calculateBalance(int totalCents);
	bool validateCreditCard(string n);
	virtual void machineAccepts();
	virtual bool acceptMoney(int index); /*override*/
	double calcBalance(Coins c, int dollars);
};

//class MachineD : public Machine
//{
//public:
//	virtual void machineAccepts();
//	virtual bool acceptMoney(int index);
//};

class MachineSystem
{
protected:
	Machine * pM[SIZE] = { 0 };
	int totalMachines = 0;

public:
	MachineSystem();
	void readFile();
	void purchase();
	int findMachine(string s);
	void printAllMachines();
	void printAvaliable();
	~MachineSystem();
};

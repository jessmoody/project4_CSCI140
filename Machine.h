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
			NICKEL = 5,
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
	double totalCost = 0;
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
	void setItem(string s, int n, Items OneProd);
	void setMachineName(string s1, int n);
	int totalCents(Coins c);	
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
	virtual void printMachine();
	void printAvailableItems();
	~Machine();
};

class MachineA : public Machine
{
protected:
	Coins change;
public:
	MachineA() { ; }
	virtual void machineAccepts();
	virtual bool acceptMoney(int index);
	bool makeChange(int amount, Coins &machine, Coins &back);
	void printCoin(Coins c);
	virtual bool insertMoney(int money, int& totalInput);
	void completePurchase(int index, int purchase, int change_amount);
	bool transaction(int index, int totalInput, int purchase);
	virtual void insufficientChange();

};

class MachineB : public MachineA
{
	Coins input;
public:
	MachineB() { ; }
	virtual void machineAccepts();
	virtual bool acceptMoney(int index);
	virtual bool insertMoney(int money, int& totalInput);
	virtual void insufficientChange();
};

class MachineC : public Machine
{

public:
	MachineC() { ; }
	bool validateCreditCard(string n);
	virtual void machineAccepts();
	virtual bool acceptMoney(int index); 
	double calcBalance(Coins c, int dollars);
};

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

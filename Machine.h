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

public:
	Machine();
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
	MachineA();
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
	MachineB();
	//bool makeChange(int amount, Coin &machine, Coin &back);
	//double calculateBalance(int totalCents);
	
};

class MachineC : public Machine
{
private:
	string cardEntered;
public:
	MachineC();
	//double calculateBalance(int totalCents);
	//bool validateCreditCard(string n);
	
};

class MachineSystem
{
protected:
	Machine * pM[SIZE];

public:
	MachineSystem()		
	{
		readFile();
	}
	void setNewObject(Machine m, int index);
	void readFile();
};
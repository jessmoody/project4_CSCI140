//outline of a potential class structure

#pragma once

#include <iostream>
#include <string>

using namespace std;

class Machine
{
protected:
	string model;
	int amountEntered;
	struct Coin
	{
		int quarters;
		int dimes;
		int nickels;
	};
	
	// will add more variables as needed

public:
	Machine();
	void setModel(string m);
	// These are just my functions from Project 1 - some are modified
	double calculateBalance(int totalCents);
	bool validation(string userInput);
	void print();
	void printInstructions(double balance);
	void printFinalReport(double balance, int totalCents);
	// functions added for Project 4
	int calculateTotalCents(Coin c);	// add up quarters, dimes and nickels
	void getInventory();		// not actually void
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
	bool makeChange(int amount, Coin &machine, Coin &back);
	double calculateBalance(int totalCents, Coin c);
	
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
	bool makeChange(int amount, Coin &machine, Coin &back);
	double calculateBalance(int totalCents);
	
};

class MachineC : public Machine
{
private:
	string cardEntered;
public:
	MachineC();
	double calculateBalance(int totalCents);
	bool validateCreditCard(string n);
	
};
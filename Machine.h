/*
5/30
Changed acceptMoney function
acceptMoney in MachineC is ready
Fixed the output by changing products.txt
5/29 
Destructor is ready, but the output is still a little bit off (see machineOutput.txt)
Had to change the acceptMoney function otherwise the program wouldn't compile... 
Working on the acceptMoney function in MachineC
*/

//outline of a potential class structure

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

	void setModel(string m)
	{
		model = m;
	}
	//void setNumMachines(int nm) { numMachines = nm; }

	// ONLY call this in initialization
	void setCoins(int q, int d, int n)
	{
		inputCoin.quarters = q;
		inputCoin.dimes = d;
		inputCoin.nickels = n;

		// *****Change 5/27*****
		currentCoin = inputCoin;
	}
	void setNumItems(int ni) { numItems = ni; }

	// ONLY call this in initialization
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

	// *****Change 5/27*****
	// Calculate the machine balance in dollars
	// Can calculate the initial and current balance
	// ***** Change 5/28: change it to virtual *****
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
	string getModel(){	return model;	}
	string getMachineName() { return machineName; }
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
		outM << "Initial balance: $"  << initialBalance /* << calcBalance(inputCoin, initialDollars)*/
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
	struct Coin
	{
		int quarters;
		int dimes;
		int nickels;
	};

public:
	MachineA()
	{
		/*printf("This is machineA\n")*/;
	}
	virtual void acceptMoney() override;
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
		/*printf("This is machineB\n")*/;

	}
	virtual void acceptMoney() override;
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
		/*printf("This is machineC\n")*/;

	}
	//double calculateBalance(int totalCents);
	bool validateCreditCard(string n)
	{
		int size = n.length();

		if (size > 19)	// Type cast to prevent overflow
		{
			return false;
		}

		// Sum of the even digits
		int digit;
		int sum = 0;    // sum of digits times two
		for (int i = 1; i < size; i += 2)
		{
			// Add even digits
			digit = n[size - 1 - i] - '0';
			if (digit < 5)    // 2 * 5 = 10, we add 1 + 0 instead of 10
			{
				sum += digit * 2;
			}
			else
			{
				int digitTwo = digit * 2;
				sum += digitTwo / 10 + digitTwo % 10;
			}
		}

		// Add odd digits
		for (int i = 0; i < size; i += 2)
		{
			digit = n[size - 1 - i] - '0';
			sum += n[size - 1 - i] - '0';
		}

		// Validate
		bool valid = (sum % 10 == 0) ? true : false;

		return valid;
	}

	virtual void acceptMoney(int index) /*override*/
	{
		// Validate credit card
		// Need to try different test cases:
		// 1 fail 1 success, 
		// 2 fails
		string card;
		bool valid;
		int attempt = 0;

		cout << "Enter your credit card number--> ";
		cin >> card;
		valid = validateCreditCard(card);
		attempt++;
		while (!valid)
		{
			cout << "Invalid credit card number was entered." << endl;

			if (attempt == 2)	// After 2 fails
			{
				cout << "Too many invalid attempts.  Your selectionis cancelled." << endl;
				return;
			}

			cout << "Enter your credit card number--> ";
			cin >> card;
			valid = validateCreditCard(card);
			attempt++;
		}

		double priceDollar = (double)items[index].price / 100;
		cout << "Your credit card was successfully charged for $" 
			<< priceDollar << "." << endl;

		// Change data in machine
		transactions++;
		items[index].currentQuantity--;
		totalCost += priceDollar;
		currentBalance += totalCost;

		cout << "Thank you! Please take your item." << endl;

	}

	virtual double calcBalance(Coins c, int dollars)
	{
		return totalCost;
	}
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

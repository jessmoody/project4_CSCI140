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
	string machineName;
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
		string selection, description;
		int itemID, quantity, price;
	};
	OneItem items[SIZE];

	struct OneProduct
	{
		string selection;
		Items OneInventory;
	};
	OneProduct ProductList[SIZE];

public:
	Machine();

	void setModel(string m)
	{
		model = m;
	}
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
		items[n].quantity = OneProd.quantity;
		items[n].description = OneProd.menu;
		items[n].price = OneProd.price;
		items[n].selection = s;
	}
	void setProduct(string selection, Items OneInventory, int n)
	{
		ProductList[n].selection = selection;
		ProductList[n].OneInventory = OneInventory;
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
				return i;
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
	virtual void printMachine();
	void printAvailableItems();
	
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
	void readFile();
	// function for user input in main - will be updated
	void purchase(string s)
	{
		int index;
		string userInput;
		index = findMachine(s);
		if (index != -1)
		{
			pM[index]->printAvailableItems();
			cout << "Select an item --> ";
			cin >> userInput;
			pM[index]->outputItemInfo(userInput);
		}
		else
		{
			cout << "Machine not found" << endl;
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
};

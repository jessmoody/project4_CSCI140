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
	OneItem items[SIZE];

public:
	Machine();
	void setModel(string m){ model = m; }
	
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
	string getModel() { return model; }
	//int getNumMachines() { return numMachines; }
	int getNumItems() { return numItems; }
	int getQuarters()
	{
		return inputCoin.quarters;
	}
	virtual void printMachine();

};

class MachineA : public Machine
{
private:

public:
	MachineA() { ; }	
};

class MachineB : public Machine
{
private:

public:
	MachineB() { ; }	
};

class MachineC : public Machine
{
private:
	string cardEntered;
public:
	MachineC() { ; }
	virtual void printMachine() override;
};

class MachineSystem
{
protected:

	Machine defaultMachine;
	Machine *pDefault;
	Machine * pM[SIZE] = { pDefault };
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
	void setTotalMachines(int n)	{ totalMachines = n; }
	int getTotalMachines() { return totalMachines; }
	void setPtr(Machine *arr[], int n)
	{
		for (int i = 0; i < n; i++)
		{
			pM[i] = arr[i];
		}
	}

};
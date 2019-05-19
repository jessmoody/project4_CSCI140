#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

const int ARR_SIZE = 8;

class MachineInput
{
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
	OneItem items[ARR_SIZE];

public:
	MachineInput(string m, int nm, Coins c, int ni, OneItem item[]):
		model(m), numMachines(nm), inputCoin(c), numItems(ni), items() {}
	void setModel(string m) {	model = m;	}
	void setNumMachines(int nm) { numMachines = nm; }
	void setCoins(Coins c) 
	{ 
		inputCoin.quarters = c.quarters;
		inputCoin.dimes = c.dimes;
		inputCoin.nickels = c.nickels;
	}
	void setNumItems(int ni) { numItems = ni; }
	void setItem(OneItem i, int n)
	{
		items[n].selection = i.selection;
		items[n].itemID = i.itemID;
		items[n].quantity = i.quantity;
	}


};


class TestMachines
{

	MachineInput allMachines;
	ifstream infile;


public:
	TestMachines(string model, int numMachines, Coins inputCoin, int numItems, OneItem items[]): // 
		allMachines(model, numMachines, inputCoin, numItems, items)
	{
		cout << "TestMachines constructor running" << endl;
	}
	void machineInput(string model, int numMachines, Coins inputCoin, int numItems, OneItem items[]);


};


void TestMachines::machineInput(string model, int numMachines, Coins inputCoin, int numItems, OneItem items[])
{
	infile.open("C:\\Users\\jessm\\Documents\\GitHub\\project4_CSCI140\\machines.txt", ios::in);

	Coins inputCoin;
	int index = 0;


	while (infile >> model)
	{
		infile >> numMachines;

		cout << "Model: " << model << endl << "Number of machines: " << numMachines << endl;

		for (int i = 0; i < numMachines; i++)
		{
			//create machine
			infile >> inputCoin.q >> inputCoin.d >> inputCoin.n;
			infile >> numItems;

			//cout << "Quarters: " << quarters << endl;
			//cout << "Dimes: " << dimes << endl;
			//cout << "Nickels: " << nickels << endl;
			//cout << endl;

			for (int i = 0; i < numItems; i++)
			{
				// create item object or struct

/*				infile >> selection >> itemID >> quantity;

				cout << "Selection: " << selection << endl;
				cout << "Item ID: " << itemID << endl;
				cout << "Quantity: " << quantity << endl << endl;
	*/		}

		}


	}

	infile.close();

}









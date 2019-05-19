#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

const int arrSize = 8;

class MachineInput
{
	string model;
	int numMachines;
	struct Coins
	{
		int dimes;
		int nickels;
	};
	int numItems;
	struct OneItem
	{
		string selection;
		int itemID, quantity;
	};

public:
	void setModel(string m);
	void setNumMachines(int nm);
	void setCoins(Coins c);
	void setNumItems(int ni);
	void setItem(OneItem item);


};


class TestMachines
{
protected:
	string model;
	int numMachines;
	struct Coins
	{
		int q;
		int d;
		int n;
	};
	int numItems;
	struct OneItem
	{
		string selection;
		int itemID, quantity;
	};

	MachineInput allMachines[arrSize];
	ifstream infile;
	OneItem items[arrSize];


public:
	TestMachines()
	{
		cout << "TestMachines constructor running" << endl;
	}
	void machineInput();


};


void TestMachines::machineInput()
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









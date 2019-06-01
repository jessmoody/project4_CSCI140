#include "Machine.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

void MachineA::machineAccepts()
{
	cout << "This machine accepts one-dollar bill only." << endl;
}

bool MachineA::acceptMoney(int index)
{

	int purchase, change_amount;

	purchase = items[index].price;
	bool valid;

	change_amount = (100 - purchase) / 100;

	cout << "Please insert a one-dollar bill. " << endl;
	cout << "Processing your purchase ..." << endl;
	cout << currentBalance << endl;
	if (currentBalance >= change_amount)
	{
		valid = makeChangesOfdollar(change_amount, currentCoin, change);
		cout << "Your change of " << change_amount << " cents is given as: " << endl;
		printCoin(change);
		/*count++;
		countDollar++;*/
		return true;
	}
	else
	{
		cout << "Insufficient changes! " << endl;
		cout << "Your transaction cannot be processed. " << endl;
		cout << "Please take back your dollar bill. " << endl;
	}
	return false;


}

bool MachineA::makeChangesOfdollar(int amount, Coins &machine, Coins &back)
{
	bool valid = true;
	int total1, total2;
	back.quarters = 0;
	back.dimes = 0;
	back.nickels = 0;
	if (machine.quarters > 0)
	{
		// Calculate the quarters

		// Calculate the dimes
		if (machine.dimes > 0 && machine.nickels > 0)
		{
			back.quarters = amount / 25;
			total1 = amount - (back.quarters * 25);
			back.dimes = total1 / 10;
			total2 = total1 - (back.dimes * 10);
			// Calculate the nickels
			back.nickels = total2 / 5;
			machine.dimes -= back.dimes;
			machine.nickels -= back.nickels;
			machine.quarters -= back.quarters;
		}
		else if (machine.dimes > 0 && machine.nickels <= 0)
		{
			back.dimes = (amount / 10) - 2;
			total1 = amount - (back.dimes * 10);
			back.quarters = total1 / 25;
			machine.dimes -= back.dimes;
			machine.quarters -= back.quarters;
		}
	}
	else
	{
		if (machine.dimes > 0)
		{
			// Calculate the dimes
			back.dimes = amount / 10;
			total1 = amount - (back.dimes * 10);
			// Calculate the nickels
			back.nickels = total1 / 5;
			machine.dimes -= back.dimes;
			machine.nickels -= back.nickels;
		}
		else
		{
			if (machine.nickels > 0)
			{
				// Calculate the nickels
				back.nickels = amount / 5;
				machine.nickels -= back.nickels;
			}
			else
			{
				cout << "We run out the quarters, dimes, and nickels." << endl;
			}
		}

	}
	return valid;
}
void MachineA::printCoin(Coins c)
{
	cout << "    Quarters:   " << c.quarters << endl;
	cout << "    Dimes:      " << c.dimes << endl;
	cout << "    Nickels:    " << c.nickels << endl << endl;
}

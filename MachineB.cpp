#include "Inventory.h"
#include "Machine.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

void MachineB::machineAccepts()
{
	cout << "This machine accepts coins or one-dollar bills." << endl;
}

bool MachineB::acceptMoney(int index) /*override*/
{

	int purchase, change_amount, numberD;
	purchase = items[index].price;
	bool valid;
	int totalCoins = 0;		//so that it does not add an invalid coin to totalCoins
	int coins,
		q = 0,
		d = 0,
		n = 0;
	cout << "Please insert your coins: ";
	cin >> coins;
	if (coins == 0)
	{
		cout << "You choose to cancel your selection. \n";
		return false;
	}
	while (coins != 0)
	{
		if (coins % 5 == 0)
		{
			if (coins % 25 == 0)
			{
				q++;
			}
			else if (coins % 10 == 0)
			{
				d++;
			}
			else if (coins % 5 == 0)
			{
				n++;
			}
			totalCoins += coins;
		}
		cin >> coins;
	}

	cout << q << ", " << d << ", " << n << ", \n";
	cout << "You inserted an amount of " << totalCoins << " cents. \n";
	cout << "Processing your purchase ..." << endl;
	change_amount = totalCoins - purchase;
	cout << currentBalance << endl;
	cout << change_amount << endl;
	if (currentBalance >= (static_cast<double>(change_amount) / 100))
	{
		if (change_amount > 0)
		{
			valid = makeChangesOfCoins(change_amount, q, d, n, currentCoin, change);
			cout << "Your change of " << change_amount << " cents is given as: " << endl;
			printCoin(change);
			transactions++;
			items[index].currentQuantity--;
			totalCost += (static_cast<double>(purchase) / 100);
			currentBalance = currentBalance - (static_cast<double>(change_amount) / 100);
			cout << currentBalance << endl;
		}
		else
		{
			cout << "Insufficient changes! " << endl;
			cout << "Your transaction cannot be processed. " << endl;
			cout << "Please take back your coins. " << endl;
		}
		return true;
	}
	else

	{
		cout << "Insufficient changes! " << endl;
		cout << "Your transaction cannot be processed. " << endl;
		cout << "Please take back your dollar bill. " << endl;
		return false;
	}
}

bool MachineB::makeChangesOfCoins(int amount, int q, int d, int n, Coins &machine, Coins &back)
{
	bool valid = true;
	int total1, total2;
	back.quarters = 0;
	back.dimes = 0;
	back.nickels = 0;
	machine.quarters += q;
	machine.dimes += d;
	machine.nickels += n;
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
void MachineB::printCoin(Coins c)
{
	cout << "    Quarters:   " << c.quarters << endl;
	cout << "    Dimes:      " << c.dimes << endl;
	cout << "    Nickels:    " << c.nickels << endl << endl;
}
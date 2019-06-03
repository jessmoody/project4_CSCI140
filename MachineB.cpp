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

bool MachineB::acceptCoins(int index)
{
	int purchase, change_amount, numberD;
	purchase = items[index].price;
	bool valid;
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
	int totalCoins = 0;
	while (coins != 0)
	{
		if (coins == 25)
		{
			q++;
			totalCoins += coins;
		}
		else if (coins == 10)
		{
			d++;
			totalCoins += coins;
		}
		else if (coins == 5)
		{
			n++;
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
	if (totalCents(currentCoin) >= change_amount)
	{
		valid = makeChanges(change_amount, currentCoin, change);
		if (valid)
		{
			// Update data in machine
			transactions++;
			items[index].currentQuantity--;
			currentCoin.quarters -= change.quarters;
			currentCoin.dimes -= change.dimes;
			currentCoin.nickels -= change.nickels;
			//currentDollars += totalInput / 100;
			double priceItems = (static_cast<double>(purchase) / 100);// total price of items being purchased
			totalCost += priceItems;
			currentBalance += priceItems;

			// Output
			cout << "Your change of " << change_amount << " cents is given as: " << endl;
			printCoin(change);
			return true;
		}


		cout << "Insufficient changes! " << endl;
		cout << "Your transaction cannot be processed. " << endl;
		cout << "Please take back your coins. " << endl;
		return false;
	}
}

bool MachineB::acceptMoney(int index)
{
	int option;
	cout << "Select an option (1- dollar bill and 2 - coins) --> ";
	cin >> option;
	if (option == 1)
	{
		return MachineA::acceptMoney(index);
	}
	else if (option == 2)
	{
		return acceptCoins(index);
	}
	else
	{
		cout << "This option is not support in this machine . \n";
		return false;
	}
}

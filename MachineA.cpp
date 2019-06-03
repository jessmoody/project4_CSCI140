#include "Machine.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>

using namespace std;

void MachineA::machineAccepts()
{
	cout << "This machine accepts one-dollar bill only." << endl;
}

bool MachineA::acceptMoney(int index)
{
	int purchase, change_amount, numberD;
	int totalInput;
	purchase = items[index].price;
	bool valid;
	cout << "Please insert your money --> ";
	cin >> numberD;
	if (numberD == 0)
	{
		cout << "You choose to cancel your selection. \n";
		return false;
	}
	totalInput = numberD;
	while (numberD != 0)
	{
		cin >> numberD;
		totalInput += numberD;
	}
	if (totalInput < purchase)
	{
		cout << "Insufficient amount! " << endl;
		cout << "Your transaction cannot be processed. " << endl;
		cout << "Please take back your dollar bill. " << endl;
		return false;
	}
	change_amount = totalInput - purchase;
	cout << "Processing your purchase ..." << endl;
	cout << currentBalance << endl;
	cout << change_amount << endl;

	if (totalCents(currentCoin) >= change_amount)
	{
		valid = makeChange(change_amount, currentCoin, change);
		if (valid)
		{
			// Update data in machine
			transactions++;
			items[index].currentQuantity--;
			currentCoin.quarters -= change.quarters;
			currentCoin.dimes -= change.dimes;
			currentCoin.nickels -= change.nickels;
			currentDollars += totalInput / DOLLAR;			
			double priceDollar = (static_cast<double>(purchase) / DOLLAR);
			totalCost += priceDollar;
			currentBalance += priceDollar;

			// Output
			cout << "Your change of " << change_amount << " cents is given as: " << endl;
			printCoin(change);
			return true;
		}
	}

	cout << "Insufficient change! " << endl;
	cout << "Your transaction cannot be processed. " << endl;
	cout << "Please take back your dollar bill. " << endl;
	return false;

}

bool MachineA::makeChange(int amount, Coins &machine, Coins &back)
{
	int total1;
	back.quarters = 0;
	back.dimes = 0;
	back.nickels = 0;

	// Calculate quarters, dimes, and nickles
	total1 = amount;
	back.quarters = min(total1 / QUARTER, machine.quarters);
	total1 -= back.quarters * QUARTER;
	back.dimes = min(total1 / DIME, machine.dimes);
	total1 -= back.dimes * DIME;
	back.nickels = min(total1 / NICKEL, machine.nickels);
	total1 -= back.nickels * NICKEL;

	if (total1 == 0)
	{
		return true;
	}
	else
	{
		// Try different solutions
		while (total1 != 0 && back.quarters > 0)
		{
			back.quarters--;
			total1 += QUARTER;
			back.dimes = min(total1 / DIME, machine.dimes);
			total1 -= back.dimes * DIME;
			back.nickels = min(total1 / NICKEL, machine.nickels);
			total1 -= back.nickels;
		}
		if (total1 == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

void MachineA::printCoin(Coins c)
{
	cout << "    Quarters:   " << c.quarters << endl;
	cout << "    Dimes:      " << c.dimes << endl;
	cout << "    Nickels:    " << c.nickels << endl << endl;
}

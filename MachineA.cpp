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
	int purchase, money = 0;
	int totalInput = 0;
	purchase = items[index].price;

	if (!insertMoney(money, totalInput))
	{
		return false;
	}

	return (transaction(index, totalInput, purchase));

}

bool MachineA::insertMoney(int numberD, int& totalInput)
{
	cout << "Insert your money --> ";
	cin >> numberD;
	if (numberD == 0)
	{
		cout << "You choose to cancel your selection. \n";
		return false;
	}
	while (numberD != 0)
	{
		if (numberD == DOLLAR)
		{
			totalInput += numberD;
		}
		cin >> numberD;
	}

	return true;
}

bool MachineA::transaction(int index, int totalInput, int purchase)
{
	bool valid;
	int change_amount;
	if (totalInput < purchase)
	{
		cout << "Insufficient amount! " << endl;
		cout << "Your transaction cannot be processed. " << endl;
		cout << "Please take back your dollar bill. " << endl;
		return false;
	}
	cout << "You entered an amount of " << totalInput << " cents." << endl;
	change_amount = totalInput - purchase;
	cout << "Processing your purchase ..." << endl;

	if (totalCents(currentCoin) >= change_amount)
	{
		valid = makeChange(change_amount, currentCoin, change);
		if (valid)
		{
			completePurchase(index, purchase, change_amount);
			//
			currentDollars += totalInput / DOLLAR;
			return true;
		}
	}
	
	insufficientChange();
	return false;

}

void MachineA::insufficientChange()
{
	cout << "Insufficient changes! " << endl;
	cout << "Your transaction cannot be processed. " << endl;
	cout << "Please take back your dollar bill. " << endl;
}

void MachineA::completePurchase(int index, int purchase, int change_amount)
{
	// Update data in machine
	transactions++;
	items[index].currentQuantity--;
	currentCoin.quarters -= change.quarters;
	currentCoin.dimes -= change.dimes;
	currentCoin.nickels -= change.nickels;
	double priceItems = (static_cast<double>(purchase) / DOLLAR);// total price of items being purchased
	totalCost += priceItems;
	currentBalance += priceItems;

	// Output
	cout << "Your change of " << change_amount << " cents is given as: " << endl;
	printCoin(change);
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
	cout << "    quarter(s):   " << c.quarters << endl;
	cout << "    dime(s):      " << c.dimes << endl;
	cout << "    nickel(s):    " << c.nickels << endl;
}

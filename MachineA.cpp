#include "Machine.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>

using namespace std;


//int MachineA::totalCoins()
//{
//	return currentCoin.quarters * 25 + currentCoin.dimes * 10 + currentCoin.nickels * 5;
//}

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
	cout << "Please insert your money ---> " << endl;
	cin >> numberD;
	if (numberD == 0)
	{
		cout << "You choose to cancle your selection. \n";
		return false;
	}
	totalInput = numberD;
	while (numberD != 0)
	{
		cin >> numberD;
		totalInput += numberD;
	}

	change_amount = totalInput - purchase;
	cout << "Processing your purchase ..." << endl;
	cout << currentBalance << endl;
	cout << change_amount << endl;

	if (totalCoins(currentCoin) >= change_amount)
	{
		valid = makeChangesOfdollar(change_amount, currentCoin, change);
		if (valid)
		{
			// Update data in machine
			transactions++;
			items[index].currentQuantity--;
			currentCoin.quarters -= change.quarters;
			currentCoin.dimes -= change.dimes;
			currentCoin.nickels -= change.nickels;
			currentDollars += totalInput / 100;			
			double priceDollar = (static_cast<double>(purchase) / 100);
			totalCost += priceDollar;
			currentBalance += priceDollar;

			// Output
			cout << "Your change of " << change_amount << " cents is given as: " << endl;
			printCoin(change);
			return true;
		}
	}
	//if (currentBalance >= (static_cast<double>(change_amount) / 100))
	//{
	//	valid = makeChangesOfdollar(change_amount, currentCoin, change);
	//	cout << "Your change of " << change_amount << " cents is given as: " << endl;
	//	printCoin(change);
	//	transactions++;
	//	items[index].currentQuantity--;
	//	currentDollars += totalInput / 100;
	//	totalCost += (static_cast<double>(purchase) / 100);
	//	currentBalance = currentBalance - (static_cast<double>(change_amount) / 100);
	//	cout << currentBalance << endl;
	//	/*count++;
	//	countDollar++;*/
	//	return true;
	//}

	cout << "Insufficient changes! " << endl;
	cout << "Your transaction cannot be processed. " << endl;
	cout << "Please take back your dollar bill. " << endl;
	return false;

}

bool MachineA::makeChangesOfdollar(int amount, Coins &machine, Coins &back)
{
	//bool valid = true;
	int total1/*, total2*/;
	back.quarters = 0;
	back.dimes = 0;
	back.nickels = 0;

	// Calculate quarters, dimes, and nickles
	total1 = amount;
	back.quarters = min(total1 / 25, machine.quarters);
	total1 -= back.quarters * 25;
	back.dimes = min(total1 / 10, machine.dimes);
	total1 -= back.dimes * 10;
	back.nickels = min(total1 / 5, machine.nickels);
	total1 -= back.nickels;

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
			total1 += 25;
			back.dimes = min(total1 / 10, machine.dimes);
			total1 -= back.dimes * 10;
			back.nickels = min(total1 / 5, machine.nickels);
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

	//if (machine.quarters > 0)
	//{
	//	// Calculate the quarters

	//	// Calculate the dimes
	//	if (machine.dimes > 0 && machine.nickels > 0)
	//	{
	//		back.quarters = amount / 25;
	//		total1 = amount - (back.quarters * 25);
	//		back.dimes = total1 / 10;
	//		total2 = total1 - (back.dimes * 10);
	//		// Calculate the nickels
	//		back.nickels = total2 / 5;
	//		machine.dimes -= back.dimes;
	//		machine.nickels -= back.nickels;
	//		machine.quarters -= back.quarters;
	//	}
	//	else if (machine.dimes > 0 && machine.nickels <= 0)
	//	{
	//		back.dimes = (amount / 10) - 2;
	//		total1 = amount - (back.dimes * 10);
	//		back.quarters = total1 / 25;
	//		machine.dimes -= back.dimes;
	//		machine.quarters -= back.quarters;
	//	}
	//}
	//else
	//{
	//	if (machine.dimes > 0)
	//	{
	//		// Calculate the dimes
	//		back.dimes = amount / 10;
	//		total1 = amount - (back.dimes * 10);
	//		// Calculate the nickels
	//		back.nickels = total1 / 5;
	//		machine.dimes -= back.dimes;
	//		machine.nickels -= back.nickels;
	//	}
	//	else
	//	{
	//		if (machine.nickels > 0)
	//		{
	//			// Calculate the nickels
	//			back.nickels = amount / 5;
	//			machine.nickels -= back.nickels;
	//		}
	//		else
	//		{
	//			cout << "We run out the quarters, dimes, and nickels." << endl;
	//		}
	//	}

	//}
}

void MachineA::printCoin(Coins c)
{
	cout << "    Quarters:   " << c.quarters << endl;
	cout << "    Dimes:      " << c.dimes << endl;
	cout << "    Nickels:    " << c.nickels << endl << endl;
}

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
	int coins,
		q = 0,
		d = 0,
		n = 0;
	cout << "Please insert your coins: ";
	cin >> coins;
	if (coins == 0)
	{
		cout << "You choose to cancle your selection. \n";
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
	if (currentBalance >= (static_cast<double>(change_amount) / 100))
	{
		currentCoin.quarters += q;
		currentCoin.dimes += d;
		currentCoin.nickels += n;
		if (change_amount > 0)
		{

			valid = makeChangesOfdollar(change_amount, currentCoin, change);
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

//bool MachineB::makeChangesOfCoins(int amount, Coins &machine, Coins &back)
//{
//	bool valid = true;
//	int total1, total2;
//	back.quarters = 0;
//	back.dimes = 0;
//	back.nickels = 0;
//
//	if (machine.quarters > 0)
//	{
//		// Calculate the quarters
//		back.quarters = amount / 25;
//		if (machine.quarters - back.quarters >= 0)
//		{
//
//			total1 = amount - (back.quarters * 25);
//			// Calculate the dimes
//			if (machine.dimes > 0)
//			{
//				// Calculate the dimes
//				back.dimes = total1 / 100;
//				total1 = total1 - (back.dimes * 10);
//				// Calculate the nickels
//				back.nickels = total1 / 5;
//				machine.dimes -= back.dimes;
//				machine.nickels -= back.nickels;
//			}
//			else
//			{
//				if (machine.nickels > 0)
//				{
//					// Calculate the nickels
//					back.nickels = total1 / 5;
//					machine.nickels -= back.nickels;
//				}
//				else if (machine.nickels <= 0)
//				{
//					cout << "We run out nickels." << endl;
//				}
//			}
//
//		}
//		else // machine.quarters - back.quarters < 0
//		{
//			back.quarters = machine.quarters;
//			total1 = amount - (back.quarters * 25);
//			if (machine.dimes > 0)
//			{
//				// Calculate the dimes
//				back.dimes = total1 / 100;
//				total1 = total1 - (back.dimes * 10);
//				// Calculate the nickels
//				back.nickels = total1 / 5;
//				machine.dimes -= back.dimes;
//				machine.nickels -= back.nickels;
//			}
//			else
//			{
//				if (machine.nickels > 0)
//				{
//					// Calculate the nickels
//					back.nickels = total1 / 5;
//					machine.nickels -= back.nickels;
//				}
//				else
//				{
//					cout << "We run out the quarters, dimes, and nickels." << endl;
//				}
//			}
//		}
//
//	}
//	else // machine.quarter < 0
//	{
//		if (machine.dimes > 0)
//		{
//			// Calculate the dimes
//			back.dimes = amount / 10;
//			total1 = amount - (back.dimes * 10);
//			// Calculate the nickels
//			back.nickels = total1 / 5;
//			machine.dimes -= back.dimes;
//			machine.nickels -= back.nickels;
//		}
//		else
//		{
//			if (machine.nickels > 0)
//			{
//				// Calculate the nickels
//				back.nickels = amount / 5;
//				machine.nickels -= back.nickels;
//			}
//			else
//			{
//				cout << "We run out the quarters, dimes, and nickels." << endl;
//			}
//		}
//
//	}
//	return valid;
//}
//void MachineB::printCoin(Coins c)
//{
//	cout << "    Quarters:   " << c.quarters << endl;
//	cout << "    Dimes:      " << c.dimes << endl;
//	cout << "    Nickels:    " << c.nickels << endl << endl;
//}
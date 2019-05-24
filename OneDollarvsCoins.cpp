// ConsoleApplication49.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Coin
{
	int q, d, n;
};

bool makeChangesOfdollar(int amount, Coin &machine, Coin &back)
{
	bool valid = true;
	int total1, total2;
	back.q = 0;
	back.d = 0;
	back.n = 0;
	if (machine.q > 0)
	{
		// Calculate the quarters

		// Calculate the dimes
		if (machine.d > 0 && machine.n > 0)
		{
			back.q = amount / 25;
			total1 = amount - (back.q * 25);
			back.d = total1 / 10;
			total2 = total1 - (back.d * 10);
			// Calculate the nickels
			back.n = total2 / 5;
			machine.d -= back.d;
			machine.n -= back.n;
			machine.q -= back.q;
		}
		else if (machine.d > 0 && machine.n <= 0)
		{
			back.d = (amount / 10) - 2;
			total1 = amount - (back.d * 10);
			back.q = total1 / 25;
			machine.d -= back.d;
			machine.q -= back.q;
		}
	}
	else
	{
		if (machine.d > 0)
		{
			// Calculate the dimes
			back.d = amount / 10;
			total1 = amount - (back.d * 10);
			// Calculate the nickels
			back.n = total1 / 5;
			machine.d -= back.d;
			machine.n -= back.n;
		}
		else
		{
			if (machine.n > 0)
			{
				// Calculate the nickels
				back.n = amount / 5;
				machine.n -= back.n;
			}
			else
			{
				cout << "We run out the quarters, dimes, and nickels." << endl;
			}
		}

	}
	return valid;
}
bool makeChangesOfCoins(int amount, int q, int d, int n, Coin &machine, Coin &back)
{
	bool valid = true;
	int total1, total2;
	back.q = 0;
	back.d = 0;
	back.n = 0;
	machine.q += q;
	machine.d += d;
	machine.n += n;
	if (machine.q > 0)
	{
		// Calculate the quarters

		// Calculate the dimes
		if (machine.d > 0 && machine.n > 0)
		{
			back.q = amount / 25;
			total1 = amount - (back.q * 25);
			back.d = total1 / 10;
			total2 = total1 - (back.d * 10);
			// Calculate the nickels
			back.n = total2 / 5;
			machine.d -= back.d;
			machine.n -= back.n;
			machine.q -= back.q;
		}
		else if (machine.d > 0 && machine.n <= 0)
		{
			back.d = (amount / 10) - 2;
			total1 = amount - (back.d * 10);
			back.q = total1 / 25;
			machine.d -= back.d;
			machine.q -= back.q;
		}
	}
	else
	{
		if (machine.d > 0)
		{
			// Calculate the dimes
			back.d = amount / 10;
			total1 = amount - (back.d * 10);
			// Calculate the nickels
			back.n = total1 / 5;
			machine.d -= back.d;
			machine.n -= back.n;
		}
		else
		{
			if (machine.n > 0)
			{
				// Calculate the nickels
				back.n = amount / 5;
				machine.n -= back.n;
			}
			else
			{
				cout << "We run out the quarters, dimes, and nickels." << endl;
			}
		}

	}
	return valid;
}
void printCoin(Coin c)
{
	cout << "    Quarters:   " << c.q << endl;
	cout << "    Dimes:      " << c.d << endl;
	cout << "    Nickels:    " << c.n << endl << endl;
}

int main()
{
	Coin machine, change;
	bool valid;
	int change_amount;
	const double VALUE_OF_QUARTERS = 0.25;
	const double VALUE_OF_DIMES = 0.10;
	const double VALUE_OF_NICKELS = 0.05;
	int purchase, count = 0, countDollar = 0;
	
	cout << "Vending Machine Version 1 by Phuong Nguyen" << endl;
	cout << fixed << showpoint << setprecision(2) << endl;
	// Input the money into machine 
	cout << "Enter the number of quarters, dimes, and nickels --> ";

	cin >> machine.q >> machine.d >> machine.n;// machine.q = 2; machine.d = 4; machine.n = 4;
	cout << "There are: " << endl;
	printCoin(machine);

	// calculate initial balance and display the money of the machine
	double initial_balance = (VALUE_OF_QUARTERS * machine.q) + (VALUE_OF_DIMES * machine.d) + (VALUE_OF_NICKELS * machine.n);
	cout << "Initial machine balance is : $" << initial_balance << endl;
	cout << "Only one-dollar bill will be accepted." << endl;
	cout << "Only amount between between  to  and multiuple of 5 is accepted." << endl;
	cout << "Enter 0 to stop the program. " << endl;
	cout << "Machine is now ready. " << endl << endl;

	// The user input the price of the object
	cout << "Enter a purchase amount [0 - 100] --> ";
	cin >> purchase;
	while (purchase != 0)
	{
		cout << "You enter a purchase amount of " << purchase << " cents. " << endl;
		cout << "Select an option(1 - dollar bill and 2 - coins)-->";
		int options;
		cin >> options;
		if (options == 1)
		{
			if (purchase <= 100)
			{
				int division = purchase % 5;
				if (division == 0)
				{
					change_amount = 100 - purchase;
					initial_balance = initial_balance - static_cast<double>(change_amount) / 100.0;
					cout << "Please insert a one-dollar bill. " << endl;
					cout << "Processing your purchase ..." << endl;
					if (initial_balance > 0)
					{
						valid = makeChangesOfdollar(change_amount, machine, change);
						cout << "Your change of " << change_amount << " cents is given as: " << endl;
						printCoin(change);
						count++;
						countDollar++;
					}
					else
					{
						initial_balance = initial_balance + static_cast<double>(change_amount) / 100;
						cout << "Insufficient changes! " << endl;
						cout << "Your transaction cannot be processed. " << endl;
						cout << "Please take back your dollar bill. " << endl;
					}
				}
				else
				{
					cout << "Invalid amount (not a multiple 5). Try again." << endl;
				}
			}
			else
			{
				cout << "Invalid amount (outside valid range). Try again. " << endl;
			}
		}
		else if (options == 2)
		{
			int coins,
				q = 0,
				d = 0,
				n = 0;
			cout << "Please insert your coins: ";
			
			cin >> coins;
			int totalCoins = coins;
			while (coins != 0)
			{
				cin >> coins;
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
			cout << q << ", " << d << ", " << n << ", \n";
			cout << "You inserted an amount of " << totalCoins << " cents. \n";
			cout << "Processing your purchase ..." << endl;
			int division = purchase % 5;
			if (division == 0)
			{
				change_amount = totalCoins - purchase;
				initial_balance = initial_balance - static_cast<double>(change_amount) / 100.0;

				if (change_amount > 0)
				{
					valid = makeChangesOfCoins(change_amount, q, d, n, machine, change);
					cout << "Your change of " << change_amount << " cents is given as: " << endl;
					printCoin(change);
					count++;
				}
				else
				{

					cout << "Insufficient changes! " << endl;
					cout << "Your transaction cannot be processed. " << endl;
					cout << "Please take back your coins. " << endl;
				}
			}
			else
			{
				cout << "Invalid amount (not a multiple 5). Try again." << endl;
			}
		}
		cout << endl;
		cout << "Enter a purchase amount [0 - 100] --> ";
		cin >> purchase;
	}
	// when the user input 0 
	cout << "Final report is being generated ... " << endl;
	cout << "There are " << count << " transactions. " << endl;
	cout << "Number of dollars : " << countDollar << endl;
	cout << "Number of quarters: " << machine.q << endl;
	cout << "Number of dimes   : " << machine.d << endl;
	cout << "Number of nickels : " << machine.n << endl;
	double final_balance = countDollar + (machine.q* VALUE_OF_QUARTERS) + (machine.d* VALUE_OF_DIMES) + (machine.n * VALUE_OF_NICKELS);
	cout << "Machine balance   : $" << final_balance << endl;
	cout << "Machine is shutting down. " << endl;

	system("pause");
	return 0;
}

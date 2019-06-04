#include "Machine.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

void MachineD::machineAccepts()
{
	cout << "This machine accepts coins, one-dollar bills, or credit card." << endl;
}

bool MachineD::acceptMoney(int index)
{
	int option;
	cout << "Select an option (1 - dollar bill, 2 - coins, and 3 - credit card) --> ";
	cin >> option;

	int purchase, money = 0;
	int totalInput = 0;
	purchase = items[index].price;

	if (option == 1)
	{
		if (!MachineA::insertMoney(money, totalInput))
		{
			return false;
		}
		return (MachineA::transaction(index, totalInput, purchase));
	}
	else if (option == 2)
	{
		if (!MachineB::insertMoney(money, totalInput))
		{
			return false;
		}
		return (MachineB::transaction(index, totalInput, purchase));
	}
	else if (option == 3)
	{
		string card;
		bool valid;
		int attempt = 0;

		cout << "Enter your credit card number--> ";
		cin >> card;
		valid = validateCreditCard(card);
		attempt++;
		while (!valid)
		{
			cout << "Invalid credit card number was entered." << endl;

			if (attempt == 2)	// After 2 fails
			{
				cout << "Too many invalid attempts.  Your selectionis cancelled." << endl;
				return false;
			}

			cout << "Enter your credit card number--> ";
			cin >> card;
			valid = validateCreditCard(card);
			attempt++;
		}

		double priceDollar = (double)items[index].price / DOLLAR;
		cout << "Your credit card was successfully charged for $"
			<< priceDollar << "." << endl;

		// Change data in machine
		transactions++;
		items[index].currentQuantity--;
		totalCost += priceDollar;
		currentBalance += priceDollar;

		return true;
	}
	else
	{
		cout << "This option is not support in this machine . \n";
		return false;
	}
}

bool MachineD::validateCreditCard(string n)
{
	int size = n.length();

	if (size > 19)
	{
		return false;
	}

	// Sum of the even digits
	int digit;
	int sum = 0;    // sum of digits times two
	for (int i = 1; i < size; i += 2)
	{
		// Add even digits
		digit = n[size - 1 - i] - '0';
		if (digit < 5)    // 2 * 5 = 10, we add 1 + 0 instead of 10
		{
			sum += digit * 2;
		}
		else
		{
			int digitTwo = digit * 2;
			sum += digitTwo / 10 + digitTwo % 10;
		}
	}

	// Add odd digits
	for (int i = 0; i < size; i += 2)
	{
		digit = n[size - 1 - i] - '0';
		sum += n[size - 1 - i] - '0';
	}

	// Validate
	bool valid = (sum % 10 == 0) ? true : false;

	return valid;
}


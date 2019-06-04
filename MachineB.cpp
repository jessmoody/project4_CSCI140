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


bool MachineB::acceptMoney(int index)
{
	int option;
	cout << "Select an option (1 - dollar bill and 2 - coins) --> ";
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
		if (!insertMoney(money, totalInput))
		{
			return false;
		}
		return (transaction(index, totalInput, purchase));
	}
	else
	{
		cout << "This option is not support in this machine . \n";
		return false;
	}
}

bool MachineB::insertMoney(int coins, int& totalCoins)
{
	input.quarters = 0,
	input.dimes = 0,
	input.nickels = 0;
	cout << "Please insert your coins: ";
	cin >> coins;
	if (coins == 0)
	{
		cout << "You choose to cancel your selection. \n";
		return false;
	}
	while (coins != 0)
	{
		if (coins == 25)
		{
			input.quarters++;
			//currentCoin.quarters += input.quarters;
			currentCoin.quarters++;
			totalCoins += coins;
		}
		else if (coins == 10)
		{
			input.dimes++;
			//currentCoin.dimes += input.dimes;
			currentCoin.dimes++;
			totalCoins += coins;
		}
		else if (coins == 5)
		{
			input.nickels++;
			//currentCoin.nickels += input.nickels;
			currentCoin.nickels++;
			totalCoins += coins;
		}
		cin >> coins;
	}

	return true;
}

void MachineB::insufficientChange()
{
	cout << "Insufficient changes! " << endl;
	cout << "Your transaction cannot be processed. " << endl;
	cout << "Please take back your dollar bill. " << endl;
	currentCoin.quarters -= input.quarters;
	currentCoin.dimes -= input.dimes;
	currentCoin.nickels -= input.nickels;
}

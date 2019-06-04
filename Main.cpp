#include "Machine.h"
#include "Inventory.h"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main(void)
{
	cout << "Vending Machine by Jessica Moody, Phuong Nguyen, and Aiqi You\n" << endl;

	cout << fixed << setprecision(2);

	string code;
	do
	{
		cout << "Please enter a startup code--> ";
		cin >> code;
	} while (code != SECRET_CODE);

	MachineSystem System;

	System.printAvaliable();
	cout << endl;

	System.purchase();
}
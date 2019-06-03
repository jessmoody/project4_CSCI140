#include "Machine.h"
#include "Inventory.h"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main(void)
{
	// Print program infomation
	cout << "Vending Machine by Jessica Moody, Phuong Nguyen, and Aiqi You\n" << endl;

	cout << fixed << setprecision(2);

	// Initialization
	string code;
	do
	{
		cout << "Please enter a startup code--> ";
		cin >> code;
	} while (code != "spring19");

	MachineSystem System;

	// Print Avaliable Machines
	// Note: currently machine 100D1 is not avaliable, but we are still printing it
	System.printAvaliable();
	cout << endl;
	// Running the machine
	System.purchase();
}
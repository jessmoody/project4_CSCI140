#include "Machine.h"
#include "Inventory.h"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

void MachineSystem::printAvaliable()
{
	cout << "Available machines: ";
	// Print the machines with two steps to deal with commas 
	// Print the first machine
	cout << pM[0]->getMachineName();
	// Print the rest
	for (int i = 0; i < totalMachines; i++)
	{
		cout << ", " << pM[i]->getMachineName();
	}
	cout << endl;
}

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

	// Maybe we can put the two cout message in the constructor of the machine system? 
	cout << "Initialize machines. Please wait..." << endl;
	MachineSystem System;
	cout << "Machines are ready." << endl;

	// Print Avaliable Machines
	// Note: currently machine 100D1 is not avaliable, but we are still printing it
	System.printAvaliable();
	cout << endl;
	// Running the machine
	System.purchase();
}
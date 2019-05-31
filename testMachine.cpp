#include "Machine.h"
#include "Inventory.h"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main(void)
{

	//cout <<

	MachineSystem TestSystem;
	string code2 = "", machineSelection;

	//cout << "------------------------------------"
	//	<< "       Printing all machines        "
	//	<< "-------------------------------------" << endl;
	//TestSystem.printAllMachines();

	cout << "Initialize machines. Please wait ... " << endl
		<< "Machines are ready." << endl
		<< "Available machines: 100A1, 100A2, 100B1, 100C1, 100C2 \n" << endl;

	cout << "Selectamachine--> ";
	cin >> machineSelection;

	TestSystem.purchase(machineSelection);

	// Test printInventory in machine class
	TestSystem.printMInv();
	return 0;

	while (code2 != "0")
	{
		cout << "Select a machine: ";
		cin >> code2;
		cout << "This machine accepts..." << endl;
		TestSystem.purchase(code2);
	}
	


	
	//TestSystem.printAllAvailableItems();
}
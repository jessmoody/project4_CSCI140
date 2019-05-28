#include "Machine.h"
#include "Inventory.h"
#include <iostream>

using namespace std;

int main(void)
{

	MachineSystem TestSystem;
	string code2 = "";

	//cout << "------------------------------------"
	//	<< "       Printing all machines        "
	//	<< "-------------------------------------" << endl;
	//TestSystem.printAllMachines();

	cout << "Initialize machines. Please wait ... " << endl
		<< "Machines are ready." << endl
		<< "Available machines: 100A1, 100A2, 100B1, 100C1, 100C2 \n" << endl;
	while (code2 != "0")
	{
		cout << "Select a machine: ";
		cin >> code2;
		cout << "This machine accepts..." << endl;
		TestSystem.purchase(code2);
	}
	


	
	//TestSystem.printAllAvailableItems();
}
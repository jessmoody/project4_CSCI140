#include "Machine.h"
#include "Inventory.h"
#include <iostream>

using namespace std;

int main(void)
{

	MachineSystem TestSystem;

	cout << "------------------------------------"
		<< "       Printing all machines        "
		<< "-------------------------------------" << endl;
	TestSystem.printAllMachines();
	TestSystem.printAllAvailableItems();
}
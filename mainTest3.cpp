#include "Machine.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	//example of how this might work

	MachineSystem m;

	Machine defaultMachine;
	MachineA a;
	MachineB b;
	MachineC c;

	cout << "MachineSystem object created." << endl;

	Machine mach[SIZE] = { a, a, b, c, c, defaultMachine };
	m.readFile(mach);

	for (int i = 0; i < m.getTotalMachines(); i++)
	{
		mach[i].printMachine();
	}

	cout << "-------Printing Machines-------" << endl;

	m.printAllMachines();

	return 0;
}
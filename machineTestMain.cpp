#include "Machine.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	//example of how this might work

	MachineSystem m;

	//Machine *one;
	Machine defaultMachine;
	Machine *pDefault = &defaultMachine;
	MachineA a;
	MachineA *pA = &a;
	MachineB b;
	MachineB *pB = &b;
	MachineC c;
	MachineC *pC = &c;

	cout << "MachineSystem object created." << endl;

	Machine *mach[SIZE] = { pA, pA, pB, pC, pC, pDefault };

	m.readFile(mach);

	cout << "Machine ptr created." << endl;

	m.printAllMachines();

	return 0;
}
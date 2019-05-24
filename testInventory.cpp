/*
Aiqi You
5/23/19
test drive for InventoryList class
*/

// Current status: all function for InventoryList class in in InventoryList.h
// TODO: make an InventoryList.cpp to store the functions


#include "Inventory.h"
#include <iostream>
#include <fstream>

using namespace std;

void printItems(Items test);

int main(void)
{
	Inventory testInv;
	testInv.loadData();
	testInv.printInventory();

	ifstream inTest("testLoad.txt");
	if (!inTest)
		return 1;

	string code;
	int id, num,
		i = 0;
	
	printf("\nNow checking out\n");

	while (inTest >> code >> id >> num)
	{
		i++;
		Items req = testInv.checkOut(id, num);
		printItems(req);
	}

	inTest.close();

	printf("Number of inventory checked out: %i\n", i);
	printf("\nPrinting InventoryList: \n");
	testInv.printInventory();
}

void printItems(Items test)
{
	printf("%i %i %i %s\n", test.id, test.quantity,
		test.price, test.menu.c_str());
}
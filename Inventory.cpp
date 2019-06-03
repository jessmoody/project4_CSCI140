#include "Inventory.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

void Inventory::loadData()
{
	// Open "products.txt" 
	ifstream inProducts("products.txt");
	if (!inProducts)
	{
		cout << "Error in reading products.txt" << endl;
		exit(1);
	}

	int i = 0;

	// Load data into InventoryList array
	inProducts >> InventoryList[i].id >> InventoryList[i].quantity >> InventoryList[i].price;
	while (!inProducts.eof())
	{
		inProducts.ignore();
		getline(inProducts, InventoryList[i].menu);
		i++;
		inProducts >> InventoryList[i].id >> InventoryList[i].quantity >> InventoryList[i].price;
	}

	numItem = i;

	inProducts.close();
}

void Inventory::printInventory() const
{
	cout << "Number of item: " << numItem << endl;
	for (int j = 0; j < numItem; j++)
	{
		// TODO: change printf to cout
		printf("%i %i %i %s\n", InventoryList[j].id, InventoryList[j].quantity,
			InventoryList[j].price, InventoryList[j].menu.c_str());
	}
}

Items Inventory::checkOut(int idReq, int quanReq)
{
	// Search for the item
	Items *find = NULL;
	int i = 0;
	while (!find && i < numItem)
	{
		if (InventoryList[i].id == idReq)
		{
			find = &InventoryList[i];
		}
		i++;
	}

	// When the requested item does not exist
	// Rarely happen, unless the machine file is messed up
	if (!find)
	{
		cout << "Error: Item not found" << endl;
		exit(404);
	}

	Items out = { find->id,0,find->price,find->menu };


	// Requested quantity is less than stored value
	if (quanReq <= find->quantity)
	{
		out.quantity = quanReq;
		find->quantity -= quanReq;
	}
	// Requested quantity is more than stored value, grap all items that is avaliable
	else
	{
		out.quantity = find->quantity;
		find->quantity = 0;
	}
	return out;
}


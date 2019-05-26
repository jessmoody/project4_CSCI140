/*
Aiqi You
5/23/19
Header file for the InventoryList class
*/

#ifndef INVENTORY_H
#define INVENTORY_H

//#include "pch.h"
#include <string>

using namespace std;

const int NUMOFPROD = 23;   // This holds the number of products a store sells

// A struct that holds one product's information:
// ID, quantity, price, and name
struct Items
{
	int id, quantity, price;
	string menu;
};

class Inventory
{
private:

	int numItem = 0;
	Items InventoryList[NUMOFPROD];

public:
	// Constructor
	Inventory()
	{
		loadData();
	}
	// Load the dada in "products.txt" and set up the InventoryList
	void loadData();
	
	// Print out InventoryList array
	void printInventory() const;

	// Accept item request
	// from the machines
	Items checkOut(int idReq, int quanReq);

	//void setId(int code)
	//{
	//	for (int i = 0; i < NUMOFPROD; i++)
	//	{
	//		InventoryList[i].id = code;
	//	}
	//}
	//void setAmount(int q)
	//{
	//	for (int i = 0; i < NUMOFPROD; i++)
	//	{
	//		InventoryList[i].quantity = q;
	//	}
	//}
	//void setPrice(int price)
	//{
	//	for (int i = 0; i < NUMOFPROD; i++)
	//	{
	//		InventoryList[i].price = price;
	//	}
	//}
	//void setName(string name)
	//{
	//	for (int i = 0; i < NUMOFPROD; i++)
	//	{
	//		InventoryList[i].menu = name;
	//	}
	//}
	//void display() const
	//{
	//	for (int i = 0; i < 23; i++)
	//		cout << InventoryList[i].id << InventoryList[i].quantity << InventoryList[i].price << InventoryList[i].menu << endl;
	//}
};


#endif
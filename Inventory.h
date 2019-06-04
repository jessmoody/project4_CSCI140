#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>

using namespace std;

const int NUMOFPROD = 23;   
const string SECRET_CODE = "spring19";

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
	Inventory()
	{
		loadData();
	}
	void loadData();
	void printInventory() const;
	Items checkOut(int idReq, int quanReq);

};


#endif
// ConsoleApplication43.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;


// This program defines a class called Inventory that has itemnumber (which 
// contains the id number of a product) and numofitem (which contains the 
// quantity on hand of the corresponding product)as private data members.
// The program will read these values from a file and store them in an 
// array of objects (of type Inventory).  It will then print these values
// to the screen.

// Example: Given the following data file:
//     986 8
//     432 24
// This program reads these values into an array of objects and prints the
// following:
//     Item number 986 has 8 items in stock
//     Item number 432 has 24 items in stock


const int NUMOFPROD = 23;   // This holds the number of products a store sells
struct Items
{
	int id, quantity, price;
	string menu;
};
class Inventory
{
private:
	Items inventory[NUMOFPROD];
public:
	void setInventory(int code, int q, int price, string name, int pos)
	{
		
			inventory[pos].id = code;
			inventory[pos].quantity = q;
			inventory[pos].price = price;
			inventory[pos].menu = name;
		
	}
	void display() const
	{
		for (int i = 0; i < 23; i++)
		{
			cout << inventory[i].id << inventory[i].quantity << inventory[i].price << inventory[i].menu << endl;
		}
	}
};


int main()
{

	ifstream infile;	      // Input file to read values into array
	infile.open("D:\\CSCI 140\\Project 4\\products.txt");
	if (!infile)
	{
		cout << "Error opening data file." << endl;
	}
	else
	{
		Inventory products;
		int pos = 0;                   // loop counter
		int id;                    // variable holding the id number
		int q;
		int price;
		string name;// variable holding the total for each id number
		while (pos < NUMOFPROD)
		{
			infile >> id >> q >> price;
			getline(infile, name);
			products.setInventory(id,q,price,name, pos);
			pos++;
		}
		
		//products[NUMOFPROD].display();
		products.display();


	}
	infile.close();
	system("pause");
	return 0;

}

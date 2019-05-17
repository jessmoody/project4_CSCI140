
#include "pch.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
const double VALUE_OF_QUARTERS = 0.25;
const double VALUE_OF_DIMES = 0.10;
const double VALUE_OF_NICKELS = 0.05;

class Machine
{
private:
	int q, d, n, dollar;
	double initial_balance, current_balance;
public:
	Machine(int quaters = 0, int dimes = 0, int nickel = 0, int dollars = 0)
	{
		q = quaters;
		d = dimes;
		n = nickel;
		dollar = dollars;
		initial_balance = (VALUE_OF_QUARTERS * q) + (VALUE_OF_DIMES * d) + (VALUE_OF_NICKELS * n);
	}
	void print() const
	{
		cout << "Initial balance: " << initial_balance << "(" << dollar << " $, " << q << " Q, " << d << " D, " << n << " N)" << endl;
	}
};
class A1 : public Machine
{
private:
	int id[5] = { 1034,1000,1100,1123,1222 };
	string code[5] = { "1A","1B","1C","1D","1E" };
	string Decription[5]{ "Candy Bar", "Chocolate Chips", "Cookies", "Brownie", "Protein Bar" };
	int quantities[5] = { 5,10,1,20,5 };
public:
	/*A1(int id1[], int code1[], string Nitem[], int quantity [])
	{
		for (int i = 0; i < 5; i++)
		{
			id[i] = id1[i];
			code[i] = code1[i];
			Decription[i] = Nitem[i];
			quantities[i] = quantity[i];
		}
	}*/
	void subtract(string id)
	{
		int position;
		for (int i = 0; i < 5; i++)
		{
			if (code[i] == id)
			{
				position = i;
			}

		}
		quantities[position]--;
	}
	void print() const
	{
		cout << "Code" << setw(8) << "Id" << setw(8) << "Description" << setw(8) << "Initial" << endl;
		for (int i = 0; i < 5; i++)
		{
			cout << code[i] << setw(8) << id[i] << setw(8) << Decription[i] << setw(8) << quantities[i] << endl;
		}
	}
};
int main()
{
	cout << "Vending Machine System II" << endl;
	Machine A1(2,4,4);
	A1.print();
	string code1, code2;
	cout << "Please enter a startup code: ";
	cin >> code1;
	cout << "Initialzie machines. Please wait ... " << endl
		<< "Machines are ready." << endl
		<< "Available machines: 100A1, 100A2, 100B1, 100C1, 100C2 \n" << endl;
	cout << "Select a machine: ";
	cin >> code2;
	while (code2 != code1)
	{
		if (code2 == "100A1")
		{
			cout << "This machine accept one dollar bill only. \n"
				<< "Available Items: \n"
				<< "1A  50   Candy Bar \n"
				<< "1B  35   Chocolate chips \n"
				<< "1C  75   Cookies \n"
				<< "1D  60   Brownie \n"
				<< "1E  165  Protein Bar \n"
				<< "Select an item: \n";
			string select;
			cin >> select;
			


			
		}
		cout << "Select a machine: ";
		cin >> code2;
	}
	cout << "different" << endl;
	system("pause");
	return 0;
}
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(void)
{
	// Open the product file
	ifstream inProduct("products.txt");	// To be closed
	if (!inProduct)
	{
		cout << "Error: unable to read file: \"products.txt\"" << endl;
		exit(1);
	}

	int code, num, charge;
	string item;

	// Possible bug: the file cannot have an extra line in the end,
	// or the last item will be read twice
	while (!inProduct.eof())
	{
		inProduct >> code >> num >> charge;
		getline(inProduct, item);
		
		printf("%i %i %i %s\n", code, num, charge, item.c_str());
	}

	//do
	//{
	//	inProduct >> code >> num >> charge;
	//	getline(inProduct, item);

	//	printf("%i %i %i %s\n", code, num, charge, item.c_str());
	//}while (!inProduct.eof());

	inProduct.close();
}
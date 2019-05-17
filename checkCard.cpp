#include <iostream>
#include <string>

using namespace std;

// A function that validate a credit card number
// Parameter: string: card number
// Return type: bool: valid or not
bool validate(string n)
{
	int size = n.length();

	if (size > 19)	// Type cast to prevent overflow
	{
		return false;
	}

	// Sum of the even digits
	int digit;
	int sum = 0;    // sum of digits times two
	for (int i = 1; i < size; i += 2)
	{
		// Add even digits
		digit = n[size - 1 - i] - '0';
		if (digit < 5)    // 2 * 5 = 10, we add 1 + 0 instead of 10
		{
			sum += digit * 2;
		}
		else
		{
			int digitTwo = digit * 2;
			sum += digitTwo / 10 + digitTwo % 10;
		}
	}

	// Add odd digits
	for (int i = 0; i < size; i += 2)
	{
		digit = n[size - 1 - i] - '0';
		sum += n[size - 1 - i] - '0';
	}

	bool valid = (sum % 10 == 0) ? true : false;

	return valid;
}

int main(void)
{

	//// Get number
	//string num;    // Card number
	//cout << "Number: ";
	//cin >> num;
	//cout << num << endl;
	//cout << validate(num) << endl;	// Output 1 if valid, 0 if invalid

	cout << validate("4388576018410707") << endl;	// 1
	cout << validate("4388576018402625") << endl;	// 0
	cout << validate("4003600000000014") << endl;	// 1
	cout << validate("378282246310005") << endl;	// 1
	cout << validate("6011111111111117") << endl;	// 1
	cout << validate("2221000000000009") << endl;	// 1
	cout << validate("4111111111111111") << endl;	// 1


	return 0;
}

/*
Test cases: 
4388576018410707
4388576018402625
4003600000000014
378282246310005
6011111111111117
2221000000000009
4111111111111111
*/


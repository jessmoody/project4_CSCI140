#include <iostream>
#include <math.h>

using namespace std;

// Validate a credit card number
// Parameter: long
// Return type: bool
bool validate(long long n)
{
	const int MAX_SIZE = 19;    // The maximum length for a credit card number is 19

	if (n / (long long) pow(10, 19) != 0)	// Type cast to prevent overflow
	{
		return false;
	}

	// Sum of the even digits
	int digit;     // even digits
	int sum = 0;    // sum of digits times two
	for (int i = 1; i < MAX_SIZE; i += 2)
	{
		// Extract the even digits
		digit = n % (long long)pow(10, i + 1) / pow(10, i);
		// Add even digits
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
	for (int i = 0; i < MAX_SIZE; i += 2)
	{
		sum += n % (long long)pow(10, i + 1) / pow(10, i);
	}

	bool valid = (sum % 10 == 0) ? true : false;

	return valid;
}

int main(void)
{

	// Get number
	long long num;    // Card number
	for (int i = 0; i < 7; i++)
	{
		cout << "Number: ";
		cin >> num;
		cout << validate(num) << endl;	// Output 1 if valid, 0 if invalid
	}


	return 0;
}




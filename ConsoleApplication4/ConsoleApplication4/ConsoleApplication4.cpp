// C++ program to find repeating sequence in a fraction
#include "stdafx.h"
#include <map>
#include <iostream>
#include <string>
using namespace std;

// This function returns repeating sequence of
// a fraction. If repeating sequence doesn't
// exits, then returns empty string
string fractionToDecimal(int numr, int denr)
{
	string res; // Initialize result


	map <int, int> mp;
	mp.clear();

	// Find first remainder
	int rem = numr%denr;

	// Keep finding remainder until either remainder
	// becomes 0 or repeats
	while ( (rem!=0) && (mp.find(rem) == mp.end()) )
	{
		// Store this remainder
		mp[rem] = res.length();

		// Multiply remainder with 10
		rem = rem*10;

		// Append rem / denr to result
		int res_part = rem / denr;
		res += to_string(res_part);

		// Update remainder
		rem = rem % denr;
	}

	return (rem == 0)? "" : res.substr(mp[rem]);
}

int main()
{
	int numr = 1, p = 0; 
	cout << "Enter P:";
	cin >> p;
	string res = fractionToDecimal(numr, p);
	if (res == "")
		cout << endl << "No recurring sequence";
	else {
		cout << "Recurring sequence is " << res;
		if (p < 1000 && res.length() == (p - 1)) {
			cout << endl << "P is smaller than 1000 and it's length equals (P-1)!";
		}
	}
		
	system("pause");
	return 0;
}
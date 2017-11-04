// Trigonometry
// Amirali Ahmadi
//951542182003

#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;

#define PI 3.14159265

void calculate(int i){
	long double value;
	cout << "enter your PI's Coefficient: ";
	cin >> value;
	if (i == 1) {
		cout << sin((PI*value) / 180);
	}
	if (i == 2) {
		cout << cos((PI*value) / 180);
	}
	if (i == 3) {
		cout << sinh(value);
	}
	if (i == 4) {
		cout << cosh(value);
	}
	optionize();
}


void optionize() {
	int i,j=1;
		cout << "please enter the number of the option you need" << endl;
		cout << "1.sinx" << endl << "2.cosx" << endl << "3.sinhx" << endl << "4.cosh" << endl;
		cin >> i;
		if (i > 0 && i <= 4) {
			j = 0;
			calculate(i);
		}
}


int main()
{
	optionize();
	system("pause");
    return 0;
}


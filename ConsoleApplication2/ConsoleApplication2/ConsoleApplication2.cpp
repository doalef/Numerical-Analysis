// Horner's Method
//Amirali Ahmadi
//9515142182003

#include "stdafx.h"
#include "polynomial.h"
#include <iostream>
using namespace std;


int main()
{
	int i, j;
	cout << "enter the length and highest exp:";
	cin >> i >> j;
	cout << endl;
	polynomial poly(i,j);
	poly.init();
	//poly.print();
	poly.hornerMethod();
	system("pause");
    return 0;
}


// Horner's Method
//Amirali Ahmadi
//9515142182003

#include "stdafx.h"
#include "polynomial.h"
#include <iostream>
using namespace std;


int main()
{
	polynomial poly(2, 2);
	poly.init();
	//poly.print();
	poly.hornerMethod();
	system("pause");
    return 0;
}


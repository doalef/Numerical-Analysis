#include "stdafx.h"

#include <iostream>
#include<cmath>
#include <iomanip>
using namespace std;
double k;

double binaryToDecimal(double q) {
	double ans, bin, frac, fun = 0.0, a;
	int sum = 0, dec, i = 0, rem, b, j = 1;
	bin = q;
	dec = bin;
	frac = bin - dec;
	while (dec != 0)
	{
		rem = dec % 10;
		dec = dec / 10;
		sum = sum + (rem*pow(2, (i++)));
	}
	while (frac != 0.000)
	{
		a = 10 * frac;
		b = a;
		fun = fun + (b*(1 / pow(2, (j++))));
		frac = a - b;
	}
	ans = sum + fun;
	return ans;
}

void decimalToBinary(double q) {
	double z, doub, r, n, count = 0, frac;
	int i = 0;
	int num, p, ar[100];
	doub = q;
	num = doub;
	frac = doub - num;
	while (num != 0)
	{
		ar[i] = num % 2;
		num = num / 2;
		i++;
		count++;
	}

	cout << "The Binary form of this number is ";
	for (i = (count - 1); i >= 0; i--)
	{
		cout << ar[i];
	}
	cout << ".";
	while (frac != 0)
	{
		z = frac * 2;
		p = z;
		frac = z - p;
		cout << p;
	}
}

void main()
{
	double expansion, m, n, r;
lable:
	cout << "Enter m , n , k and r:";
	cin >> m >> n >> k >> r;
	if (m > n)
		goto lable;
	if (r == 2) {
		expansion = (m / n);
		int temp = (expansion * pow(10, k));
		expansion = 0.0;
		expansion = (temp / pow(10, k));
		decimalToBinary(expansion);
	}
	if (r == 10) {
		expansion = m;
		cout << setprecision(k) << fixed << binaryToDecimal(expansion);
	}
	system("pause");
}


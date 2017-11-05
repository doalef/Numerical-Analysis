#include "stdafx.h"
#include "polynomial.h"
#include <cmath>
#include <iostream>
using namespace std;


polynomial::polynomial()
{
}

polynomial::polynomial(int n, int d) {
	num = n;
	degree = d;
	term_ = new term[degree];
}


polynomial::~polynomial()
{
}

void polynomial::init() {
	for (int i = num-1; i >= 0; i--) {
		cout << "enter coef: ";
		cin >> term_[i].coef;
		cout << endl << "enter exp: ";
		cin >> term_[i].exp;
	}
}

void polynomial::print() {
	string x = "x^";

	for (int i = num - 1; i >= 0; i--) {
		//if == 0 then doesn't need + at the end of it 
		if (i == 0 && term_[i].exp == 0) {
			//checking for positive and negative 
			if (term_[i].coef >= 0) {
				cout << term_[i].coef;
			}
			else
			{
				cout << "(-" << term_[i].coef << ")";
			}
		}
		else if (i == 0 && term_[i].exp > 0) {
			//checking for positive and negative 
			if (term_[i].coef > 0) {
				cout << term_[i].coef << "x^" << term_[i].exp;
			}
			else
			{
				cout << "(-" << term_[i].coef << ")" << "x^" << term_[i].exp;
			}
		}
		else
		{
			//checking for positive and negative 
			if (term_[i].coef > 0) {
				cout << term_[i].coef << "x^" << term_[i].exp << " + ";
			}
			else
			{
				cout << "(-" << term_[i].coef << ")" << "x^" << term_[i].exp << " + ";
			}
		}
	}
}

float polynomial::Eval(float f) {
	float res = 0;
	for (int i = 0; i < degree; i++) {
		if (term_[i].exp != 0) {
			res += (term_[i].coef * pow(f, term_[i].exp));
		}
		else if (term_[i].exp == 0) {
			res += term_[i].coef;
		}		
	}
	return res;
}

void polynomial::hornerMethod() {
	float value=2;
	polynomial anchor(degree, num);
	for (int i = num - 1; i >= 0; i--) {
		anchor.term_[i].coef = term_[i].coef;
		anchor.term_[i].exp = term_[i].exp;
	}
	int l = 0;
	for (int i = 0; i < degree; i++) {
		if (l == 0) {
			cout << endl << "function:" << endl;
			anchor.print();
			cout << endl << "value:" << endl;
			cout << anchor.Eval(value);
			l++;
		}
		for (int j = num; j >= 0; j--) {
			if (anchor.term_[j].exp == 0) {
				anchor.term_[j].coef = 0.0;
			}
			else {
				anchor.term_[j].coef *= anchor.term_[j].exp;
				anchor.term_[j].exp--;
			}
		}
		if (l != 0) {
			cout << endl << "function:" << endl;
			anchor.print();
			cout << endl << "value:" << endl;
			cout << anchor.Eval(value);
		}
	}
}



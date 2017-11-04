#pragma once
//#include "term.h"
class polynomial
{
	friend class horner;
public:
	polynomial();
	polynomial(int d, int n);
	~polynomial();


	void init();
	void print();
	void hornerMethod();
	float Eval(float f);

	int degree;
	int num;
	struct term
	{
		int exp;
		float coef;
	}*term_;
};
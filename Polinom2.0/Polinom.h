#pragma once
#include"Monom.h"
class Polinom
{
	Monom *pFirst;

public:
	int isEmpty();
	int isFull();
	Polinom(int C);
	Polinom addition(const Polinom &);
	Polinom Minus(const Polinom &);
	void Input();
	void Add(Monom *);
	Polinom(Monom *);
	Polinom(Polinom &);
	Polinom operator=(Polinom &);
	void out(char*);
	Polinom();
	~Polinom();
};


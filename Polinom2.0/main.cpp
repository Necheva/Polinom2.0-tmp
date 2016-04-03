#include"Polinom.h"
#include<iostream>
using namespace std;

int main()
{
	Polinom F;
	F.Input();
	F.out("First polinom");
	cout << endl;
	Polinom T;
	T.Input();
	T.out("Second polinom");
	cout << endl;
	cout << "_______________________________________________________" << endl;
	Polinom S = F.addition(T);
	S.out("Sum of polinoms");
	cout << endl;
	Polinom C = F.Minus(T);
	C.out("Raznost of polinoms");
	cout << endl;
	
}
#include "Polinom.h"
#include<iostream>
using namespace std;
Polinom::Polinom()
{
	pFirst = 0;

}

Polinom::Polinom(int C)
{

}
Polinom::Polinom(Polinom &A)
{
	pFirst = 0;
	for (Monom *R = A.pFirst; R != 0; R = R->pNext)
	{
		this->Add(R);
	}
}

Polinom Polinom:: operator=(Polinom &A)
{
	Monom *tmp = pFirst;
	while (tmp != 0)
	{
		Monom *prev = tmp;
		tmp = tmp->pNext;
		delete prev;
	}
	pFirst = 0;
	for (Monom *R = A.pFirst; R != 0; R = R->pNext)
	{
		this->Add(R);
	}
	return *this;
}

Polinom::Polinom(Monom *P)
{
	pFirst = P;

}

void Polinom::Add(Monom*A)
{
	Monom *Q = new Monom(*A);//создали новый моном для добавления
	if (pFirst == 0)
	{
		pFirst = Q;
	}
	else
	{
		Monom *tmp = pFirst;
		Monom *prev = 0;
		while (tmp != 0 && tmp->StepX > Q->StepX && tmp->StepY > Q->StepY && tmp->StepZ > Q->StepZ)
		{
			prev = tmp;
			tmp = tmp->pNext;
		}
		if (tmp == 0)//добавление в конец
			prev->pNext = Q;
		else
		{
			if (tmp->StepX == Q->StepX && tmp->StepY == Q->StepY && tmp->StepZ == Q->StepZ)//если степени равны, то складываем коэффициенты
			{
				tmp->Data = tmp->Data + Q->Data;
			}
			else
			{
				if (prev != 0)//добавление в середину
				{
					Q->pNext = tmp;
					prev->pNext = Q;
				}
				else//добавление в голову
				{
					Q->pNext = pFirst;
					pFirst = Q;
				}
			}
		}
	}
}

int Polinom::isEmpty()
{
	return pFirst == 0;
}

int Polinom::isFull()
{
	Monom* tmp = new Monom(1, 0, 0, 0, 0);
	int res = (tmp == 0);
	if (tmp != 0)
	{
		delete tmp;
	}
	return res;
}

Polinom Polinom::addition(const Polinom &A)
{
	Monom *tmp;
	Monom *tmpA;
	Polinom res;
	tmp = this->pFirst;
	tmpA = A.pFirst;

	while (tmp != 0 && tmpA != 0)
	{
		if (tmp->StepX > tmpA->StepX )
		{
			res.Add(tmp);
			tmp = tmp->pNext;
		}
		else
		{
			if (tmp->StepX == tmpA->StepX && tmp->StepY == tmpA->StepY && tmp->StepZ == tmpA->StepZ)
			{
				res.Add(new Monom(tmp->Data + tmpA->Data, 0, tmp->StepX, tmp->StepY, tmp->StepZ));
				tmp = tmp->pNext;
				tmpA = tmpA->pNext;
			}
			else
			{
				res.Add(tmpA);
				tmpA = tmpA->pNext;
			}
		}
	}
	//дописываем остатки хвостов
	while (tmp != 0)
	{
		res.Add(tmp);
		tmp = tmp->pNext;
	}
	while (tmpA != 0)
	{
		res.Add(tmpA);
		tmpA = tmpA->pNext;
	}

	return res;
}

Polinom Polinom::Minus(const Polinom &M)
{
	Monom *tmp;
	Monom *tmpA;
	Polinom res;
	tmp = this->pFirst;
	tmpA = M.pFirst;

	while (tmp != 0 && tmpA != 0)
	{
		if (tmp->StepX > tmpA->StepX)
		{
			res.Add(tmp);
			tmp = tmp->pNext;
		}
		else
		{
			if (tmp->StepX == tmpA->StepX && tmp->StepY == tmpA->StepY && tmp->StepZ == tmpA->StepZ)
			{
				res.Add(new Monom(tmp->Data - tmpA->Data, 0, tmp->StepX, tmp->StepY, tmp->StepZ));
				tmp = tmp->pNext;
				tmpA = tmpA->pNext;
			}
			else
			{
				res.Add(tmpA);
				tmpA = tmpA->pNext;
			}
		}
	}
	//дописываем остатки хвостов
	while (tmp != 0)
	{
		res.Add(tmp);
		tmp = tmp->pNext;
	}
	while (tmpA != 0)
	{
		res.Add(tmpA);
		tmpA = tmpA->pNext;
	}

	return res;
}

void Polinom::Input()
{
	int StepX,StepY,StepZ;
	int Data;
	char Y;
	while (1)
	{
		cout << "enter step X: ";
		cin >> StepX;
		cout << "enter step Y: ";
		cin >> StepY;
		cout << "enter step Z: ";
		cin >> StepZ;
		cout << "enter data: ";
		cin >> Data;

		Monom M(Data,0,StepX,StepY,StepZ);
		this->Add(&M);

		cout << "more(Y/N) ?: ";
		cin >> Y;
		if (Y == 'N' || Y == 'n')
			break;
	}
	cout << endl;
}

void Polinom::out(char*Z)
{
	cout << Z << endl;
	
	for (Monom *i = pFirst; i != 0; i = i->pNext)
	{
		if (i->Data == 0)
			cout << "your monom is= 0" << endl;
		else
		{
			{
				cout << "your monom is= " << i->Data << "*" << "(" << " X^" << i->StepX << "*" << " Y^" << i->StepY << "*" << " Z^" << i->StepZ << ")";
				cout << endl;
			}
		}
	}
}

Polinom::~Polinom()
{
	Monom *tmp = pFirst;
	while (tmp != 0)
	{
		Monom *prev = tmp;
		tmp = tmp->pNext;
		delete prev;
	}
}

#include "Monom.h"

Monom::Monom(int D, Monom *P, int SX,int SY,int SZ)
{
	Data = D;
	pNext = P;
	StepX = SX;
	StepY = SY;
	StepZ = SZ;
}
Monom::Monom(Monom &D)
{
	Data = D.Data;
	StepX = D.StepX;
	StepY = D.StepY;
	StepZ = D.StepZ;
	pNext = 0;
}

Monom* Monom::GetNext()
{
	return pNext;
}

int Monom::GetStepX()
{
	return StepX;
}

int Monom::GetStepY()
{
	return StepY;
}

int Monom::GetStepZ()
{
	return StepZ;
}

int Monom::GetData()
{
	return Data;
}

void Monom::SetNext(Monom *p)
{
	pNext = p;
}

Monom::~Monom()
{

}

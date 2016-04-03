#pragma once
#pragma once
class Monom
{
	int Data;
	Monom *pNext;
	int StepX, StepY, StepZ;
public:
	int GetData();
	Monom* GetNext();
	int GetStepX();
	int GetStepY();
	int GetStepZ();
	Monom(Monom &);
	void SetNext(Monom *p);
	Monom(int D, Monom *P, int SX, int SY,int SZ);
	~Monom();
	friend class Polinom;
};


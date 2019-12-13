#pragma once
#include <iostream>


#include "TNode.h"
#include "TException.h"

class TMonom : public TNode<unsigned, double>
{
public:
	TMonom(unsigned key_, const double* pData_);
	TMonom(unsigned key_, const double& data);
	TMonom(const TMonom& temp);
	TMonom(const TNode<unsigned, double>& temp);
	~TMonom();

	TNode<unsigned, double> operator*(const TMonom& temp);
	//TNode<unsigned, double> operator+(const TMonom& temp);

	friend std::ostream& operator<<(std::ostream& out, const TMonom& monom);

	friend TMonom operator-(const TMonom& temp);
};

TMonom::TMonom(unsigned key_, const double* pData_) : TNode<unsigned, double>(key_, pData_)
{
	if (key > 999 || *pData == 0) throw TException(NotInSystem);
}

TMonom::TMonom(unsigned key_, const double& data) : TNode<unsigned, double>(key_, data)
{
	if (key > 999 || *pData == 0) throw TException(NotInSystem);
}

TMonom::TMonom(const TMonom& temp) : TNode<unsigned, double>(temp)
{
	if (key > 999 || *pData == 0) throw TException(NotInSystem);
}

TMonom::TMonom(const TNode<unsigned, double>& temp) : TNode<unsigned, double>(temp)
{
	if (key > 999 || *pData == 0) throw TException(NotInSystem);
}

TMonom::~TMonom()
{

}

TNode<unsigned, double> TMonom::operator*(const TMonom& temp)
{
	if ((key / 100 + temp.key / 100) >= 10) throw TException(NotInSystem);
	if ((key % 100 / 10 + temp.key % 100 / 10) >= 10) throw TException(NotInSystem);
	if ((key % 10 + temp.key % 10) >= 10) throw TException(NotInSystem);
	TNode<unsigned, double> out(key + temp.key, *pData * *(temp.pData));
	return out;
}

/*TNode<unsigned, double> TMonom::operator+(const TMonom& temp)
{
	TNode<unsigned, double> out(key, *pData + *(temp.pData));
	return out;
}*/

std::ostream& operator<<(std::ostream& out, const TMonom& monom)
{
	if (*(monom.pData) > 0)
		out << "+";
	else
		out << "-";
	if ((*(monom.pData) != 1 && *(monom.pData) != -1) || monom.key == 0)
		out << abs(*(monom.pData));
	if (monom.key / 100 != 0)
		out << "x^" << (monom.key / 100);
	if (monom.key % 100 / 10 != 0)
		out << "y^" << (monom.key % 100 / 10);
	if (monom.key % 10 != 0)
		out << "z^" << (monom.key % 10);
	return out;
}

TMonom operator-(const TMonom& temp)
{
	TMonom out(temp.key, -*(temp.pData));
	return out;
}
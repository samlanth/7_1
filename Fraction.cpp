#include "Fraction.h"

int CFraction::GetDen() const 
{
	return den_;
}
int CFraction::GetNum() const
{
	return num_;
}
void CFraction::SetDen(int den)
{
	den_ = den;
}
void CFraction::SetNum(int num)
{
	num_ = num;
}
//Une CFraction devra avoir un constructeur paramétrique qui permet de donner les deux nombres qui la composent,
//seulement le numérateur (1 sera alors utilisé comme dénominateur par défaut) ou rien du tout (0/1 sera alors la fraction par défaut obtenue).
CFraction::CFraction(int num, int den) 
	: num_(num), den_(den)
{
}
CFraction::CFraction(int nombre)
	: num_(nombre), den_(1)
{

}
CFraction::CFraction()
	: num_(0), den_(1)
{

}
bool CFraction::operator==(const CFraction& f) const
{
	double d1 = static_cast<double>(num_) / static_cast<double>(den_);
	double d2 = static_cast<double>(f.num_) / static_cast<double>(f.den_);
	return (d1 == d2);
	//if (num_ == Fraction.num_ && den_ == Fraction.den_ || (num_ * Fraction.den_) == (den_ * Fraction.num_))
	//	return true;
	//else
	//	return false;
}
bool CFraction::operator!=(const CFraction& Fraction) const
{
	return !operator==(Fraction);
	//if (num_ != Fraction.num_ && den_ != Fraction.den_ || (num_ * Fraction.den_) != (den_ * Fraction.num_))
	//	return true;
	//else
	//	return false;
}
CFraction& CFraction::operator=(const CFraction& Fraction)
{
	if (this != &Fraction)
	{
		SetNum(Fraction.GetNum());
		SetDen(Fraction.GetDen());
	}
	return *this;
}
CFraction& CFraction::operator+=(int Valeur)
{
	Valeur = Valeur * GetDen();
	SetNum(GetNum() + Valeur);
	SetDen(GetDen());
	return *this;
}
CFraction& CFraction::operator+=(const CFraction& LaFraction)
{
	SetNum(GetNum() * LaFraction.GetDen() + (LaFraction.GetNum() * GetDen()));
	SetDen(GetDen() * LaFraction.GetDen());
	return *this;
}

// global
CFraction operator+(const CFraction &LaFraction, int Valeur)
{
	// f5 + 3
	Valeur = Valeur * LaFraction.GetDen();

	int NouvelleVal = (LaFraction.GetNum() + Valeur);
	int n2 = (LaFraction.GetDen());
	CFraction Nouveau(NouvelleVal, n2);
	return Nouveau;
}

CFraction CFraction::operator++(int)
{
	// n1/d1 + 1 = (n1+1*d1)/d1
	CFraction old = *this;
	this->num_ = this->num_ + 1*this->den_;
	return old;
}

CFraction& CFraction::operator++()
{
	// n1/d1 + 1 = (n1+1*d1)/d1
	this->num_ = this->num_ + 1 * this->den_;
	return *this;
}
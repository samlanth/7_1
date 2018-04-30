#include <iostream>
#include "Fraction.h"
using namespace std;

CFraction operator+(const CFraction &LaFraction, int Valeur)
{
	// f5 + 3
	Valeur = Valeur * LaFraction.GetDen();

	int NouvelleVal = (LaFraction.GetNum() + Valeur);
	int n2 = (LaFraction.GetDen());
	CFraction Nouveau(NouvelleVal,n2);
	return Nouveau;
}   

CFraction operator+(int Valeur, const CFraction &LaFraction)
{
	return operator+(LaFraction,Valeur);
}

CFraction operator+(const CFraction &LaFraction, const CFraction &LaFraction2)
{
	// n1/d1 + n2/d2 = n1*d2 + n2*d1 / (d1*d2)
	int n = LaFraction.GetNum() * LaFraction2.GetDen() + LaFraction2.GetNum() * LaFraction.GetDen();
	int d = LaFraction.GetDen() * LaFraction2.GetDen();

	return CFraction(n, d);
}

ostream & operator<<(ostream& os, const CFraction& Fraction)
{
	os << Fraction.GetNum() << "/";
	os << Fraction.GetDen();
	return os;
}

CFraction LaPlusPetite(CFraction f1, CFraction f2, CFraction f3)
{
	CFraction r;
	if ((f1 < f2) && (f1 < f3)) r = f1;
	else if ((f2 < f1) && (f2 < f3)) r = f2;
	else r = f3;
	
	cout << "Dans fonction -- Nombre de fractions: " << CFraction::GetCompteur() << endl;
	// Affiche 7 (f1, f2, f3 dans le main, plus f1, f2, f3 et plusPetite locales)

	return r;
}

int main()
{
	CFraction f1(3, 4);
	CFraction f2(5, 8);
	CFraction f3(6, 15);

	CFraction pp = LaPlusPetite(f1, f2, f3);
	cout << "La plus petite fraction entre " << f1 << ", " << f2 << " et " << f3 << " est " << pp << endl;
	// Affiche 6/15 (ou 2/5)

	cout << "Dans main -- Nombre de fractions: " << CFraction::GetCompteur() << endl;
	// Affiche 4 (f1, f2, f3 et pp)
	system("pause");
}
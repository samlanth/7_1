#include <iostream>
#include "Fraction.h"
using namespace std;

//CFraction operator+(const CFraction &LaFraction, int Valeur)
//{
//	// f5 + 3
//	Valeur = Valeur * LaFraction.GetDen();
//
//	int NouvelleVal = (LaFraction.GetNum() + Valeur);
//	int n2 = (LaFraction.GetDen());
//	CFraction Nouveau(NouvelleVal,n2);
//	return Nouveau;
//}   

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

int main()
{
	CFraction f1(3, 4);
	CFraction f2(5, 8);
	CFraction f3;
	CFraction f3b;
	CFraction f4(1, 2);
	CFraction f5(5, 10);
	
	f3 = f3b = f1;

	cout << f1 << endl; // Affiche 3/4
	cout << f2 << endl; // Affiche 5/8
	cout << f3 << endl; // Affiche 3/4

    f1 += f2;
	cout << f1 << endl; // Affiche 44/32 (ou 11/8)

	f2 += 2;
	cout << f2 << endl; // Affiche 21/8

	cout << f4 + f5 << endl; // Affiche 20/20 (ou 1/1)
	cout << f5 + 3 << endl; // Affiche 35/10 (ou 7/2)
	cout << 3 + f5 << endl; // Affiche 35/10 (ou 7/2)

	if (f4 == f5)
	{
		cout << "Fractions equivalentes" << endl; // Devrait être affiché
	}

	if (f4 != f2)
	{
		cout << "Fractions differentes" << endl; // Devrait être affiché
	}
	cout << f4++ << endl; // Affiche 1/2
	cout << f4 << endl; // Affiche 3/2

	cout << ++f4 << endl; // Affiche 5/2
	cout << f4 << endl; // Affiche 5/2

	system("pause");
}
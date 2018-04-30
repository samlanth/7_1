/*
----------------------------------------------------------------
Samuel Lanthier
2018-04-30
Fraction.h
declaration Operator
-----------------------------------------------------------------
*/
//Vous devez concevoir une classe CFraction qui impl�mente un nombre rationnel,
//sous forme num�rateur/d�nominateur. Par exemple, 3/4 est une fraction, 5/10 aussi.
#pragma once
class CFraction
{
private:
	int num_;
	int den_;

public:
	//Une CFraction devra avoir un constructeur param�trique qui permet de donner les deux nombres qui la composent,
	//seulement le num�rateur (1 sera alors utilis� comme d�nominateur par d�faut) ou rien du tout (0/1 sera alors la fraction par d�faut obtenue).
	CFraction(int num, int den);
	CFraction(int nombre);
	CFraction();
	//acceseur mutateur
	void SetNum(int num);
	void SetDen(int den);
	int GetDen() const;
	int GetNum() const;
	//== retourne vrai si les deux fractions sont �quivalentes, c'est-�-dire qu'elles repr�sentent le m�me nombre rationnel. Par exemple, 3/4 == 6/8, 1/2 == 5/10, et 4/5 == 4/5. 
	bool operator==(const CFraction& Fraction) const;
	//!= retourne le contraire de ce que == retournerait! (En bons programmeurs, on �vitera de coder deux fois la m�me chose; mieux vaut appeler l'op�rateur qu'on a d�j� fait...)
	bool operator!=(const CFraction& Fraction) const;
	//= l'op�rateur d'affectation permettra d'affecter une fraction � une autre en copiant ses attributs et en se retournant, pour permettre les affectations � la cha�ne. Ainsi, ce code sera fonctionnel: 
	CFraction& operator=(const CFraction& Fraction);
	//+= vous ferez deux versions de cet op�rateur: 
	//La premi�re version permettra d'ajouter un entier � la fraction. Ainsi, ces lignes seront valides:
	CFraction& operator+=(int Valeur);
	//La deuxi�me version permettra d'ajouter une fraction � une fraction. Ainsi, ces lignes seront valides: 
	CFraction& operator+=(const CFraction& LaFraction);
	//On conviendra que l'op�rateur ++ ajoutera 1 (entier) � la fraction.
	CFraction operator++(int);
	CFraction& operator++();
};

CFraction operator+(const CFraction &LaFraction, int Valeur);

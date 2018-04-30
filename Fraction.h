/*
----------------------------------------------------------------
Samuel Lanthier
2018-04-30
Fraction.h
declaration Operator
-----------------------------------------------------------------
*/
//Vous devez concevoir une classe CFraction qui implémente un nombre rationnel,
//sous forme numérateur/dénominateur. Par exemple, 3/4 est une fraction, 5/10 aussi.
#pragma once
class CFraction
{
private:
	int num_;
	int den_;

public:
	//Une CFraction devra avoir un constructeur paramétrique qui permet de donner les deux nombres qui la composent,
	//seulement le numérateur (1 sera alors utilisé comme dénominateur par défaut) ou rien du tout (0/1 sera alors la fraction par défaut obtenue).
	CFraction(int num, int den);
	CFraction(int nombre);
	CFraction();
	//acceseur mutateur
	void SetNum(int num);
	void SetDen(int den);
	int GetDen() const;
	int GetNum() const;
	//== retourne vrai si les deux fractions sont équivalentes, c'est-à-dire qu'elles représentent le même nombre rationnel. Par exemple, 3/4 == 6/8, 1/2 == 5/10, et 4/5 == 4/5. 
	bool operator==(const CFraction& Fraction) const;
	//!= retourne le contraire de ce que == retournerait! (En bons programmeurs, on évitera de coder deux fois la même chose; mieux vaut appeler l'opérateur qu'on a déjà fait...)
	bool operator!=(const CFraction& Fraction) const;
	//= l'opérateur d'affectation permettra d'affecter une fraction à une autre en copiant ses attributs et en se retournant, pour permettre les affectations à la chaîne. Ainsi, ce code sera fonctionnel: 
	CFraction& operator=(const CFraction& Fraction);
	//+= vous ferez deux versions de cet opérateur: 
	//La première version permettra d'ajouter un entier à la fraction. Ainsi, ces lignes seront valides:
	CFraction& operator+=(int Valeur);
	//La deuxième version permettra d'ajouter une fraction à une fraction. Ainsi, ces lignes seront valides: 
	CFraction& operator+=(const CFraction& LaFraction);
	//On conviendra que l'opérateur ++ ajoutera 1 (entier) à la fraction.
	CFraction operator++(int);
	CFraction& operator++();
};

CFraction operator+(const CFraction &LaFraction, int Valeur);

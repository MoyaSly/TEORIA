#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

// Friend, si a la calss A posem "friend class B;" la class B pot veure tot el private i protected de A.
// al struct si no poses res tot el public, en canvi a una class tot es privat a no ser que posis public.
// struct es per emmagatzemar dades.
// la unica diferencia entre class y struct es el private i el public base.
//el polimorfisme fa que un mateix metode faci diferents resultats segons la especialització de la classe.

using namespace std;

class Shape
{
public:
	int base;
	int altura;

	virtual float GetArea()const
	{
		return 0;
	}

};

class Triangle : public Shape
{
public:
	float GetArea()const { return (base*altura) / 2; }

};

class Cuadrado : public Shape
{
public:
	float GetArea()const { return (base*altura); }
};


int main()
{
	Shape* s1 = new Triangle();
	Shape* s2 = new Cuadrado();

	s1->altura = 4;
	s1->base = 3;
	s2->altura = 4;
	s2->base = 3;


	cout << s1->GetArea() << endl;
	cout << s2->GetArea() << endl;

	getchar();
}
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

// Friend, si a la calss A posem "friend class B;" la class B pot veure tot el private i protected de A.
// al struct si no poses res tot el public, en canvi a una class tot es privat a no ser que posis public.
// struct es per emmagatzemar dades.
// la unica diferencia entre class y struct es el private i el public base.
// el polimorfisme fa que un mateix metode faci diferents resultats segons la especialització de la classe.
// const char* c -> puedes modificar hacia donde apunta c, pero no lo que apunta (*c = NULL) MAL, (c++) BIEN. porque cambia la direccion de c.
/* 
///////////////Metodes Automatics///////////////////////
Class Gaga
{
	public:
		Gaga();						-> CONSTRUCTOR PER DEFECTE
		Gaga(const Gaga&);			-> CONSTRUCTOR COPIA
		~Gaga();					-> DESTRUCTOR

		Gaga(Gaga&&);				-> CONSTRUCTOR MOURE
		Gaga operator=(Thing&&);	-> ASIGNACIÓ
};

Els 3 primers es creen automaticament.

Per crearse el 4t s'han de cumplir:
	!Constuctor de copia.
	!Asignació.
	!Move.
	!Destructor.
	Si no esta marcat com a deleted.
	Si tots els membres es poden moure.

Per crearse el 5e s'han de cumplir:
	!Constuctor de copia.
	!
	!Constructor de moure.
	!Destructor.
	Si no esta marcat com a deleted.
	Si tots els membres es poden moure.

*/

using namespace std;

class Shape
{
public:
	int base;
	int altura;

	Shape(){};

	virtual float GetArea()const
	{
		return 0;
	}
	virtual ~Shape(){};

};



class Triangle : public Shape
{
public:
	float GetArea()const { return (base*altura) / 2; }
	int* numbers;

	Triangle()
	{
		numbers = new int[999];
	}

	~Triangle()
	{
		delete[] numbers;
	}

};

class Cuadrado : public Shape
{
public:
	float GetArea()const { return (base*altura); }
	int* numbers;

	Cuadrado()
	{
		numbers = new int[999];
	}

	~Cuadrado()
	{
		delete[] numbers;
	}
};


void Swap(int* node1, int* node2)
{
	int a;
	a = *node1;
	*node1 = *node2;
	*node2 = a;
}

void Swap(float* node1, float* node2)
{
	float a;
	a = *node1;
	*node1 = *node2;
	*node2 = a;
}

void Swap(char* node1, char* node2)
{
	char a;
	a = *node1;
	*node1 = *node2;
	*node2 = a;
}

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
	int a = 5;
	int b = 6;
	float a1 = 5.0f;
	float b1 = 6.6f;
	char a2 = '5';
	char b2 = '6';

	int* pa = &a;
	int* pb = &b;
	float* pa1 = &a1;
	float* pb1 = &b1;
	char* pa2 = &a2;
	char* pb2 = &b2;

	Swap(pa, pb);
	Swap(pa1, pb1);
	Swap(pa2, pb2);

	cout << endl << a << endl << b << endl << a1 << endl << b1 << endl << a2 << endl << b2 << endl;

	delete s1;
	delete s2;
	getchar();
}
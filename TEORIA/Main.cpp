
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Circle.h"
#include "Point2D.h"
#include "String.h"
#include "DynArray.h"
#include "Defs.h"
#include "List.h"
#include "StackList.h"

using namespace std;

// Friend, si a la calss A posem "friend class B;" la class B pot veure tot el private i protected de A.
// al struct si no poses res tot el public, en canvi a una class tot es privat a no ser que posis public.
// struct es per emmagatzemar dades.
// la unica diferencia entre class y struct es el private i el public base.
// el polimorfisme fa que un mateix metode faci diferents resultats segons la especialitzaci� de la classe.
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
		Gaga operator=(Thing&&);	-> ASIGNACI�
};

Els 3 primers es creen automaticament.

Per crearse el 4t s'han de cumplir:
	!Constuctor de copia.
	!Asignaci�.
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

/*		STATIC

1.	per definir una variable global
		- amb static nom�s es pot accedir des del mateix arxiu a la variable global.

2.	per definir una varieble en una funci�:
		- adressa inmodificable
		- existeix fins el final del programa
		- s'inicialtza 1 cop
		- la variable quedara com a global i sempre que s'entri a la funci� no la tornara a inicialitzar i podras cridarla des de fora de la funci�.

3.	per una funci� o una variable d'una clase
		- no queda vinculat amb un sol objecte
		- si la clase t� un valor static ocupara memoria
		- es un valor vinculat a tots els objectes, es a dir tots el modifiquen, si a 3 objectes sumesis 1 es sumarian 3 a la variable.
		- s'han dinicialitzar fora de la classe i en un .cpp (en un .h no es poden inicialitar estatiques)

*/

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

template <class TYPE>

void Swap(TYPE& node1, TYPE& node2)
{
	TYPE a;
	a = node1;
	node1 = node2;
	node2 = a;
};

/*void Swap(int* node1, int* node2)
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
}*/


int main()
{
	StackList<char> st;
	st.Push('a');
	st.Push('l');
	st.Push('o');
	st.Push('h');

	char h, o, l, a;

	st.Pop(h);
	st.Pop(o);
	st.Pop(l);
	st.Pop(a);


	cout << h << o << l << a;

	getchar();
	return 0;
}
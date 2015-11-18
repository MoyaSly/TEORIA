#ifndef __STRING__
#define __STRING__
#include "Defs.h"

class String
{
private:
	char* str;
	uint mem_capacity;

public:
	//Constructor  buit
	String();
	//Desde Char
	String(const char* str_c);
	//Constructor de copia
	String(const String& string);
	//Constructor copia memoria
	String(uint memory);
	//Destructor
	~String();
	
	//operador == Char
	bool operator==(const char* str_c)const;
	//operador == String
	bool operator==(const String& string)const;
	//operador != Char
	bool operator!=(const char* str_c)const;
	//operador != String
	bool operator!=(const String& string)const;
	//operador = String
	const String& operator=(const String& string);
	//operador += Char
	//const String& operator+=(const char* str_c);
	//operador += String
	//const String& operator+=(const String& string);


	//Capacity
	uint Capacity()const;
	//Trobem la capacitat
	uint GetCapacity(const char* str_c)const;
	//String to Char
	const char* c_str()const;

	//operadors d'asignacio
	//mirem si necessitem memoria, sino no fem new
	//si no cap hem de borrar la cadena anterior, al principi fem delete


	//HACER --> EMPTY(si es zero), CLEAR(le asignas \0), PREFIX(PONER PREFIJO) ,LENGHT(STRLEN)
};
#endif

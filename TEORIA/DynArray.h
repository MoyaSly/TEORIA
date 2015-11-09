
#ifndef __DYNARRAY__
#define __DYNARRAY__
#include "Defs.h"

template <class TYPE>
class DynArray
{
private:
	TYPE* data = NULL;
	uint capacity = BLOCK;
	uint num_elements = 0;

public:
	//CONSTRUCTOR BUIT
	DynArray() { data = new TYPE[capacity]; }
	//CONSTRUCTOR COPIA
	DynArray(const DynArray& dyn) : num_elements(dyn.num_elements)
	{
		capacity = MAX(BLOCK, num_elements);
		data = new TYPE[capacity];
		memcpy(data, dyn.data, dyn.num_elements*sizeof(TYPE));
	}
	//CONSTRUCTOR RESERVA MEMORIA
	DynArray(uint mem_res) : capacity(MAX(mem_res, BLOCK))
	{
		data = new TYPE[capacity];
	}
	//DESTRUCTOR
	~DynArray()
	{
		if (data != NULL)
			delete[] data;

	}
	//AÑADE 1 CARACTER
	void PushBack(const TYPE& data)
	{
		if (capacity < num_elements)
		{
			TYPE* tmp = data;
			capacity = capacity + BLOCK;
			data = new TYPE[capacity];
			memcpy(data, tmp, num_elements*sizeof(TYPE));
			delete[] tmp;
		}

		this->data[num_elements++] = data;

	}
	//RETURN CAPACIDAD
	uint Capacity()
	{
		return capacity;
	}
	//RETURN TAMAÑO
	uint Size()
	{
		return num_elements;
	}
	//RESET DATA
	void Clear()
	{
		num_elements = 0;
	}
	//ESTA VACIO?
	bool Empty()
	{
		if (data == NULL) ? true : false;
	}
	//RETURN POSICION ESPECIFICADA
	const TYPE At(uint pos)
	{
		if (pos <= num_elements) ? data[pos] : NULL;
	}
	//TODO
	/*
	operator[]
	operator=
	pop_back()	(elimina ultim element)
	srink_to_fit() (si sobra memoria es destrueix la k sobra)
	flip()
	insert(pos, data)   ABCDE -> INSERT(1, X) -> AXBCDE
	*/
};
#endif
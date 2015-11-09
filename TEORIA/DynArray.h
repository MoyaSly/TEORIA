#include "Defs.h"
#ifndef __DYNARRAY__
#define __DYNARRAY__


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
		capacity = MAX(BLOCK, dyn.capacity);
		data = new TYPE[capacity];
		memcpy(data, dyn.data, dyn.num_elements*sizeof(TYPE));
	}
	//CONSTRUCTOR RESERVA MEMORIA
	DynArray(TYPE& mem_res)
	{
		tmp = new TYPE[capacity];
		memcpy(data, tmp, num_elements*sizeof(TYPE));
		delete[] data;
		capacity += mem_res;
		data = new TYPE[capacity];
		memcpy(tmp, data, num_elements*sizeof(TYPE));
		delete[] tmp;
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
		if (capacity > num_elements)
		{
			this->data[num_elements++] = data;
		}
		else
		{
			tmp = new TYPE[capacity];
			memcpy(data, tmp, num_elements*sizeof(TYPE));
			delete[] tmp;
			capacity = capacity + BLOCK;
			data = new TYPE[capacity];
			memcpy(tmp, data, num_elements*sizeof(TYPE));
			data[num_elements++] = tmp;
			capacity = capacity + BLOCK;
			delete[] tmp;
		}

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
};
#endif
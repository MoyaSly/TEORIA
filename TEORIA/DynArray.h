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
		data = new TYPE[mem_res];
		memcpy(tmp, data, num_elements*sizeof(TYPE));
		delete[] tmp;

		capacity = mem_res;
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
		if (capacity > (num_elements + 1)
		{
			this->data[num_elements++] = data;
		}
		else
		{
			tmp = new TYPE[num_elements++];
			memcpy(data, tmp, num_elements*sizeof(TYPE));
			delete[] data;
			data = new TYPE[num_elements+1];
			capacity = num_elements+1;
			memcpy(tmp, data, num_elements*sizeof(TYPE));
			data[capacity] = tmp;
			delete[] tmp;

		}

	}

	uint Capacity()
	{
		return capacity;
	}

	uint Size()
	{
		return num_elements;
	}
	//RESET DATA
	void Clear()
	{
		data = NULL;
		capacity = BLOCK;
		num_elements = 0;
	}

	bool Empty()
	{
		if (data == NULL) ? true : false;
	}
	//RETURN POSICION ESPECIFICADA
	TYPE At(uint pos)
	{
		return data[pos];
	}

};



#endif
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
	DynArray() { data = new TYPE[capacity]; }

	DynArray(const DynArray& dyn) : num_elements(dyn.num_elements)
	{
		capacity = MAX(BLOCK, dyn.capacity);
		data = new TYPE[capacity];
		memcpy(data, dyn.data, dyn.num_elements*sizeof(TYPE));
	}

	~DynArray()
	{
		if (data != NULL)
			delete[] data;

	}

	void PushBack(const TYPE& data)
	{
		if (capacity > (num_elements + 1)
		{
			this->data[num_elements++] = data;
		}
		else
		{

		}

	}


	/*
	DILLUNS:
		- At(pos); dice posiciones
		- Capacity();
		- Size();
		- Clear();
		- Empty(); return true si esta buida
		- Constructor para reservar memoria -->  DynArray(mem_res){} (CAPACITAT) (todos los const hacen new)
	*/
};



#endif
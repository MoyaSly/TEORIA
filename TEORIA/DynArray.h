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
	DynArray(const DynArray<TYPE>& dyn) : num_elements(dyn.num_elements)
	{
		capacity = MAX(BLOCK, num_elements);
		data = new TYPE[capacity];
		memcpy(data, dyn.data, dyn.num_elements*sizeof(TYPE));
	}
	//CONSTRUCTOR RESERVA MEMORIA
	DynArray(uint mem_res) 
	{
		capacity = MAX(mem_res, BLOCK);
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
		if (capacity <= num_elements)
		{
			TYPE* tmp = data;
			capacity = capacity + BLOCK;
			this->data = new TYPE[capacity];
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
	bool At(uint pos)
	{
		if (pos <= num_elements)
		{

		}
	}
	//OPERATOR []
	TYPE& operator[](uint pos)
	{
		if (pos <= num_elements) ? data[pos] : NULL;
	}
	//OPERATOR [] CONST
	const TYPE& operator[](uint pos) const
	{
		if (pos < num_elements) ? data[pos] : NULL;
	}
	// OPERATOR =
	const DynArray operator = (const DynArray<TYPE>& dyn)
	{
		num_elements = dyn.num_elements;
		capacity = dyn.capacity;
		data = new TYPE[capacity];
		memcpy(data, dyn.data, num_elements*sizeof(TYPE));
		return *this;
	}
	//(elimina ultim element)
	bool PopBack()
	{
		if(num_elements > 0)
		{
			--num_elements;
			return true;
		}
		return false;
	}
	//(si sobra memoria es destrueix la k sobra)
	void SrinkToFit()
	{
		if (capacity != num_elements)
		{
		TYPE* tmp = data;
		capacity = num_elements;
		data = new TYPE[capacity];
		memcpy(data, tmp, num_elements*sizeof(TYPE));
		delete[] tmp;
		}
	}
	//MIRROR
	void Flip() //HACER CON SWAP
	{
		if (capacity != (num_elements + 1))
			SrinkToFit();
		TYPE* tmp = data;
		data = new TYPE[capacity];
		for (uint i = 0; i <= num_elements; ++i)
		{
			data[i] = tmp[num_elements - i];
		}
		delete[] tmp;
	}
	//INSERT DYNARRAY ON ESPECIFIC POS (ABCDE->INSERT(1, X) -> AXBCDE)  
	void Insert(uint pos, const DynArray<TYPE>& dyn)
	{
		TYPE* tmp = data;
		
		if (capacity < num_elements+dyn.num_elements)
			capacity += dyn.capacity;

		num_elements += dyn.num_elements;
		data = new TYPE[capacity];

		for (uint i = 0; i <= num_elements; ++i)
		{
			if (i < pos)
				data[i] = tmp[i];
			else if (i < (dyn.num_elements + pos))
				data[i] = dyn.data[i - pos];
			else
				data[i] = tmp[i - dyn.num_elements];
		}
		delete[] tmp; 
	}
};
#endif
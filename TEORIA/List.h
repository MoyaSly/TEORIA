
#ifndef __LIST__
#define __LIST__
#include "Defs.h"

template <class TYPE>
struct ListNode
{
private:
public:
	ListNode<TYPE>* next = NULL;
	ListNode<TYPE>* prev = NULL;

	TYPE data = NULL;

	ListNode(const TYPE& data) : data(data){}

	void GetNext(ListNode<TYPE>* next)		
	{
		this->next = next;
	}
	void GetPrev(ListNode<TYPE>* prev)
	{
		this->prev = prev;
	}
};

template <class TYPE>
class List
{
public:
	List(){};
	~List(){ Clear(); };

	//RETURN INICI
	ListNode<TYPE>* GetStart(ListNode<TYPE>* start){return this->start = start;}
	//RETURN FINAL
	ListNode<TYPE>* GetEnd()
	{
		ListNode<TYPE>* tmp = start;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		return tmp;
	}

	//TAMANY
	uint Size() const
	{
		ListNode<TYPE>* tmp = start;
		uint count = 0;
		while (tmp)
		{
			count++;
			tmp = tmp->next;
		}
		return count;
	}

	//AFEGEIX AL FINAL
	void PushBack(const TYPE& item)
	{
		ListNode<TYPE>* new_node = new ListNode<TYPE>(item);

		if (start == NULL)
			start = new_node;
		else
		{
			ListNode<TYPE>* tmp = GetEnd();
			tmp->next = new_node;
			new_node->prev = tmp;
		}
	}

	//NETEJA LA LLISTA
	void Clear()
	{
		if (start != NULL)
		{
			ListNode<TYPE>* tmp = start;
			while (tmp->next != NULL)
			{
				tmp = tmp->next;
				delete tmp->prev;
			}
		}
		start = NULL;
	}

	//COMPROVA SI ESTA BUIT
	const bool Empty()
	{
		 return start == NULL;
	}


	/*
	TODO
		- const Front() const puntero a start
		- const Back() const puntero al final
		- PushFront() 
		- PopBack() return del valor quitado (DATA)
		- PopFront() return del valor quitado (DATA)
		- Insert() afegeix node en la posició que vulguis
		- Remove() treu el node en la posició que vulguis

	*/
//private:
	ListNode<TYPE>* start = NULL;

	
};

#endif
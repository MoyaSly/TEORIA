
#ifndef __LIST__
#define __LIST__
#include "Defs.h"

template <class TYPE>
struct ListNode
{
	ListNode<TYPE>* next = NULL;
	ListNode<TYPE>* prev = NULL;

	TYPE data = NULL;

	ListNode(const TYPE& data) : data(data){}
};

template <class TYPE>
class List
{
public:
	List(){};
	~List(){ Clear(); };

	void GetStart(ListNode<TYPE>* start){this->start = start;}

	void GetEnd(ListNode<TYPE>* end)
	{
		ListNode<TYPE>* tmp = start;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = end;
		tmp->next->prev = tmp;
	}

	ListNode<TYPE>* SetEnd()
	{
		ListNode<TYPE>* tmp = start;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		return tmp;
	}
	
	//RETURN INICI
	ListNode<TYPE>* GetStart(){ return start;}
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
			ListNode<TYPE>* tmp = SetEnd();
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

	void PushFront(const TYPE& item)
	{
		ListNode<TYPE>* new_node = new ListNode<TYPE>(item);

		if (start == NULL)
			start = new_node;
		else
		{
			ListNode<TYPE>* tmp = start;
			new_node->next = tmp;
			tmp->prev = new_node;
		}

	}

	bool PopBack(TYPE& var)
	{
		ListNode<TYPE>* tmp = SetEnd();
		tmp->prev->next = tmp->prev;
		var = tmp->data;
		delete tmp;
		return true
	}

	bool PopFront(TYPE& var)
	{
		ListNode<TYPE>* tmp = start;
		tmp->next->prev = tmp;
		var = tmp->data;
		delete tmp;
		return true;
	}

	void Insert(uint pos, const TYPE& item)
	{
		if (start == NULL)
			start = new_node;
		else if (pos > Size())
		{
			PushBack();
		}
		else
		{
			ListNode<TYPE>* tmp = start;
			ListNode<TYPE>* new_node = new ListNode<TYPE>(item);

			tmp.Search(pos);

			new_node->prev = tmp->prev;
			new_node->next = tmp->next;
			tmp->next = new_node->next;
			tmp->prev = new_node;
		}
	}


	void Remove(uint pos)
	{
		if (pos > Size())
		{
			break;
		}
		else
		{
			ListNode<TYPE>* tmp = start;

			tmp.Search(pos);

			tmp->prev->next = tmp;
			tmp->prev->prev = tmp->prev->prev;
			tmp->next->prev = tmp;
			tmp->next->next = tmp->next->next;
			delete tmp;
		}
	}

	ListNode<TYPE>* Search(uint pos)
	{
		ListNode<TYPE>* tmp = start;

		for (uint i = 0; i <= pos; i++)
		{
			tmp = tmp->next;
		}
		return tmp;
	}

private:
	ListNode<TYPE>* start = NULL;

	
};

#endif
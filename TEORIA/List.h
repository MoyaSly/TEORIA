
#ifndef __LIST__
#define __LIST__
#include "Defs.h"

template <class TYPE>
struct ListNode
{
private:

	ListNode<TYPE>* next = NULL;
	ListNode<TYPE>* prev = NULL;

public:

	friend List;
	TYPE data = NULL;

	ListNode(const TYPE& data) : data(data){}

	void SetNext(ListNode<TYPE>* next)
	{
		this->next = next;
	}

	void SetPrev(ListNode<TYPE>* prev)
	{
		this->prev = prev;
	}
};

template <class TYPE>
class List
{
public:
	List(){};
	~List(){ Clear();};

	void SetStart(ListNode<TYPE>* start){this->start = start;}
	void SetEnd(ListNode<TYPE>* end)
	{
		ListNode<TYPE>* tmp = start;
		while (tmp->SetNext() != NULL)
		{
			tmp = tmp->SetNext();
		}
		tmp->GetNext() = end;
		tmp->SetNext()->GetPrev(tmp);
	}

	ListNode<TYPE>* GetStart(){return start;}

	ListNode<TYPE>* GetEnd()
	{
		ListNode<TYPE>* tmp = start;
		while (tmp->SetNext() != NULL)
		{
			tmp = tmp->SetNext();
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
			tmp->GetNext(new_node);
			new_node->GetPrev(tmp);
		}
	}

	//NETEJA LA LLISTA
	void Clear()
	{
		if (start != NULL)
		{
			ListNode<TYPE>* tmp = start;
			while (tmp->SetNext() != NULL)
			{
				tmp = tmp->SetNext();
				delete tmp->SetPrev();

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
			ListNode<TYPE>* tmp = GetStart();
			new_node->GetNext(tmp);
			tmp->GetPrev(new_node);
		}

	}

	bool PopBack(TYPE& var)
	{
		if (start != NULL)
		{
			ListNode<TYPE>* tmp = SetEnd();
			tmp->prev->SetNext(NULL);
			var = tmp->data;
			delete tmp;
			return true;
		}
		return false;
	}

	bool PopFront(TYPE& var)
	{
		if (start != NULL)
		{
			ListNode<TYPE>* tmp = SetStart();
			tmp->next->SetPrev(NULL);
			var = tmp->data;
			delete tmp;
			return true;
		}
		return false;
	}

	void Insert(uint pos, const TYPE& item)
	{
		ListNode<TYPE>* tmp = start;
		ListNode<TYPE>* new_node = new ListNode<TYPE>(item);
		if (start == NULL)
			start = new_node;
		else if (pos > Size())
		{
			PushBack();
		}
		else
		{
			for (uint i = 0; i <= pos; i++)
			{
				tmp = tmp->next;
			}
			new_node->GetPrev(tmp->SetPrev());
			new_node->GetNext(tmp->SetNext());
			tmp->GetNext(new_node->SetNext());
			tmp->GetPrev(new_node);
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
		
			for (uint i = 0; i < pos; i++)
			{
				tmp = tmp->next;
			}
			tmp->SetPrev()->GetNext(tmp);
			tmp->SetPrev()->GetPrev(tmp->SetPrev()->SetPrev());
			tmp->SetNext()->GetPrev(tmp);
			tmp->SetNext()->GetNext(tmp->SetNext()->SetNext());
			delete tmp;
		}
	}

private:
	ListNode<TYPE>* start = NULL;

	
};

#endif
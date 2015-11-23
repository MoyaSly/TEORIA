
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

	TYPE data = NULL;

	ListNode(const TYPE& data) : data(data){}

	ListNode<TYPE>* SetNext()
	{
		return next;
	}

	ListNode<TYPE>* SetPrev()
	{
		return prev;
	}

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

	void GetStart(ListNode<TYPE>* start){this->start = start;}
	void GetEnd(ListNode<TYPE>* end)
	{
		ListNode<TYPE>* tmp = start;
		while (tmp->SetNext() != NULL)
		{
			tmp = tmp->SetNext();
		}
		tmp->GetNext() = end;
		tmp->SetNext()->GetPrev(tmp);
	}

	ListNode<TYPE>* SetStart()
	{
		return start;
	}

	ListNode<TYPE>* SetEnd()
	{
		ListNode<TYPE>* tmp = start;
		while (tmp->SetNext() != NULL)
		{
			tmp = tmp->SetNext();
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

	TYPE& PopBack()
	{
		ListNode<TYPE>* tmp = SetEnd();
		tmp->SetPrev()->GetNext(tmp->SetPrev());
		delete tmp;
		return tmp->data;

	}

	TYPE& PopFront()
	{
		ListNode<TYPE>* tmp = SetStart();
		tmp->SetNext()->GetPrev(start);
		delete tmp;
		return tmp->data;
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
#ifndef __STACKLIST__
#define __STACKLIST__

#include "List.h"
#include "Defs.h"

template <class TYPE>
class StackList
{
private:
	List<TYPE> list;
public:
	StackList(){ };

	void Push(const TYPE& item)
	{
		list.PushFront(item);
	}

	bool Pop(TYPE& var)
	{
		return list.PopFront(var);
	}

	bool Peek(TYPE& var) const
	{
		if (list.GetStart() != NULL)
		{
			var = list.GetStart()->data;
			return true;
		}
		return false;
	}
};

#endif
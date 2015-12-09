#ifndef __GRAPH__
#define __GRAPH__

#include "List.h"
#include "Defs.h"

template <class TYPE>
class Graph
{
private:
	struct node
	{
		TYPE data;
		List<node*> links;

		void PushLink(node* link)
		{
			links.PushBack(link);
		}
		bool PopLink(int pos)
		{
			if (pos = > links.Size())
			{
				links.Remove(pos);
				return true;
			}
			return false;
		}
	};

	List<node*> nodes;

public:

	void AddNode(TYPE& data)
	{

	}
	bool Goto(node* start, node* end)
	{

	}

};

#endif
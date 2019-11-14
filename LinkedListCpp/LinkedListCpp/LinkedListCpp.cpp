#include <iostream>
#include "LinkedList.h"

int main()
{
	LinkedList<int> linkedList;
	linkedList.AddFirst(3);
	linkedList.AddFirst(2);
	linkedList.AddFirst(1);
	linkedList.AddLast(4);
	linkedList.AddLast(5);

	linkedList.Remove(1);
	linkedList.Remove(5);
	linkedList.Remove(3);
	;

}
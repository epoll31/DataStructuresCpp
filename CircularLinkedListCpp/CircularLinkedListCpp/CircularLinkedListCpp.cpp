#include <iostream>
#include "LinkedList.h"

int main()
{
	LinkedList<int> ll;

	ll.AddFirst(2);
	ll.AddFirst(1);
	ll.AddLast(5);
	ll.AddLast(6);
	ll.AddBefore(ll.Find(5), 3);
	ll.AddAfter(ll.Find(3), 4);

	Node<int>* currentNode = ll.Start.get();

	do
	{
		std::cout << currentNode->Value << " ";
		currentNode = currentNode->Next.get();
	} while (currentNode != ll.Start.get());

	std::cout << std::endl;

}
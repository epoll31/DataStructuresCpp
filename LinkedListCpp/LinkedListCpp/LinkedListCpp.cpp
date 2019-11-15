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
	linkedList.AddAfter(linkedList.Start.get()->Next.get()->Next.get(), 6);

	std::cout << "Count: " << linkedList.Count << std::endl;
	
	Node<int>* currentNode = linkedList.Start.get();

	while (currentNode != nullptr)
	{
		std::cout << currentNode->Value << " ";
		currentNode = currentNode->Next.get();
	}
	std::cout << std::endl << std::endl;

	currentNode = linkedList.End;

	while (currentNode != nullptr)
	{
		std::cout << currentNode->Value << " ";
		currentNode = currentNode->Previous;
	}
	std::cout << std::endl;
	

	linkedList.Remove(1);
	linkedList.Remove(5);
	linkedList.Remove(3);
	;

}
#pragma once
#include <iostream>
#include "Node.h"

template <typename T>
class LinkedList
{
public:
	std::unique_ptr<Node<T>> Start;
	Node<T>* End;
	int Count;

	LinkedList();
	~LinkedList();

	void AddFirst(T value);
	void AddLast(T value);
	void Remove(T value);
	void RemoveFirst();
	void RemoveLast();
};

#include "LinkedList.tpp"

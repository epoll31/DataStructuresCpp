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
	void AddBefore(Node<T>* node, T value);
	void AddAfter(Node<T>* node, T value);
	void Remove(T value);
	void RemoveFirst();
	void RemoveLast();

	Node<T>* Find(T value);
	bool Contains(T value);
};

#include "LinkedList.tpp"

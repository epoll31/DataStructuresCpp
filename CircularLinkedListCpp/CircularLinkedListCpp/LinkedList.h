#pragma once
#include <iostream>
#include "Node.h"

template <typename T>
class LinkedList
{
public:
	std::shared_ptr<Node<T>> Start;
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

private:
	void Remove(Node<T>* nodeToDelete);
};

#include "LinkedList.tpp"
#pragma once
#include <iostream>

template <typename T>
class Node
{
public:
	T Value;

	std::unique_ptr<Node<T>> Next;
	Node<T>* Previous;

	Node();
	Node(T value);
	~Node();
};

#include "Node.tpp"

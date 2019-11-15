#pragma once
#include <iostream>

template <typename T>
class Node
{
public:
	T Value;

	std::shared_ptr<Node<T>> Next;
	std::weak_ptr<Node<T>> Previous;

	Node(T value);
	~Node();
};

#include "Node.tpp"
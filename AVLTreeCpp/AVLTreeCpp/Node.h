#pragma once
#include <iostream>

template<typename T>
class Node
{
public:
	T Value;
	std::unique_ptr<Node<T>> Left;
	std::unique_ptr<Node<T>> Right;
	Node<T>* Parent;

	Node(T value);
	~Node();

	bool IsLeftChild();
	int GetHeight();
	int GetBalance();
};

#include "Node.tpp"
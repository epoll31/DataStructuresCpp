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
};

#include "LinkedList.tpp"
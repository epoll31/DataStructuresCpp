#pragma once
#include <iostream>
#include "Node.h"

template <typename T>
class BinarySearchTree
{
public:
	int Count;
	std::unique_ptr<Node<T>> Head;

	BinarySearchTree();
	~BinarySearchTree();

	void Add(T value);
	void Remove(T value);
	Node<T>* Find(T value);
	bool Contains(T value);
};

#include "BinarySearchTree.tpp"
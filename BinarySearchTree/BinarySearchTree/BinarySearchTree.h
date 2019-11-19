#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
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

	std::vector<Node<T>*> DepthFirstTraversalPreOrder();
	std::vector<Node<T>*> DepthFirstTraversalInOrder();
	std::vector<Node<T>*> DepthFirstTraversalPostOrder();
	std::vector<Node<T>*> BreadthFirstTraversal();

private:
	void Remove(Node<T>* nodeToRemove);
};

#include "BinarySearchTree.tpp"
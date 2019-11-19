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

	std::vector<Node<T>*> DepthFirstSearchPreOrder();
	std::vector<Node<T>*> DepthFirstSearchInOrder();
	std::vector<Node<T>*> DepthFirstSearchPostOrder();
	std::vector<Node<T>*> BreadthFirstSearch();

private:
	void Remove(Node<T>* nodeToRemove);
};

#include "BinarySearchTree.tpp"
#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include "Node.h"

template <typename T>
class AVLTree
{
public:
	int Count;
	std::unique_ptr<Node<T>> Head;

	AVLTree();
	~AVLTree();

	void Add(T value);
	void Remove(T value);
	Node<T>* Find(T value);
	bool Contains(T value);

	std::vector<Node<T>*> DepthFirstTraversalPreOrder();
	std::vector<Node<T>*> DepthFirstTraversalInOrder();
	std::vector<Node<T>*> DepthFirstTraversalPostOrder();
	std::vector<Node<T>*> BreadthFirstTraversal();

	Node<T>* RotateRight(Node<T>* nodeToRotate);
	Node<T>* RotateLeft(Node<T>* nodeToRotate);
	Node<T>* DoubleRotateRight(Node<T>* nodeToRotate);
	Node<T>* DoubleRotateLeft(Node<T>* nodeToRotate);

private:
	void Remove(Node<T>* nodeToRemove);
	void Balance(Node<T>* startNode);
};

#include "AVLTree.tpp"

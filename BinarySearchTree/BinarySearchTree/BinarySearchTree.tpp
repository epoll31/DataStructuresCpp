#pragma once

template <typename T>
BinarySearchTree<T>::BinarySearchTree()
{
	Count = 0;
}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree()
{

}

template <typename T>
void BinarySearchTree<T>::Add(T value)
{
	if (Head == nullptr)
	{
		Head = std::make_unique<Node<T>>(value);
		Count++;
		return;
	}
	
	Node<T>* traversalNode = Head.get();

	while (true)
	{
		if (value < traversalNode->Value)
		{
			if (traversalNode->Left == nullptr)
			{
				traversalNode->Left = std::make_unique<Node<T>>(value);
				traversalNode->Left.get()->Parent = traversalNode;
				Count++;
				return;
			}
			else
			{
				traversalNode = traversalNode->Left.get();
			}
		}
		else if (value > traversalNode->Value)
		{
			if (traversalNode->Right == nullptr)
			{
				traversalNode->Right = std::make_unique<Node<T>>(value);
				traversalNode->Right.get()->Parent = traversalNode;

				Count++;
				return;
			}
			else
			{
				traversalNode = traversalNode->Right.get();
			}
		}
		else
		{
			traversalNode->Count++;
			Count++;
			return;
		}
	}
}

template <typename T>
void BinarySearchTree<T>::Remove(T value)
{

}

template <typename T>
Node<T>* BinarySearchTree<T>::Find(T value)
{

} 

template <typename T>
bool BinarySearchTree<T>::Contains(T value)
{

}
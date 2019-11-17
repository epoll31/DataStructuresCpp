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

	while (traversalNode != nullptr)
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
	Remove(Find(value));
}

template <typename T>
void BinarySearchTree<T>::Remove(Node<T>* nodeToRemove)
{
	nodeToRemove->Count--;
	Count--;
	if (nodeToRemove->Count > 0)
	{
		return;
	}

	if (nodeToRemove->Left == nullptr && nodeToRemove->Right == nullptr)//no children
	{
		if (nodeToRemove->Parent == nullptr)
		{
			Head = nullptr;
		}
		else
		{
			if (nodeToRemove->IsLeftChild())
			{
				nodeToRemove->Parent->Left.release();
			}
			else
			{
				nodeToRemove->Parent->Right.release();
			}
		}
	}
	else if (nodeToRemove->Left != nullptr && nodeToRemove->Right == nullptr)//left child
	{
		nodeToRemove->Left.get()->Parent = nodeToRemove->Parent;
		if (nodeToRemove->Parent == nullptr)
		{
			Head = std::move(nodeToRemove->Left);
		}
		else
		{
			if (nodeToRemove->IsLeftChild())
			{
				nodeToRemove->Parent->Left = std::move(nodeToRemove->Left);
			}
			else
			{
				nodeToRemove->Parent->Right = std::move(nodeToRemove->Left);
			}
		}
	}
	else if (nodeToRemove->Left == nullptr && nodeToRemove->Right != nullptr)//right child
	{
		nodeToRemove->Right.get()->Parent = nodeToRemove->Parent;
		if (nodeToRemove->Parent == nullptr)
		{
			Head = std::move(nodeToRemove->Right);
		}
		else
		{
			if (nodeToRemove->IsLeftChild())
			{
				nodeToRemove->Parent->Left = std::move(nodeToRemove->Right);
			}
			else
			{
				nodeToRemove->Parent->Right = std::move(nodeToRemove->Right);
			}
		}
	}
	else//both children
	{
		Node<T>* replacementNode = nodeToRemove->Left.get();
		while (replacementNode->Right != nullptr)
		{
			replacementNode = replacementNode->Right.get();
		}

		nodeToRemove->Value = replacementNode->Value;
		Remove(replacementNode);
	}
}

template <typename T>
Node<T>* BinarySearchTree<T>::Find(T value)
{
	Node<T>* traversalNode = Head.get();
	while (traversalNode != nullptr)
	{
		if (value < traversalNode->Value)
		{
			traversalNode = traversalNode->Left.get();
		}
		else if (value > traversalNode->Value)
		{
			traversalNode = traversalNode->Right.get();
		}
		else
		{
			return traversalNode;
		}
	}

	return nullptr;
}

template <typename T>
bool BinarySearchTree<T>::Contains(T value)
{
	Node<T>* traversalNode = Head.get();
	while (traversalNode != nullptr)
	{
		if (traversalNode->Value < value)
		{
			traversalNode = traversalNode->Left;
		}
		else if (traversalNode->Value > value)
		{
			traversalNode = traversalNode->Right;
		}
		else
		{
			return true;
		}
	}

	return false;
}
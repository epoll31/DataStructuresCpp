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

template <typename T>
std::vector<Node<T>*> BinarySearchTree<T>::DepthFirstTraversalPreOrder()
{
	std::stack<Node<T>*> stack;
	std::vector<Node<T>*> returnList;

	stack.push(Head.get());

	while (stack.size() > 0)
	{
		Node<T>* currentNode = stack.top();
		stack.pop();

		returnList.push_back(currentNode);

		if (currentNode->Right != nullptr)
		{
			stack.push(currentNode->Right.get());
		}
		if (currentNode->Left != nullptr)
		{
			stack.push(currentNode->Left.get());
		}
	}

	return returnList;
}

template <typename T>
std::vector<Node<T>*> BinarySearchTree<T>::DepthFirstTraversalInOrder()
{
	auto Contains = [](std::vector<Node<T>*> & list, Node<T> * value)-> bool
	{
		for (auto item = list.begin(); item < list.end(); item++)
		{
			Node<T>* node = (*item);
			if (node == value)
			{
				return true;
			}
		}
		return false;
	};

	std::stack<Node<T>*> stack;
	std::vector<Node<T>*> returnList;

	stack.push(Head.get());

	while (stack.size() > 0)
	{
		Node<T>* currentNode = stack.top();
		stack.pop();

		while (currentNode->Left != nullptr && !Contains(returnList, currentNode->Left.get()))
		{
			currentNode = currentNode->Left.get();
		}

		if (!Contains(returnList, currentNode))
		{
			returnList.push_back(currentNode);
		}
		if (!Contains(returnList, currentNode->Parent) && currentNode->Parent != nullptr)
		{
			stack.push(currentNode->Parent);
		}
		if (!Contains(returnList, currentNode->Right.get()) && currentNode->Right != nullptr)
		{
			stack.push(currentNode->Right.get());
		}
	}


	return returnList;
}

template <typename T>
std::vector<Node<T>*> BinarySearchTree<T>::DepthFirstTraversalPostOrder()
{
	std::stack<Node<T>*> stack;
	std::vector<Node<T>*> inputList;

	stack.push(Head.get());

	while (stack.size() > 0)
	{
		Node<T>* currentNode = stack.top();
		stack.pop();

		inputList.push_back(currentNode);

		if (currentNode->Left != nullptr)
		{
			stack.push(currentNode->Left.get());
		}
		if (currentNode->Right != nullptr)
		{
			stack.push(currentNode->Right.get());
		}
	}

	std::vector<Node<T>*> outputList;
	for (auto item = inputList.end()-1; item >= inputList.begin(); item--)
	{
		outputList.push_back(*item);

		if (item == inputList.begin())
		{
			break;
		}
	}

	return outputList;
}

template <typename T>
std::vector<Node<T>*> BinarySearchTree<T>::BreadthFirstTraversal()
{
	std::queue<Node<T>*> queue;
	std::vector<Node<T>*> returnList;

	queue.push(Head.get());

	while (queue.size() > 0)
	{
		Node<T>* currentNode = queue.front();
		queue.pop();

		returnList.push_back(currentNode);

		if (currentNode->Left != nullptr)
		{
			queue.push(currentNode->Left.get());
		}
		if (currentNode->Right != nullptr)
		{
			queue.push(currentNode->Right.get());
		}
	}

	return returnList;
}
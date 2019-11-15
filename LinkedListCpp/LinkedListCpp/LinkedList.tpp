#pragma once


template<typename T>
LinkedList<T>::LinkedList()
{
	Count = 0;
	Start = nullptr;
	End = nullptr;
}

template<typename T>
LinkedList<T>::~LinkedList()
{
}



template<typename T>
void LinkedList<T>::AddFirst(T value)
{
	if (Count == 0)
	{
		Start = std::make_unique<Node<T>>(value);
		Start.get()->Next = nullptr;
		Start.get()->Previous = nullptr;
		End = Start.get();

		Count++;
		return;
	}

	std::unique_ptr<Node<T>> newNode = std::make_unique<Node<T>>(value);
	newNode.get()->Next = std::move(Start);
	newNode.get()->Previous = nullptr;
	newNode.get()->Next.get()->Previous = newNode.get();
	Start = std::move(newNode);

	Count++;
}

template<typename T>
void LinkedList<T>::AddLast(T value)
{
	if (Count == 0)
	{
		Start = std::make_unique<Node<T>>(value);
		Start.get()->Next = nullptr;
		Start.get()->Previous = nullptr;
		End = Start.get();

		Count++;
		return;
	}


	End->Next = std::make_unique<Node<T>>(value);
	End->Next.get()->Previous = End;
	End = End->Next.get();

	Count++;
}

template<typename T>
void LinkedList<T>::AddBefore(Node<T>* node, T value)
{
	if (node == Start.get())
	{
		AddFirst(value);
		return;
	}

	std::unique_ptr<Node<T>> newNode = std::make_unique<Node<T>>(value);
	newNode.get()->Previous = node->Previous;
	newNode.get()->Next = std::move(node->Previous->Next);
	node->Previous->Next = std::move(newNode);
	node->Previous = node->Previous->Next.get();

	Count++;
}
template<typename T>
void LinkedList<T>::AddAfter(Node<T>* node, T value)
{
	if (node == End)
	{
		AddLast(value);
		return;
	}

	std::unique_ptr<Node<T>> newNode = std::make_unique<Node<T>>(value);
	node->Next.get()->Previous = newNode.get();
	newNode.get()->Next = std::move(node->Next);
	newNode.get()->Previous = node;
	node->Next = std::move(newNode);

	Count++;
}

template<typename T>
void LinkedList<T>::Remove(T value)
{
	Node<T>* currentNode = Start.get();
	while (currentNode != nullptr)
	{
		if (currentNode->Value == value)
		{
			if (currentNode == Start.get())
			{
				RemoveFirst();
				return;
			}
			else if (currentNode == End)
			{
				RemoveLast();
				return;
			}
			else
			{
				currentNode->Next.get()->Previous = currentNode->Previous;
				currentNode->Previous->Next = std::move(currentNode->Next);
				Count--;
				return;
			}
		}

		currentNode = currentNode->Next.get();
	}
}

template<typename T>
void LinkedList<T>::RemoveFirst()
{
	Start = std::move(Start.get()->Next);
	Start.get()->Previous = nullptr;
	Count--;
}

template<typename T>
void LinkedList<T>::RemoveLast()
{
	End = End->Previous;
	End->Next = nullptr;
	Count--;
}

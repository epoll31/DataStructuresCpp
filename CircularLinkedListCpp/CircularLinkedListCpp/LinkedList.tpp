#pragma once

template <typename T>
LinkedList<T>::LinkedList() 
{
	Count = 0;
}

template <typename T>
LinkedList<T>::~LinkedList()
{

}
template<typename T>
void LinkedList<T>::AddFirst(T value)
{
	if (Count == 0)
	{
		Start = std::make_shared<Node<T>>(value);
		Start.get()->Next = Start;
		Start.get()->Previous = Start;

		Count++;
		return;
	}

	std::shared_ptr<Node<T>> newNode = std::make_shared<Node<T>>(value);
	newNode.get()->Next = Start;
	newNode.get()->Previous = Start.get()->Previous;
	Start.get()->Previous.lock()->Next = newNode;
	Start.get()->Previous = newNode;
	Start = newNode;
	Count++;
}

template<typename T>
void LinkedList<T>::AddLast(T value)
{
	if (Count == 0)
	{
		Start = std::make_shared<Node<T>>(value);
		Start.get()->Next = Start;
		Start.get()->Previous = Start;

		Count++;
		return;
	}

	std::shared_ptr<Node<T>> newNode = std::make_shared<Node<T>>(value);
	newNode.get()->Previous = Start.get()->Previous;
	newNode.get()->Next = Start;
	Start.get()->Previous.lock()->Next = newNode;
	Start.get()->Previous = newNode;

	Count++;
}

template<typename T>
void LinkedList<T>::AddBefore(Node<T>* node, T value)
{
	std::shared_ptr<Node<T>> newNode = std::make_shared<Node<T>>(value);
	newNode.get()->Next = node->Previous.lock().get()->Next;
	newNode.get()->Previous = node->Previous;
	node->Previous.lock()->Next = newNode;
	node->Previous = newNode;
	
	Count++;
}

template<typename T>
void LinkedList<T>::AddAfter(Node<T>* node, T value)
{
	AddBefore(node->Next.get(), value);
}

template<typename T>
void LinkedList<T>::Remove(T value)
{
	Remove(Find(value));
}

template<typename T>
void LinkedList<T>::Remove(Node<T>* nodeToDelete)
{
	if (Count == 1)
	{
		Start == nullptr;
	}

	nodeToDelete->Next.get()->Previous = nodeToDelete->Previous;
	nodeToDelete->Previous.lock().get()->Next = nodeToDelete->Next;

	if (nodeToDelete == Start.get())
	{
		Start = nodeToDelete->Next;
	}
	Count--;
}


template<typename T>
void LinkedList<T>::RemoveFirst()
{
	Remove(Start.get());
}

template<typename T>
void LinkedList<T>::RemoveLast()
{
	Remove(Start.get()->Previous.lock().get());
}

template<typename T>
Node<T>* LinkedList<T>::Find(T value)
{
	Node<T>* currentNode = Start.get();
	do
	{
		if (currentNode->Value == value) {
			return currentNode;
		}

		currentNode = currentNode->Next.get();
	} while (currentNode != Start.get());

	return nullptr;
}

template <typename T>
bool LinkedList<T>::Contains(T value)
{
	Node<T>* currentNode = Start.get();
	do
	{
		if (currentNode->Value == value) {
			return true;
		}

		currentNode = currentNode->Next.get();
	} while (currentNode != Start.get());

	return false;
}
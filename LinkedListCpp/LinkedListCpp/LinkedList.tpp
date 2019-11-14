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
	End = End.get()->Next.get();

	Count++;
}

template<typename T>
void LinkedList<T>::Remove(T value)
{
}

template<typename T>
void LinkedList<T>::RemoveFirst()
{
}

template<typename T>
void LinkedList<T>::RemoveLast()
{
}

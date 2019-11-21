#include "Node.h"
#pragma once

template <typename T>
Node<T>::Node(T value)
{
	Value = value;
	Parent = nullptr;
}

template <typename T>
Node<T>::~Node()
{

}

template <typename T>
bool Node<T>::IsLeftChild()
{
	return this == Parent->Left.get();
}

template<typename T>
int Node<T>::GetHeight()
{
	int left = 0;
	int right = 0;
	if (Left != nullptr)
	{
		left = Left.get()->GetHeight();
	}
	if (Right != nullptr)
	{
		right = Right.get()->GetHeight();
	}
	if (right < left)
	{
		return left + 1;
	}
	else
	{
		return right + 1;
	}
}

template<typename T>
int Node<T>::GetBalance()
{
	if (Left == nullptr && Right == nullptr)
	{
		return 0;
	}
	else if (Left == nullptr && Right != nullptr)
	{
		return Right.get()->GetHeight();
	}
	else if (Left != nullptr && Right == nullptr)
	{
		return -Left.get()->GetHeight();
	}
	else
	{
		return Right.get()->GetHeight() - Left.get()->GetHeight();
	}
}

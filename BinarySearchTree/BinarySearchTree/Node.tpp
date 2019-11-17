#pragma once

template <typename T>
Node<T>::Node(T value)
{
	Value = value;
	Count = 1;
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
#pragma once

template <typename T>
Node<T>::Node(T value)
{
	Value = value;
	Next = nullptr;
	Previous = nullptr;
}

template <typename T>
Node<T>::~Node()
{

}

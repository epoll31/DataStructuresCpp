#pragma once

template <typename T>
Node<T>::Node(T value)
{
	Value = value;
	Count = 1;
}

template <typename T>
Node<T>::~Node()
{

}
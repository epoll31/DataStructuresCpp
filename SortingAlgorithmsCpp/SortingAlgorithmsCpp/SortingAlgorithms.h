#pragma once
#include <iostream>
#include <vector>

namespace SortingAlgorithms
{
	template <typename T>
	std::vector<T> BubbleSort(std::vector<T> data)
	{
		int amountLess = 1;
		for (auto i = data.begin(); i < data.end(); i++)
		{
			for (auto j = data.begin(); j < data.end() - amountLess; j++)
			{
				if (*j > * (j + 1))
				{
					T temp = *(j + 1);
					*(j + 1) = *j;
					*j = temp;
				}
			}
			amountLess++;
		}

		return data;
	}

	template <typename T>
	std::vector<T> SelectionSort(std::vector<T> data)
	{
		for (auto i = data.begin(); i < data.end() - 1; i++)
		{
			auto min = i;
			for (auto j = i + 1; j < data.end(); j++)
			{
				if (*j < *min)
				{
					min = j;
				}
			}

			T temp = *i;
			*i = *min;
			*min = temp;
		}

		return data;
	}

	template <typename T>
	std::vector<T> InsertionSort(std::vector<T> data)
	{
		for (auto i = data.begin() + 1; i < data.end(); i++)
		{
			for (auto j = i; j > data.begin(); j--)
			{
				if (*j < *(j-1)) {

					T temp = *(j - 1);
					*(j - 1) = *j;
					*j = temp;
				}
				else
				{
					break;
				}
			}
		}

		return data;
	}
}
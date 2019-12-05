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
}
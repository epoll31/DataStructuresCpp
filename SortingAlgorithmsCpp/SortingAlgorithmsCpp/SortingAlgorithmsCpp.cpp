#include <iostream>
#include "SortingAlgorithms.h"

int main()
{
	std::vector<int> before;
	for (int i = 0; i < 100; i++)
	{
		before.push_back(rand() % 100);
	}

	std::vector<int> after = SortingAlgorithms::SelectionSort(before);

	std::cout << "before: ";
	for (auto i = before.begin(); i < before.end(); i++)
	{
		std::cout << *i << " ";
	}

	std::cout << std::endl << std::endl << "after: ";
	for (auto i = after.begin(); i < after.end(); i++)
	{
		std::cout << *i << " ";
	}
}


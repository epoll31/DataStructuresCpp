#include <iostream>
#include "SortingAlgorithms.h"

int main()
{
	std::vector<int> before;
	before.push_back(6);
	before.push_back(5);
	before.push_back(4);
	before.push_back(3);
	before.push_back(2);
	before.push_back(1);

	std::vector<int> after = SortingAlgorithms::BubbleSort(before);

	std::cout << "before: ";
	for (auto i = before.begin(); i < before.end(); i++)
	{
		std::cout << *i << " ";
	}

	std::cout << std::endl << "after: ";
	for (auto i = after.begin(); i < after.end(); i++)
	{
		std::cout << *i << " ";
	}
}


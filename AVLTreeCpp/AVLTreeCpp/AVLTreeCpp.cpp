#include <iostream>
#include "AVLTree.h"

int main()
{
	AVLTree<int> tree;
	for (int i = 0; i < 1000; i++)
	{
		int newValue = rand() % 1000;
		if (tree.Contains(newValue))
		{
			i--;
			continue;
		}
		
		tree.Add(newValue);

	}
	
	for (int i = 0; i < 1000; i++)
	{
		int newValue = rand() % 1000;
		if (!tree.Contains(newValue))
		{
			i--;
			continue;
		}
		tree.Remove(newValue);
	}
}

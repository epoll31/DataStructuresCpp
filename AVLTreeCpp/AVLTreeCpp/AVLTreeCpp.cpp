#include <iostream>
#include "AVLTree.h"

int main()
{
	AVLTree<int> tree;
	for (int i = 15; i > 0; i--)
	{
		tree.Add(i);
	}
	;
}

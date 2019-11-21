#include <iostream>
#include "AVLTree.h"

int main()
{
	AVLTree<int> tree;
	tree.Add(5);
	tree.Add(4);
	tree.Add(3);
	tree.RotateRight(tree.Head.get());
	tree.Add(2);
	tree.Add(1);
	tree.RotateRight(tree.Head.get()->Left.get());
	;
}

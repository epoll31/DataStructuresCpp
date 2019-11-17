#include <iostream>

#include "BinarySearchTree.h"

int main()
{
	BinarySearchTree<int> tree;

	tree.Add(1);//4);
	tree.Add(2);//2);
	tree.Add(3);//6);
	tree.Add(1);//1);
	tree.Add(2);//3);
	tree.Add(3);//5);
	tree.Add(1);//7);

	tree.Remove(1);
	tree.Remove(2);
	tree.Remove(3);
	tree.Remove(3);
	tree.Remove(2);
	tree.Remove(1);
	//tree.Remove(1);

}

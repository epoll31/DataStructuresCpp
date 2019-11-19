#include <iostream>
#include "BinarySearchTree.h"
#include <vector>

int main()
{
	BinarySearchTree<int> tree;

	//tree.Add(4);
	//tree.Add(2);
	//tree.Add(6);
	//tree.Add(1);
	//tree.Add(3);
	//tree.Add(5);
	//tree.Add(7);

	tree.Add(25);
	tree.Add(15);
	tree.Add(50);
	tree.Add(10);
	tree.Add(22);
	tree.Add(35);
	tree.Add(70);
	tree.Add(4);
	tree.Add(12);
	tree.Add(18);
	tree.Add(24);
	tree.Add(31);
	tree.Add(44);
	tree.Add(66);
	tree.Add(90);

	std::vector<Node<int>*> preorder = tree.DepthFirstSearchPreOrder();
	
	for (auto i = preorder.begin(); i < preorder.end(); i++)
	{
		std::cout << (*i)->Value << " ";
	}
	std::cout << std::endl;

	std::vector<Node<int>*> inorder = tree.DepthFirstSearchInOrder();

	for (auto i = inorder.begin(); i < inorder.end(); i++)
	{
		std::cout << (*i)->Value << " ";
	}
	std::cout << std::endl;

	std::vector<Node<int>*> postorder = tree.DepthFirstSearchPostOrder();

	for (auto i = postorder.begin(); i < postorder.end(); i++)
	{
		std::cout << (*i)->Value << " ";
	}
	std::cout << std::endl;

}

#include <iostream>
#include "AVLTree.h"
#include <vector>

int main()
{
	AVLTree<int> tree;
	for (int i = 0; i < 15; i++)
	{
		int newValue = rand() % 15;
		if (tree.Contains(newValue))
		{
			i--;
			continue;
		}
		
		tree.Add(newValue);

	}

	std::vector<Node<int>*> preorder = tree.DepthFirstTraversalPreOrder();
	std::cout << "PreOrder: ";
	for (auto i = preorder.begin(); i < preorder.end(); i++)
	{
		std::cout << (*i)->Value;
		if (i != preorder.end() - 1)
		{
			std::cout << " ";
		}
	}
	std::cout << std::endl;

	std::vector<Node<int>*> inorder = tree.DepthFirstTraversalInOrder();
	std::cout << "InOrder: ";
	for (auto i = inorder.begin(); i < inorder.end(); i++)
	{
		std::cout << (*i)->Value;
		if (i != inorder.end() - 1)
		{
			std::cout << " ";
		}
	}
	std::cout << std::endl;

	std::vector<Node<int>*> postorder = tree.DepthFirstTraversalPostOrder();
	std::cout << "PostOrder: ";
	for (auto i = postorder.begin(); i < postorder.end(); i++)
	{
		std::cout << (*i)->Value;
		if (i != postorder.end() - 1)
		{
			std::cout << " ";
		}
	}
	std::cout << std::endl;

	std::vector<Node<int>*> breadthfirst = tree.BreadthFirstTraversal();
	std::cout << "BreadthFirst: ";
	for (auto i = breadthfirst.begin(); i < breadthfirst.end(); i++)
	{
		std::cout << (*i)->Value;
		if (i != breadthfirst.end() - 1)
		{
			std::cout << " ";
		}
	}
	std::cout << std::endl;


	for (int i = 0; i < 15; i++)
	{
		int newValue = rand() % 15;
		if (!tree.Contains(newValue))
		{
			i--;
			continue;
		}
		tree.Remove(newValue);
	}

}

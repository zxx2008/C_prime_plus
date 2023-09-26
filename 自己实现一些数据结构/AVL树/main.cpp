#include "AVLTree.h"
#include "AVLTree.cpp"
#include <iostream>
int main() {
	//AVLTreeNode<int> tree = AVLTreeNode<int>(4);
	//std::cout << tree.mKey << std::endl;

	AVLTree<int>* tree = new AVLTree<int>(10);
	AVLTreeNode<int>* Root = tree->getRoot();
	tree->Insert(Root, 9);
	tree->Insert(Root, 10);
	tree->Insert(Root, 11);
	tree->PreOrder(Root);
}
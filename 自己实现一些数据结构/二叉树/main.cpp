#include "BinaryTree.h"

int main() {
	BinaryTree<int>* tree = new BinaryTree<int>(9);
	tree->Insert(tree->getRoot(), 8, true);
	tree->Insert(tree->getRoot(), 10, false);
	tree->PreOrder(tree->getRoot());
}
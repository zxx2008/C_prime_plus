# include "AVLTree.h"
# include <iostream>
int main() {
	AVLTreeNode<int> tree = AVLTreeNode<int>(4);
	std::cout << tree.mKey << std::endl;
}
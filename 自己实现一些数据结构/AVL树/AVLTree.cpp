#include "AVLTree.h"
#include <algorithm>

template <class T>
AVLTree<T>::AVLTree(T key) {
	root = new AVLTreeNode<T>(key);
}

template <class T>
AVLTreeNode<T>* AVLTree<T>::Insert(AVLTreeNode<T>*& node, T key) {
	if (node == nullptr) {
		node = new AVLTreeNode<T>(key);
	}
	else if (key < node->mKey) {
		node->mLeftChildren = Insert(node->mLeftChildren, key);
	}
}

/*
          k1                 k2
		 /  \				/  \
		k2   w		       x    k1
       /  \       -->     /    / \
	  x    y             z    y   w
     /
	z
*/

template <class T>
AVLTreeNode<T>* AVLTree<T>::leftLeftRotation(AVLTreeNode<T>*& k1) {
	AVLTreeNode<T>* k2 = k1->mLeftChildren;
	k1->mLeftChildren = k2->mRightChildren;
	k2->mRightChildren = k1;
	k1->mHeight = std::max();
}
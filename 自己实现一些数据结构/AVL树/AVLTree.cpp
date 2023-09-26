#include "AVLTree.h"
#include <algorithm>
#include <iostream>

template <class T>
AVLTree<T>::AVLTree(T key) {
	root = new AVLTreeNode<T>(key);
}

template <class T>
AVLTreeNode<T>* AVLTree<T>::Insert(AVLTreeNode<T>*& node, T key) {
	if (node == nullptr) {
		node = new AVLTreeNode<T>(key);
	}
	else if (key < node->mKey) {   //插入node 左子树的情况
		node->mLeftChildren = Insert(node->mLeftChildren, key);
		if (node->mLeftChildren - node->mRightChildren == 2) {
			if (key < node->mLeftChildren->mKey) {
				node = leftLeftRotation(node);
			}
			else {
				node = leftRightRotation(node);
			}
		}
	}
	else if (key > node->mKey) {   //插入node 右子树的情况
		node->mRightChildren = Insert(node->mRightChildren, key);
		if (node->mRightChildren - node->mLeftChildren == 2) {
			if (key < node->mRightChildren->mKey) {
				node = rightLeftRotation(node);
			}
			else {
				node = rightRightRotation(node);
			}
		}
	}
	else {
		std::cout << "添加失败，不能添加相同的点" << std::endl;
	}
	node->mHeight = std::max(height(node->mLeftChildren), height(node->mRightChildren)) + 1;
	return node;
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
	k1->mHeight = std::max(height(k1->mLeftChildren), height(k1->mRightChildren)) + 1;
	k2->mHeight = std::max(height(k2->mLeftChildren), k1->mHeight) + 1;
	return k2;
}


template <class T>
AVLTreeNode<T>* AVLTree<T>::rightRightRotation(AVLTreeNode<T>*& k1) {
	AVLTreeNode<T>* k2 = k1->mRightChildren;
	k1->mRightChildren = k2->mLeftChildren;
	k2->mLeftChildren = k1;
	k1->mHeight = std::max(height(k1->mLeftChildren), height(k1->mLeftChildren)) + 1;
	k2->mHeight = std::max(height(k2->mRightChildren), k1->mHeight) + 1;
	return k2;
}

/*
         k1                     k1                   k3
		/  \                   /  \                 /  \
	   k2   w                 k3   w               k2   k1
	  /  \        -->        /  \        -->      /    /  \
	 x    k3                k2   z               x    z    w
           \	           /
		    z             x
*/

template <class T>
AVLTreeNode<T>* AVLTree<T>::leftRightRotation(AVLTreeNode<T>*& k1) {
	AVLTreeNode<T>* k2 = k1->mLeftChildren;
	k1->mLeftChildren = rightRightRotation(k2);
	//k1 = leftLeftRotation(k1);
	return leftLeftRotation(k1);
}

template <class T>
AVLTreeNode<T>* AVLTree<T>::rightLeftRotation(AVLTreeNode<T>*& k1) {
	AVLTreeNode<T>* k2 = k1->mRightChildren;
	k1->mRightChildren = leftLeftRotation(k2);
	return rightRightRotation(k1);
}

template <class T>
int AVLTree<T>::height(AVLTreeNode<T>* node) {
	return node != nullptr ? node->mHeight : 0;
}

template <class T>
void AVLTree<T>::PreOrder(AVLTreeNode<T>* node) {
	if (node != nullptr) {
		std::cout << node->mKey << std::endl;
		PreOrder(node->mLeftChildren);
		PreOrder(node->mRightChildren);
	}
}

//template <class T>

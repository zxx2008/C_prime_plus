#include "BinaryTree.h"

template <class T>
BinaryTree<T>::BinaryTree() {
	root = new BinaryTreeNode();
}

template <class T>
BinaryTree<T>::~BinaryTree() {
	destroy(root);
}

template <class T>
void BinaryTree<T>::destroy(BinaryTreeNode<T>* cur) {
	if (cur != nullptr) {
		destroy(cur->leftChildren);
		destroy(cur->rightChildren);
		delete cur;
	}
}

template <class T>
BinaryTree<T>::BinaryTree(T val) {
	root = new BinaryTreeNode<T>(val);
}

template <class T>
BinaryTreeNode<T>* BinaryTree<T>::getLeftChildren(BinaryTreeNode<T>* cur) {
	return cur->leftChildren;

}
template <class T>
BinaryTreeNode<T>* BinaryTree<T>::getRightChildren(BinaryTreeNode<T>* cur) {
	return cur->rightChildren;
}

template <class T>
void BinaryTree<T>::PreOrder(BinaryTreeNode<T>* cur) {
	if (cur != nullptr) {
		std::cout << cur->data << std::endl;
		PreOrder(cur->leftChildren);
		PreOrder(cur->rightChildren);
	}
}

template <class T>
void BinaryTree<T>::InOrder(BinaryTreeNode<T>* cur) {
	if (cur != nullptr) {
		InOrder(cur->leftChildren);
		std::cout << cur->data << std::endl;
		InOrder(cur->rightChildren);
	}
}

template <class T>
void BinaryTree<T>::PostOrder(BinaryTreeNode<T>* cur) {
	if (cur != nullptr) {
		PostOrder(cur->leftChildren);
		PostOrder(cur->rightChildren);
		std::cout << cur->data << std::endl;
	}
}
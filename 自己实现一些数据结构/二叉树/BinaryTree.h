#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_


#include <iostream>

template <class T>
struct BinaryTreeNode {
	T data;
	BinaryTreeNode<T>* leftChildren;
	BinaryTreeNode<T>* rightChildren;
	BinaryTreeNode() : leftChildren(nullptr), rightChildren(nullptr){}
	BinaryTreeNode(T data, BinaryTreeNode<T>* l = nullptr, BinaryTreeNode<T>* r = nullptr) : data(data),leftChildren(l),rightChildren(r) {}
};

template <class T>
class BinaryTree {
public:
	BinaryTree();
	~BinaryTree();
	void destroy(BinaryTreeNode<T> * cur);
	BinaryTree(T val);
	bool Insert(BinaryTreeNode<T> * cur, T val, bool isLeft) { //通过isLeft判断新节点放在cur的左孩子还是右孩子
		if (isLeft) {
			if (cur->leftChildren != nullptr) {
				std::cout << "左节点已被占用" << std::endl;
				return false;
			}
			else {
				cur->leftChildren = new BinaryTreeNode<T>(val);
				return true;
			}
		}
		else if (!isLeft) {
			if (cur->rightChildren != nullptr) {
				std::cout << "右节点已被占用" << std::endl;
				return false;
			}
			else {
				cur->rightChildren = new BinaryTreeNode<T>(val);
				return true;
			}
		}
	}
	BinaryTreeNode<T>* getLeftChildren(BinaryTreeNode<T>* cur);
	BinaryTreeNode<T>* getRightChildren(BinaryTreeNode<T>* cur);
	void PreOrder(BinaryTreeNode<T>* cur);
	void PostOrder(BinaryTreeNode<T>* cur);
	void InOrder(BinaryTreeNode<T>* cur);
	BinaryTreeNode<T>* getRoot() {
		return root;
	}
private:
	struct BinaryTreeNode<T>* root;
};

#endif // !_BINARY_TREE_H_
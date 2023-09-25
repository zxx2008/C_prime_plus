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
	bool Insert(BinaryTreeNode<T> * cur, T val, bool isLeft) { //ͨ��isLeft�ж��½ڵ����cur�����ӻ����Һ���
		if (isLeft) {
			if (cur->leftChildren != nullptr) {
				std::cout << "��ڵ��ѱ�ռ��" << std::endl;
				return false;
			}
			else {
				cur->leftChildren = new BinaryTreeNode<T>(val);
				return true;
			}
		}
		else if (!isLeft) {
			if (cur->rightChildren != nullptr) {
				std::cout << "�ҽڵ��ѱ�ռ��" << std::endl;
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
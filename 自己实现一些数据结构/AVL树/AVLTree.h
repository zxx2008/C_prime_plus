#ifndef _AVL_TREE_H_
#define _AVL_TREE_H_

template <class T>
struct AVLTreeNode {
	T mKey;
	int mHeight;
	AVLTreeNode<T>* mLeftChildren;
	AVLTreeNode<T>* mRightChildren;
	AVLTreeNode(T key) : mKey(key), mHeight(1), mLeftChildren(nullptr), mRightChildren(nullptr){}
};

template <class T>
class AVLTree {
public:
	AVLTree(T key);
	~AVLTree();
	AVLTreeNode<T>* Insert(AVLTreeNode<T>*& node, T key); //���ز���ڵ㣬������תƽ���ĸ��ڵ�
	AVLTreeNode<T>* leftLeftRotation(AVLTreeNode<T> *&k1); //����ʧ�⣬��ת
	AVLTreeNode<T>* leftRightRotation(AVLTreeNode<T> *&k1); //����ʧ�⣬��ת
	AVLTreeNode<T>* rightLeftRotation(AVLTreeNode<T> *&k1); //����ʧ�⣬��ת
	AVLTreeNode<T>* rightRightRotation(AVLTreeNode<T> *&k1); //����ʧ�⣬��ת
	int height(AVLTreeNode<T>* node); //���ؽڵ�ĸ߶�
	void PreOrder(AVLTreeNode<T>* node);
	AVLTreeNode<T>* getRoot() {
		return root;
	}
private:
	AVLTreeNode<T>* root;
};
#endif // !_AVL_TREE_H_

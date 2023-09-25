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
	AVLTreeNode<T>* Insert(AVLTreeNode*& node, T key); //���ز���ڵ㣬������תƽ���ĸ��ڵ�
	AVLTreeNode<T>* leftLeftRotation(AVLTreeNode *&k1); //����ʧ�⣬��ת
	AVLTreeNode<T>* leftRightRotation(AVLTreeNode *&k1); //����ʧ�⣬��ת
	AVLTreeNode<T>* rightLeftRotation(AVLTreeNode *&k1); //����ʧ�⣬��ת
	AVLTreeNode<T>* rightRightRotation(AVLTreeNode *&k1); //����ʧ�⣬��ת
private:
	AVLTreeNode<T>* root;
};
#endif // !_AVL_TREE_H_

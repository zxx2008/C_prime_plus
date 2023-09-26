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
	AVLTreeNode<T>* Insert(AVLTreeNode<T>*& node, T key); //返回插入节点，返回旋转平衡后的根节点
	AVLTreeNode<T>* leftLeftRotation(AVLTreeNode<T> *&k1); //左左失衡，旋转
	AVLTreeNode<T>* leftRightRotation(AVLTreeNode<T> *&k1); //左右失衡，旋转
	AVLTreeNode<T>* rightLeftRotation(AVLTreeNode<T> *&k1); //右左失衡，旋转
	AVLTreeNode<T>* rightRightRotation(AVLTreeNode<T> *&k1); //右右失衡，旋转
	int height(AVLTreeNode<T>* node); //返回节点的高度
	void PreOrder(AVLTreeNode<T>* node);
	AVLTreeNode<T>* getRoot() {
		return root;
	}
private:
	AVLTreeNode<T>* root;
};
#endif // !_AVL_TREE_H_

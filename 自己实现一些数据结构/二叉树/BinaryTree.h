#pragma once

template <class T>
struct BinaryTreeNode {
	T data;
	BinaryTreeNode* leftChildren, rightChildren;
	BinaryTreeNode() : leftChildren(nullptr), rightChildren(nullptr){}
	BinaryTreeNode(T data, BinaryTreeNode* leftChildren = nullptr, BinaryTreeNode* rightChildren = nullptr) : data(data) {}
};

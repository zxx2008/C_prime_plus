#ifndef _B_TREE_H_
#define _B_TREE_H_
#include <vector>
extern const int M;
struct BTNode {
	int keynum; //�ڵ㵱ǰ�ؼ��ֵĸ���
	std::vector<int> key;
	struct BTNode* parent; //���ڵ�ָ��1
	std::vector<struct BTNode*> children; //���ӽڵ�ָ������
	BTNode(std::vector<int>& array) : keynum(0), parent(nullptr){
		key = array;
		//for (auto it =)
	}
};


#endif
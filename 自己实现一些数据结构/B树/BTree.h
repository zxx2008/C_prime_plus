#ifndef _B_TREE_H_
#define _B_TREE_H_
#include <vector>
#include <string>
//extern const int M;
struct BTNode {
	int keynum; //�ڵ㵱ǰ�ؼ��ֵĸ���
	std::vector<int> key;
	struct BTNode* parent; //���ڵ�ָ��1
	std::vector<struct BTNode*> children; //���ӽڵ�ָ������
	BTNode(std::vector<int>& array) : keynum(0), parent(nullptr){
		key = array;
		for (auto it = children.begin(); it != children.end(); ++it) {
			*it = nullptr;
		}
	}
	int search(int k) {
		int i = 0;
		while (i < keynum && k >= key[i]) ++i;
		return i;
	}

};

class BTree {
public:
	void Insert(int key, std::string val);
	void ShowBTree();
	BTree();
	~BTree();
private:
	struct BTNode* root;
};
#endif
#include "BTree.h"
#include <iostream>

BTree::BTree() {
	std::vector<int> rootArray = {};
	root = new BTNode(rootArray);
}

void BTree::Insert(int k, std::string val) {
	BTNode* cur = root;
	bool found = false;
	int i = 0;
	do {
		i = cur->search(k);
		if (k == cur->key[i]) found = true;
	} while (cur != nullptr && !found);
	if (found) {
		std::cout << "рясп" << k << std::endl;
	}
	else {
		//if ()
		cur->key.insert(cur->key.begin() + i + 1, k);
	}
}
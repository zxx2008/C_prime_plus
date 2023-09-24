#include <iostream>
#include "ArrayHashMap.h"
int main() {
	ArrayHashMap* testMap = new ArrayHashMap();
	testMap->put(12, "���");
	testMap->put(14, "�����");
	testMap->put(189, "����");
	for (const auto key : testMap->keySet()) {
		std::cout << key << std::endl;
	}
	for (const auto val : testMap->valSet()) {
		std::cout << val << std::endl;
	}
	for (const auto kv : testMap->pairSet()) {
		std::cout << kv->key << kv->val << std::endl;
	}
	std::cout << "����key=189" << std::endl;
	std::cout << testMap->get(189) << std::endl;
	testMap->remove(189);
	std::cout << testMap->get(189) << std::endl;
	testMap->~ArrayHashMap();
}
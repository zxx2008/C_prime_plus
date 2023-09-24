#include "ArrayHashMap.h"


int hashFunc(int key) { 
	int index = key % 100;
	return index;
}

ArrayHashMap::ArrayHashMap() {
	buckets = std::vector<Pair*>(100, nullptr); //初始化数组，包含100个桶
}

ArrayHashMap::~ArrayHashMap() {
	for (const auto &bucket : buckets) { //使用引用就不会调用拷贝构造函数提高效率
		//delete bucket;
		if (bucket != nullptr) {
			delete bucket;
		}
	}
	buckets.clear();
}

void ArrayHashMap::put(int key, std::string val) {
	int index = hashFunc(key);
	buckets[index] = new Pair(key, val);
}

void ArrayHashMap::remove(int key) {
	int index = hashFunc(key);
	delete buckets[index];
	buckets[index] = nullptr; //重置指针为空！很重要！！！！
}

std::string ArrayHashMap::get(int key) {
	int index = hashFunc(key);
	Pair* kv = buckets[index];
	if (kv == nullptr) {
		return "cannot find";
	}
	return kv->val;
}

std::vector<Pair *> ArrayHashMap::pairSet() {
	std::vector<Pair *> pairs;
	for (const auto& bucket : buckets) {
		//pairs.push_back(bucket);
		if (bucket != nullptr) {  
			pairs.push_back(bucket);
		}
	}
	return pairs;
}

std::vector<int> ArrayHashMap::keySet() {
	std::vector<int> keys;
	for (const auto& bucket : buckets) {
		//keys.push_back(bucket->key);
		if (bucket != nullptr) { //一定要加入if判断，不然bucket为空，根本就无法获得key程序异常中断
			keys.push_back(bucket->key);
		}
	}
	return keys;
}

std::vector<std::string> ArrayHashMap::valSet() {
	std::vector<std::string> vals;
	for (const auto& bucket : buckets) {
		//vals.push_back(bucket->val);
		if (bucket != nullptr) {
			vals.push_back(bucket->val);
		}
	}
	return vals;
}
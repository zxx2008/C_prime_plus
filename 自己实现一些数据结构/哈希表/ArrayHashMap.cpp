#include "ArrayHashMap.h"


int hashFunc(int key) { 
	int index = key % 100;
	return index;
}

ArrayHashMap::ArrayHashMap() {
	buckets = std::vector<Pair*>(100, nullptr); //��ʼ�����飬����100��Ͱ
}

ArrayHashMap::~ArrayHashMap() {
	for (const auto &bucket : buckets) { //ʹ�����þͲ�����ÿ������캯�����Ч��
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
	buckets[index] = nullptr; //����ָ��Ϊ�գ�����Ҫ��������
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
		if (bucket != nullptr) { //һ��Ҫ����if�жϣ���ȻbucketΪ�գ��������޷����key�����쳣�ж�
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
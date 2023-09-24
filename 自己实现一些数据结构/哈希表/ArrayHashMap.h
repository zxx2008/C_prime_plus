#ifndef _ARRAY_HASH_MAP_H_
#define _ARRAY_HASH_MAP_H_
#include <string>
#include <vector>

struct Pair {
	int key;
	std::string val;
	Pair(int key, std::string val): key(key), val(val) {}
};


//基于数组实现一个简易的HashMap
class ArrayHashMap {
public:
	ArrayHashMap();
	~ArrayHashMap();
	std::string get(int key);
	void put(int key, std::string val);
	void remove(int key);
	std::vector<Pair *> pairSet(); //返回所有的键值对
	std::vector<int> keySet(); //返回所有的键
	std::vector<std::string> valSet(); //返回所有的值
private:
	std::vector<Pair*> buckets;
	
};
#endif // !_ARRAY_HASH_MAP_H_
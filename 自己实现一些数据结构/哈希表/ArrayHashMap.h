#ifndef _ARRAY_HASH_MAP_H_
#define _ARRAY_HASH_MAP_H_
#include <string>
#include <vector>

struct Pair {
	int key;
	std::string val;
	Pair(int key, std::string val): key(key), val(val) {}
};


//��������ʵ��һ�����׵�HashMap
class ArrayHashMap {
public:
	ArrayHashMap();
	~ArrayHashMap();
	std::string get(int key);
	void put(int key, std::string val);
	void remove(int key);
	std::vector<Pair *> pairSet(); //�������еļ�ֵ��
	std::vector<int> keySet(); //�������еļ�
	std::vector<std::string> valSet(); //�������е�ֵ
private:
	std::vector<Pair*> buckets;
	
};
#endif // !_ARRAY_HASH_MAP_H_
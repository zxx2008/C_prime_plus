# ifndef _DOUBLE_RECTION_QUEUE_
# define _DOUBLE_RECTION_QUEUE_

struct DoubleRectionNode {
	int val;
	DoubleRectionNode* next;
	DoubleRectionNode* prev;
	DoubleRectionNode() : next(nullptr), prev(nullptr) {}
};


class DoubleRectionQueue {
public:
	DoubleRectionQueue();
	~DoubleRectionQueue();
	void putFront(int val);
	void putBack(int val);
	void put(int val, bool isFront);
	void popFront();
	void popBack();
	void pop(bool isFront);
	void getSize();
private:
	DoubleRectionNode* first;
	DoubleRectionNode* last;
	int size;
};
#endif // !_DOUBLE_RECTION_QUEUE_

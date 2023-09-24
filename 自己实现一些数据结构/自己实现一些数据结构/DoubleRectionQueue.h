# ifndef _DOUBLE_RECTION_QUEUE_
# define _DOUBLE_RECTION_QUEUE_

//双向队列节点结构体
struct DoubleRectionNode { 
	int val;
	DoubleRectionNode* next;
	DoubleRectionNode* prev;
	DoubleRectionNode(int val) : next(nullptr), prev(nullptr), val(val) {}
};

//双向队列类
class DoubleRectionQueue {
public:
	DoubleRectionQueue();
	~DoubleRectionQueue();
	void putFront(int val); //队列前方插入新元素
	void putBack(int val); //队列后方插入新元素
	void put(int val, bool isFront); //插入新元素前后方由isFront决定
	int popFront(); //队列前方pop
	int popBack();	  //队列后方pop
	int pop(bool isFront); //pop 前方后方由isFront决定
	int getSize(); //返回队列大小
	void printQueue();//遍历输出队列中所以元素的值
private:
	DoubleRectionNode* first;
	DoubleRectionNode* last;
	int size;
};
#endif // !_DOUBLE_RECTION_QUEUE_

# ifndef _DOUBLE_RECTION_QUEUE_
# define _DOUBLE_RECTION_QUEUE_

//˫����нڵ�ṹ��
struct DoubleRectionNode { 
	int val;
	DoubleRectionNode* next;
	DoubleRectionNode* prev;
	DoubleRectionNode(int val) : next(nullptr), prev(nullptr), val(val) {}
};

//˫�������
class DoubleRectionQueue {
public:
	DoubleRectionQueue();
	~DoubleRectionQueue();
	void putFront(int val); //����ǰ��������Ԫ��
	void putBack(int val); //���к󷽲�����Ԫ��
	void put(int val, bool isFront); //������Ԫ��ǰ����isFront����
	int popFront(); //����ǰ��pop
	int popBack();	  //���к�pop
	int pop(bool isFront); //pop ǰ������isFront����
	int getSize(); //���ض��д�С
	void printQueue();//�����������������Ԫ�ص�ֵ
private:
	DoubleRectionNode* first;
	DoubleRectionNode* last;
	int size;
};
#endif // !_DOUBLE_RECTION_QUEUE_

#ifndef _BOUNDED_BLOCKING_QUEUE_H_
#define _BOUNDED_BLOCKING_QUEUE_H_

#include "Task.h"
#include <queue>
#include <mutex>


//�̰߳�ȫ������������
class BoundedBlockingQueue
{
public:
	BoundedBlockingQueue() = default;
	//�ж��г������ߵĹ��캯��
	BoundedBlockingQueue(int size) : MAX_SIZE(size)
	{
		;
	}
	~BoundedBlockingQueue() = default;
	
	//���г�������
	int MAX_SIZE;
	//�������������
	void addTask(TaskPtr task);
	//������ȡ������
	TaskPtr getTask();
	//��ö���������ĸ���
	int getSize();
	//�ж϶����Ƿ�Ϊ��
	bool isEmpty();
	//���ؿ������캯��
	BoundedBlockingQueue(BoundedBlockingQueue& other);
	//���ظ�ֵ����
	BoundedBlockingQueue& operator=(const BoundedBlockingQueue& other);


private:
	std::queue<TaskPtr> m_tasks; //������б�������
	std::mutex m_mutex;
};

#endif // !_BOUNDED_BLOCKING_QUEUE_H_

#ifndef _BOUNDED_BLOCKING_QUEUE_H_
#define _BOUNDED_BLOCKING_QUEUE_H_

#include "Task.h"
#include <queue>
#include <mutex>


//线程安全有限阻塞队列
class BoundedBlockingQueue
{
public:
	BoundedBlockingQueue() = default;
	//有队列长度上线的构造函数
	BoundedBlockingQueue(int size) : MAX_SIZE(size)
	{
		;
	}
	~BoundedBlockingQueue() = default;
	
	//队列长度上限
	int MAX_SIZE;
	//队列中添加任务
	void addTask(TaskPtr task);
	//队列中取出任务
	TaskPtr getTask();
	//获得队列中任务的个数
	int getSize();
	//判断队列是否为空
	bool isEmpty();
	//重载拷贝构造函数
	BoundedBlockingQueue(BoundedBlockingQueue& other);
	//重载赋值函数
	BoundedBlockingQueue& operator=(const BoundedBlockingQueue& other);


private:
	std::queue<TaskPtr> m_tasks; //定义队列保存任务
	std::mutex m_mutex;
};

#endif // !_BOUNDED_BLOCKING_QUEUE_H_

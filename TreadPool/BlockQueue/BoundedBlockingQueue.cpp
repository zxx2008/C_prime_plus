#include "BoundedBlockingQueue.h"

std::mutex g_mutex;	//定义全局互斥锁， 用于防止打印混乱
//添加任务
void BoundedBlockingQueue::addTask(TaskPtr task)
{
	std::lock_guard<std::mutex> lock(m_mutex);
	if (m_tasks.size() >= MAX_SIZE)
	{
		//防止打印混乱添加锁
		{
			std::lock_guard<std::mutex> lock(g_mutex);
			std::cout << "队列已满" << std::endl;
		}
		return;
	}
	//防止打印混乱添加锁
	{
		std::lock_guard<std::mutex> lock(g_mutex);
		std::cout << "---add task : [" << task->getName().c_str() << "]" << std::endl;
	}
	m_tasks.push(task);
}

//取出任务
TaskPtr BoundedBlockingQueue::getTask()
{
	std::lock_guard<std::mutex> lock(m_mutex);

	if (m_tasks.empty())
		return nullptr;

	TaskPtr task = m_tasks.front();
	m_tasks.pop();

	return task;
}

//获得队列中任务的个数
int BoundedBlockingQueue::getSize()
{
	std::lock_guard<std::mutex> lock(m_mutex);
	return m_tasks.size();
}

//判断队列是否为空
bool BoundedBlockingQueue::isEmpty()
{
	std::lock_guard<std::mutex> lock(m_mutex);
	return m_tasks.empty();
}

BoundedBlockingQueue::BoundedBlockingQueue(BoundedBlockingQueue& other)
{
	m_tasks = other.m_tasks;
	MAX_SIZE = other.MAX_SIZE;
}

BoundedBlockingQueue& BoundedBlockingQueue::operator=(const BoundedBlockingQueue& other)
{
	m_tasks = other.m_tasks;
	MAX_SIZE = other.MAX_SIZE;
	return *this;
}


#include "BoundedBlockingQueue.h"

std::mutex g_mutex;	//����ȫ�ֻ������� ���ڷ�ֹ��ӡ����
//�������
void BoundedBlockingQueue::addTask(TaskPtr task)
{
	std::lock_guard<std::mutex> lock(m_mutex);
	if (m_tasks.size() >= MAX_SIZE)
	{
		//��ֹ��ӡ���������
		{
			std::lock_guard<std::mutex> lock(g_mutex);
			std::cout << "��������" << std::endl;
		}
		return;
	}
	//��ֹ��ӡ���������
	{
		std::lock_guard<std::mutex> lock(g_mutex);
		std::cout << "---add task : [" << task->getName().c_str() << "]" << std::endl;
	}
	m_tasks.push(task);
}

//ȡ������
TaskPtr BoundedBlockingQueue::getTask()
{
	std::lock_guard<std::mutex> lock(m_mutex);

	if (m_tasks.empty())
		return nullptr;

	TaskPtr task = m_tasks.front();
	m_tasks.pop();

	return task;
}

//��ö���������ĸ���
int BoundedBlockingQueue::getSize()
{
	std::lock_guard<std::mutex> lock(m_mutex);
	return m_tasks.size();
}

//�ж϶����Ƿ�Ϊ��
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


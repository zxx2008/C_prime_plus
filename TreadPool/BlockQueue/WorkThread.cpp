#include "WorkThread.h"
#include "QueueTask.h"
extern std::mutex g_mutex;

void WorkThread::dequeue()
{
	//工程线程没有结束的时候
	while (!m_finish)
	{
		m_state = STATE_WAIT;	//线程默认阻塞状态

		//当线程没有结束并且队列为空的时候，阻塞当前线程
		while (!m_finish && m_taskQue.isEmpty())
		{
			//休眠100微妙 
			std::this_thread::sleep_for(std::chrono::microseconds(50));
		}
		//当线程结束了，结束循环
		if (m_finish)
		{
			break;
		}

		//运行到此处,说明队列不为空,取出队列中的数据
		TaskPtr task = m_taskQue.getTask();

		if (task != nullptr)
		{
			//此时状态设置为工作状态
			m_state = STATE_WORK;

			//	cout << "--- thread[" << get_id() << "] : run task [" << task->getName().c_str() << "] << begin" << endl;
			task->run(); //运行当前线程任务
		//	cout << "--- thread[" << get_id() << "] : run task [" << task->getName().c_str() << "] << end" << endl;
		}
	}
	m_state = STATE_EXIT;
}

WorkThread::WorkThread(BoundedBlockingQueue& blockingQueue): m_taskQue(blockingQueue), m_state(STATE_WAIT), m_finish(false)
{
	//使用lambda表达式创建线程
	m_thread = std::thread(&WorkThread::dequeue, this);
	{
		std::lock_guard<std::mutex> lock(g_mutex);
		std::cout << "-- Workthread [" << m_thread.get_id() << "]: started ---" << std::endl;
	}
}

WorkThread::~WorkThread()
{
	//防止打印混乱，添加锁
	{
		std::lock_guard<std::mutex> lock(g_mutex);
		std::cout << "---Workthread [" << m_thread.get_id() << "]: finish ---" << std::endl;
	}
	
	if (m_thread.joinable())
		m_thread.join();
}

int WorkThread::getState() const
{
	return m_state;
}

void WorkThread::finish()
{
	m_finish = true;
}

std::thread::id WorkThread::getId()
{
	return m_thread.get_id();
}

std::thread& WorkThread::getCurrentThread()
{
	return m_thread;
}
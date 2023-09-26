#include "TaskThread.h"
#include "QueueTask.h"

extern std::mutex g_mutex;

void TaskThread::enqueue()
{
	int i = 0;
	while (!m_finish)
	{
		m_state = STATE_WAIT;	//线程默认阻塞状态

		//当线程没有结束并且队列满的时候，阻塞当前线程
		while (!m_finish && m_taskQue.getSize() == m_taskQue.MAX_SIZE)
		{
			//休眠100微妙
			std::this_thread::sleep_for(std::chrono::microseconds(50));
		}
		//当线程结束了，结束循环
		if (m_finish)
		{
			break;
		}

		//运行到此处,说明队列没有满
		m_taskQue.addTask(std::make_shared<MyTask>(i));
		//此时状态设置为工作
		m_state = STATE_WORK;
		++i;
	}
	m_state = STATE_EXIT;
}

TaskThread::TaskThread(BoundedBlockingQueue& blockingQueue): m_taskQue(blockingQueue), m_state(STATE_WAIT), m_finish(false)
{
	//使用lambda表达式创建线程
	m_thread = std::thread(&TaskThread::enqueue, this);
	//防止打印混乱添加锁
	{
		std::lock_guard<std::mutex> lock(g_mutex);
		std::cout << "-- Taskthread [" << m_thread.get_id() << "]: started ---" << std::endl;
	}
}

TaskThread::~TaskThread()
{	//防止打印混乱添加锁
	{
		std::lock_guard<std::mutex> lock(g_mutex);
		printf("-- Taskthread [%d]  : finish ---\n", m_thread.get_id());
	}
	if (m_thread.joinable())
		m_thread.join();

}

int TaskThread::getState() const
{
	return m_state;
}

void TaskThread::finish()
{
	m_finish = true;
}

std::thread::id TaskThread::getId()
{
	return m_thread.get_id();
}

std::thread& TaskThread::getCurrentThread()
{
	return m_thread;
}
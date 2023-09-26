#include "TaskThread.h"
#include "QueueTask.h"

extern std::mutex g_mutex;

void TaskThread::enqueue()
{
	int i = 0;
	while (!m_finish)
	{
		m_state = STATE_WAIT;	//�߳�Ĭ������״̬

		//���߳�û�н������Ҷ�������ʱ��������ǰ�߳�
		while (!m_finish && m_taskQue.getSize() == m_taskQue.MAX_SIZE)
		{
			//����100΢��
			std::this_thread::sleep_for(std::chrono::microseconds(50));
		}
		//���߳̽����ˣ�����ѭ��
		if (m_finish)
		{
			break;
		}

		//���е��˴�,˵������û����
		m_taskQue.addTask(std::make_shared<MyTask>(i));
		//��ʱ״̬����Ϊ����
		m_state = STATE_WORK;
		++i;
	}
	m_state = STATE_EXIT;
}

TaskThread::TaskThread(BoundedBlockingQueue& blockingQueue): m_taskQue(blockingQueue), m_state(STATE_WAIT), m_finish(false)
{
	//ʹ��lambda���ʽ�����߳�
	m_thread = std::thread(&TaskThread::enqueue, this);
	//��ֹ��ӡ���������
	{
		std::lock_guard<std::mutex> lock(g_mutex);
		std::cout << "-- Taskthread [" << m_thread.get_id() << "]: started ---" << std::endl;
	}
}

TaskThread::~TaskThread()
{	//��ֹ��ӡ���������
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
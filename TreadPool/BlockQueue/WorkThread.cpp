#include "WorkThread.h"
#include "QueueTask.h"
extern std::mutex g_mutex;

void WorkThread::dequeue()
{
	//�����߳�û�н�����ʱ��
	while (!m_finish)
	{
		m_state = STATE_WAIT;	//�߳�Ĭ������״̬

		//���߳�û�н������Ҷ���Ϊ�յ�ʱ��������ǰ�߳�
		while (!m_finish && m_taskQue.isEmpty())
		{
			//����100΢�� 
			std::this_thread::sleep_for(std::chrono::microseconds(50));
		}
		//���߳̽����ˣ�����ѭ��
		if (m_finish)
		{
			break;
		}

		//���е��˴�,˵�����в�Ϊ��,ȡ�������е�����
		TaskPtr task = m_taskQue.getTask();

		if (task != nullptr)
		{
			//��ʱ״̬����Ϊ����״̬
			m_state = STATE_WORK;

			//	cout << "--- thread[" << get_id() << "] : run task [" << task->getName().c_str() << "] << begin" << endl;
			task->run(); //���е�ǰ�߳�����
		//	cout << "--- thread[" << get_id() << "] : run task [" << task->getName().c_str() << "] << end" << endl;
		}
	}
	m_state = STATE_EXIT;
}

WorkThread::WorkThread(BoundedBlockingQueue& blockingQueue): m_taskQue(blockingQueue), m_state(STATE_WAIT), m_finish(false)
{
	//ʹ��lambda���ʽ�����߳�
	m_thread = std::thread(&WorkThread::dequeue, this);
	{
		std::lock_guard<std::mutex> lock(g_mutex);
		std::cout << "-- Workthread [" << m_thread.get_id() << "]: started ---" << std::endl;
	}
}

WorkThread::~WorkThread()
{
	//��ֹ��ӡ���ң������
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
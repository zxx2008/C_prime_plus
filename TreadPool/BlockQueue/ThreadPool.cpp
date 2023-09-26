#include "threadpool.h"

extern std::mutex g_mutex;

ThreadPool::ThreadPool(int QueMaxSize, int min, int max) : m_finish(false), m_min(min), m_max(max)
{
	m_taskQ = BoundedBlockingQueue(QueMaxSize);

	//����min���̣߳��̳߳ش����С�߳���
	for (int i = 0; i < min; ++i)
	{
		//�ֱ𴴽������̣߳���������ʹ�������
		addThreadWork();
		addThreadTask();
	}

	//���������߳�
	//m_managerThread = std::thread([this]()
	//	{
	//		int cnt = 0;
	//		//�����̳߳�û�йرգ���һֱ���
	//		while (!m_finish)
	//		{
	//			//��ǰ�������� > 2�����߳��� &&  �Ѿ����ڵ��߳� < ����̸߳���
	//			//˵����ǰ�߳�̫����,����̫����,��Ҫ�����µĹ����߳�
	//			if ((m_taskQ.getSize() > 2 * m_thread.size()) && (m_thread.size() < m_max))
	//			{
	//				addThread();
	//			}
	//			else
	//			{
	//				//ͳ�Ƶ�ǰ�����̵߳�����
	//				cnt = 0;

	//				for (auto it = m_thread.begin(); it != m_thread.end(); ++it)
	//				{
	//					//���ǵ�ǰ�߳��������߳�
	//					if (it->second->getState() == WorkThread::STATE_WAIT)
	//					{
	//						++cnt;
	//					}
	//				}

	//				//���ǿ��е��߳��� > 2����������,�Ѿ��������߳��ܸ��� > ��С�߳���
	//				//˵����ǰ���е��߳�̫����,�Ѷ���Ŀ����߳����ٵ�
	//				if ((cnt > 2 * m_taskQ.getSize()) && (m_thread.size() > m_min))
	//				{
	//					delThread();
	//				}
	//				//����100΢��
	//				std::this_thread::sleep_for(std::chrono::microseconds(100));
	//			}
	//		}

	//	});
}

ThreadPool::~ThreadPool()
{
	//���չ������߳�
	if (m_managerThread.joinable())
		m_managerThread.join();
}

////���������ӵ����������
//void ThreadPool::addTask(TaskPtr task)
//{
//	m_taskQ.addTask(task);
//}

//�ر��̳߳�
void ThreadPool::Finish()
{
	m_finish = true;

	for (auto it = m_thread.begin(); it != m_thread.end(); ++it)
	{
		it->second->finish();
	}
}

//��������������߳��̣߳����ѹ����߳���ӵ�unorder_map�й���
void ThreadPool::addThreadWork()
{
	{
		std::lock_guard<std::mutex> lock(g_mutex);
		std::cout << "--- add threadWork" << std::endl;
	}

	auto tidPtr = std::make_shared<WorkThread>(m_taskQ);
	m_thread[tidPtr->getId()] = tidPtr;

}

//����������񵽶��е��̣߳����ѹ����߳���ӵ�unorder_map�й���
void ThreadPool::addThreadTask()
{
	{
		std::lock_guard<std::mutex> lock(g_mutex);
		std::cout << "--- add threadTask" << std::endl;
	}
	auto tidPtr = std::make_shared<TaskThread>(m_taskQ);
	m_thread[tidPtr->getId()] = tidPtr;
}

//ɾ������wait״̬���߳�
//void ThreadPool::delThread()
//{
//	std::cout << "--- del thread" << std::endl;
//
//	std::thread::id tid;
//
//	for (auto it = m_thread.begin(); it != m_thread.end(); ++it)
//	{
//		//�������߳�Ϊ�ȴ�״̬
//		if (it->second->getState() == WorkThread::STATE_WAIT)
//		{
//			//������ǰ�߳�
//			it->second->finish();
//			//����̵߳�tid
//			tid = it->first;
//			break;
//		}
//	}
//
//	//��tid��Ӧ���̰߳�
//	m_thread.erase(tid);
//}
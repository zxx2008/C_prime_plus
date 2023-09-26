#include "threadpool.h"

extern std::mutex g_mutex;

ThreadPool::ThreadPool(int QueMaxSize, int min, int max) : m_finish(false), m_min(min), m_max(max)
{
	m_taskQ = BoundedBlockingQueue(QueMaxSize);

	//创建min个线程，线程池存放最小线程数
	for (int i = 0; i < min; ++i)
	{
		//分别创建两种线程：产生任务和处理任务
		addThreadWork();
		addThreadTask();
	}

	//创建管理线程
	//m_managerThread = std::thread([this]()
	//	{
	//		int cnt = 0;
	//		//若是线程池没有关闭，就一直检测
	//		while (!m_finish)
	//		{
	//			//当前的任务数 > 2倍的线程数 &&  已经存在的线程 < 最大线程个数
	//			//说明当前线程太少了,任务太多了,需要创建新的工作线程
	//			if ((m_taskQ.getSize() > 2 * m_thread.size()) && (m_thread.size() < m_max))
	//			{
	//				addThread();
	//			}
	//			else
	//			{
	//				//统计当前阻塞线程的数据
	//				cnt = 0;

	//				for (auto it = m_thread.begin(); it != m_thread.end(); ++it)
	//				{
	//					//若是当前线程是阻塞线程
	//					if (it->second->getState() == WorkThread::STATE_WAIT)
	//					{
	//						++cnt;
	//					}
	//				}

	//				//若是空闲的线程数 > 2倍的任务数,已经创建的线程总个数 > 最小线程数
	//				//说明当前空闲的线程太多了,把多余的空闲线程销毁掉
	//				if ((cnt > 2 * m_taskQ.getSize()) && (m_thread.size() > m_min))
	//				{
	//					delThread();
	//				}
	//				//休眠100微秒
	//				std::this_thread::sleep_for(std::chrono::microseconds(100));
	//			}
	//		}

	//	});
}

ThreadPool::~ThreadPool()
{
	//回收管理者线程
	if (m_managerThread.joinable())
		m_managerThread.join();
}

////添加任务添加到任务队列中
//void ThreadPool::addTask(TaskPtr task)
//{
//	m_taskQ.addTask(task);
//}

//关闭线程池
void ThreadPool::Finish()
{
	m_finish = true;

	for (auto it = m_thread.begin(); it != m_thread.end(); ++it)
	{
		it->second->finish();
	}
}

//创建处理任务的线程线程，并把工作线程添加到unorder_map中管理
void ThreadPool::addThreadWork()
{
	{
		std::lock_guard<std::mutex> lock(g_mutex);
		std::cout << "--- add threadWork" << std::endl;
	}

	auto tidPtr = std::make_shared<WorkThread>(m_taskQ);
	m_thread[tidPtr->getId()] = tidPtr;

}

//创建添加任务到队列的线程，并把工作线程添加到unorder_map中管理
void ThreadPool::addThreadTask()
{
	{
		std::lock_guard<std::mutex> lock(g_mutex);
		std::cout << "--- add threadTask" << std::endl;
	}
	auto tidPtr = std::make_shared<TaskThread>(m_taskQ);
	m_thread[tidPtr->getId()] = tidPtr;
}

//删除所有wait状态的线程
//void ThreadPool::delThread()
//{
//	std::cout << "--- del thread" << std::endl;
//
//	std::thread::id tid;
//
//	for (auto it = m_thread.begin(); it != m_thread.end(); ++it)
//	{
//		//若是有线程为等待状态
//		if (it->second->getState() == WorkThread::STATE_WAIT)
//		{
//			//结束当前线程
//			it->second->finish();
//			//获得线程的tid
//			tid = it->first;
//			break;
//		}
//	}
//
//	//把tid对应的线程把
//	m_thread.erase(tid);
//}
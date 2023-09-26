#ifndef _THREADPOOL_H_
#define _THREADPOOL_H_

#include "BoundedBlockingQueue.h"
#include <thread>
#include <unordered_map>
#include <iostream>
#include <atomic>
#include "VirtualThread.h"
#include "TaskThread.h"
#include "WorkThread.h"

class ThreadPool
{
public:
	ThreadPool(int QueMaxSize, int min = 10, int max = 50);
	~ThreadPool();

	//添加任务队列任务到线程池中
	void addTask(TaskPtr task);

	//关闭线程池
	void Finish();

private:

	//创建线程,向线程池中添加线程
	void addThreadWork();	//添加处理任务的线程
	void addThreadTask();	//添加向队列插入任务的线程

	//删除线程,删除线程池中的线程
	/*void delThread();*/

	//功能和bool类型差不多，只不过是在多线程操作中可以保证原子操作.
	//原子操作:在同一时刻只有唯一的线程可以这个资源进行访问
	std::atomic_bool m_finish; //线程池结束标志

	//存储工作线程信息
	std::unordered_map<std::thread::id, ThreadPtr>  m_thread;

	std::thread m_managerThread;// 管理线程

	BoundedBlockingQueue m_taskQ; //创建用户自定义任务对象
	int m_max; //最大线程数
	int m_min; //最小线程数
};
#endif // !_THREADPOOL_H_


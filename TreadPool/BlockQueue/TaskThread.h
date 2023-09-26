#ifndef _TASKTHREAD_H_
#define _TASKTHREAD_H_

#include "BoundedBlockingQueue.h"
#include <atomic>
#include <memory>
#include <thread>
#include <string>
#include "VirtualThread.h"

extern std::mutex g_mutex;

class TaskThread: public VirtualThread
{
public:
	//用constexpr修饰的函数或者变量都将被看作其值是编译期确定的值！
	constexpr static int STATE_WAIT = 1;
	constexpr static int STATE_WORK = 2;
	constexpr static int STATE_EXIT = 3;

	TaskThread(BoundedBlockingQueue& blockingQueue);
	~TaskThread();
	//获得线程状态
	int getState() const;
	//功能函数，向队列中添加任务，用于线程的调用
	void enqueue();
	//结束线程，m_finish置为true
	void finish();
	//获得线程id
	std::thread::id getId();

	std::thread& getCurrentThread();

private:
	BoundedBlockingQueue& m_taskQue;  //任务队列
	std::atomic_int m_state;  //判断当前线程状态
	std::atomic_bool m_finish;  //线程结束标值
	std::thread m_thread;  //保存当前线程地址
};

//using ThreadPtr = std::shared_ptr<TaskThread>;

//class MyTask : public Task {
//public:
//	MyTask(int i) : Task("MyTask" + std::to_string(i)) {}
//	//实现Task类的Run函数，最终线程池里会调用该函数
//	void run()
//	{
//		for (int i = 0; i < 5; ++i) {
//			//使用printf输出较少<< 重载的时间
//			{
//				std::lock_guard<std::mutex> lock(g_mutex);
//				printf("-- thread [%d]: task_name=[%s]\n", std::this_thread::get_id(), this->getName().c_str());
//			}
//			/*{
//				std::lock_guard<std::mutex> lock(m_taskQue.m_mutex);
//				std::cout << "-- thread [" << std::this_thread::get_id() << "] : task_name=[" << this->getName() << 
//			}*/
//			// std::this_thread::sleep_for(std::chrono::microseconds(5000));
//			std::this_thread::sleep_for(std::chrono::seconds(1));
//		}
//	}
//};
#endif 


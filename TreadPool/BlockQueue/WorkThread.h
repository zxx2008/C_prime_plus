#ifndef _WORKTHREAD_H_
#define _WORKTHREAD_H_

#include "BoundedBlockingQueue.h"
#include <atomic>
#include <memory>
#include <thread>
#include "VirtualThread.h"

class WorkThread: public VirtualThread
{
public:
	//用constexpr修饰的函数或者变量都将被看作其值是编译期确定的值！
	constexpr static int STATE_WAIT = 1;
	constexpr static int STATE_WORK = 2;
	constexpr static int STATE_EXIT = 3;

	WorkThread(BoundedBlockingQueue& blockingQueue);
	~WorkThread();
	//获得线程状态
	int getState() const;
	//功能函数，处理队列中的任务，用于线程的调用
	void dequeue();
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

//using ThreadPtr = std::shared_ptr<WorkThread>;

#endif // !_WORKTHREAD_H_


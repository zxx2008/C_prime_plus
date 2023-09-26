#ifndef _VIRTUALTHREAD_H_
#define _VIRTUALTHREAD_H_

#include "BoundedBlockingQueue.h"
#include <atomic>
#include <memory>
#include <thread>

//用于自定义子类线程功能的父类
class VirtualThread
{
public:
	virtual ~VirtualThread() { ; }
	//获得线程状态
	virtual int getState() const = 0;

	virtual void finish() = 0;
	//获得线程id
	virtual std::thread::id getId() = 0;

	virtual std::thread& getCurrentThread() = 0;

};

using ThreadPtr = std::shared_ptr<VirtualThread>;

#endif // !_VIRTUALTHREAD_H_

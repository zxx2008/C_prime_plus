#ifndef _VIRTUALTHREAD_H_
#define _VIRTUALTHREAD_H_

#include "BoundedBlockingQueue.h"
#include <atomic>
#include <memory>
#include <thread>

//�����Զ��������̹߳��ܵĸ���
class VirtualThread
{
public:
	virtual ~VirtualThread() { ; }
	//����߳�״̬
	virtual int getState() const = 0;

	virtual void finish() = 0;
	//����߳�id
	virtual std::thread::id getId() = 0;

	virtual std::thread& getCurrentThread() = 0;

};

using ThreadPtr = std::shared_ptr<VirtualThread>;

#endif // !_VIRTUALTHREAD_H_

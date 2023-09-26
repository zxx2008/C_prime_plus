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
	//��constexpr���εĺ������߱���������������ֵ�Ǳ�����ȷ����ֵ��
	constexpr static int STATE_WAIT = 1;
	constexpr static int STATE_WORK = 2;
	constexpr static int STATE_EXIT = 3;

	WorkThread(BoundedBlockingQueue& blockingQueue);
	~WorkThread();
	//����߳�״̬
	int getState() const;
	//���ܺ�������������е����������̵߳ĵ���
	void dequeue();
	//�����̣߳�m_finish��Ϊtrue
	void finish();
	//����߳�id
	std::thread::id getId();

	std::thread& getCurrentThread();

private:
	BoundedBlockingQueue& m_taskQue;  //�������
	std::atomic_int m_state;  //�жϵ�ǰ�߳�״̬
	std::atomic_bool m_finish;  //�߳̽�����ֵ
	std::thread m_thread;  //���浱ǰ�̵߳�ַ
};

//using ThreadPtr = std::shared_ptr<WorkThread>;

#endif // !_WORKTHREAD_H_


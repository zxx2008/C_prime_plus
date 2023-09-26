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
	//��constexpr���εĺ������߱���������������ֵ�Ǳ�����ȷ����ֵ��
	constexpr static int STATE_WAIT = 1;
	constexpr static int STATE_WORK = 2;
	constexpr static int STATE_EXIT = 3;

	TaskThread(BoundedBlockingQueue& blockingQueue);
	~TaskThread();
	//����߳�״̬
	int getState() const;
	//���ܺ������������������������̵߳ĵ���
	void enqueue();
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

//using ThreadPtr = std::shared_ptr<TaskThread>;

//class MyTask : public Task {
//public:
//	MyTask(int i) : Task("MyTask" + std::to_string(i)) {}
//	//ʵ��Task���Run�����������̳߳������øú���
//	void run()
//	{
//		for (int i = 0; i < 5; ++i) {
//			//ʹ��printf�������<< ���ص�ʱ��
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


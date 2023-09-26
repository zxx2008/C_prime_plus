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

	//���������������̳߳���
	void addTask(TaskPtr task);

	//�ر��̳߳�
	void Finish();

private:

	//�����߳�,���̳߳�������߳�
	void addThreadWork();	//��Ӵ���������߳�
	void addThreadTask();	//�������в���������߳�

	//ɾ���߳�,ɾ���̳߳��е��߳�
	/*void delThread();*/

	//���ܺ�bool���Ͳ�ֻ࣬�������ڶ��̲߳����п��Ա�֤ԭ�Ӳ���.
	//ԭ�Ӳ���:��ͬһʱ��ֻ��Ψһ���߳̿��������Դ���з���
	std::atomic_bool m_finish; //�̳߳ؽ�����־

	//�洢�����߳���Ϣ
	std::unordered_map<std::thread::id, ThreadPtr>  m_thread;

	std::thread m_managerThread;// �����߳�

	BoundedBlockingQueue m_taskQ; //�����û��Զ����������
	int m_max; //����߳���
	int m_min; //��С�߳���
};
#endif // !_THREADPOOL_H_


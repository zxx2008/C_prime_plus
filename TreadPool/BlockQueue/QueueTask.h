#ifndef _QUEUETASK_H_
#define _QUEUETASK_H_

#include "Task.h"
#include <mutex>

extern std::mutex g_mutex;

class MyTask: public Task
{
public:
	
	MyTask(int num, std::string name = "MyTask") : m_num(num), Task(name)
	{
		;
	}
	void run()
	{
		{
			std::lock_guard<std::mutex> lock(g_mutex);
			//printf("-- thread [%d]: task_name=[%s] task_num=[%d]\n", std::this_thread::get_id(), this->getName().c_str(), this->m_num);
			std::cout << "--thread [" << std::this_thread::get_id << "]: task_num=[" << this->m_num << "] ÒÑÍê³É" << std::endl;
		}
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
private:
	int m_num;
};
#endif
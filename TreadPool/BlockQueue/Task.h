#ifndef _TASK_H_
#define _TASK_H_

#include <iostream>
#include <memory>

//用户自定义的任务类,用户后期可自定义任务，继承重写run函数来添加信息
class Task
{
public:
	//这里设计了一个stirng保存任务名字
	Task(const std::string& name = "") : m_name(name)
	{
		;
	}

	inline std::string getName()
	{
		return m_name;
	}
	//给用户重写需要的run方法
	virtual void run() = 0;

private:
	std::string m_name;
};

using TaskPtr = std::shared_ptr<Task>;
#endif 
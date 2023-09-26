#ifndef _TASK_H_
#define _TASK_H_

#include <iostream>
#include <memory>

//�û��Զ����������,�û����ڿ��Զ������񣬼̳���дrun�����������Ϣ
class Task
{
public:
	//���������һ��stirng������������
	Task(const std::string& name = "") : m_name(name)
	{
		;
	}

	inline std::string getName()
	{
		return m_name;
	}
	//���û���д��Ҫ��run����
	virtual void run() = 0;

private:
	std::string m_name;
};

using TaskPtr = std::shared_ptr<Task>;
#endif 
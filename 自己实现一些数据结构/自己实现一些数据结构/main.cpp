#include "DoubleRectionQueue.h"
#include <iostream>
int main() {
	DoubleRectionQueue* queueTest = new DoubleRectionQueue();
	std::cout << queueTest->getSize() << std::endl;
	queueTest->putFront(4);
	queueTest->putFront(5);
	std::cout << queueTest->getSize() << std::endl;
	std:: cout << "pop "<< queueTest->popBack() << std::endl;
	std::cout << queueTest->getSize() << std::endl;
	std::cout << "pop " << queueTest->popBack() << std::endl;
	std::cout << "pop " <<queueTest->popBack() << std::endl; //输出异常"队列为空"
	queueTest->putFront(4);
	queueTest->putFront(5);
	queueTest->putFront(4);
	queueTest->putFront(5);
	queueTest->printQueue();
	return 0;
}
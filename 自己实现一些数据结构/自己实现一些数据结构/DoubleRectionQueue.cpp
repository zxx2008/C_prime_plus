#include "DoubleRectionQueue.h"
#include <iostream>

DoubleRectionQueue::DoubleRectionQueue() : first(nullptr), last(nullptr), size(0) {}

DoubleRectionQueue::~DoubleRectionQueue() {
	DoubleRectionNode* cur = first;
	DoubleRectionNode* pre = first;
	while (cur != nullptr) {
		pre = cur;
		cur = first->next;
		delete pre;
	}
}

void DoubleRectionQueue::put(int val, bool isFront) {
	DoubleRectionNode* newNode = new DoubleRectionNode(val);
	if (this->size == 0) {
		first = last = newNode;
	} 
	else if (isFront) {
		newNode->next = first;
		first->prev = newNode;
		first = newNode;
	}
	else {
		last->next = newNode;
		newNode->prev = last;
		last = newNode;
	}
	this->size++;
}

void DoubleRectionQueue::putFront(int val) {
	this->put(val, true);
}

void DoubleRectionQueue::putBack(int val) {
	this->put(val, false);
}

int DoubleRectionQueue::pop(bool isFront) {
	int val = 0;
	if (this->size == 0) {
		//std::cout << "队列为空" << std::endl;
		throw std::out_of_range("队列为空");
		//return val;
	}
	else if (isFront) {
		val = first->val;
		DoubleRectionNode* nextFirst = first->next;
		if (nextFirst) {
			delete first;
			first = nextFirst;
		}
		else {
			delete first;
			first = last = nullptr;
		}
		--size;
		//return val
	}
	else {
		val = last->val;
		DoubleRectionNode* prevLast = last->prev;
		if (prevLast) {
			delete last;
			last = prevLast;
		}
		else {
			delete last;
			last = first = nullptr;
		}
		--size;
	}
	return val;
}

int DoubleRectionQueue::popFront() {
	int val = 0;
	try {
		val = this->pop(true);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	return val;
}

int DoubleRectionQueue::popBack() {
	int val = 0;
	try {
		val = this->pop(false);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	return val;
}

int DoubleRectionQueue::getSize() {
	return this->size;
}

void DoubleRectionQueue::printQueue() {
	if (this->size == 0) {
		std::cout << "队列为空" << std::endl;
	}
	else {
		DoubleRectionNode* cur = first;
		std::cout << "队列中的元素值分别为：" << std::endl;
		do {
			std::cout << cur->val << std::endl;
			cur = cur->next;
		} while (cur);
	}
}
#include "DoubleRectionQueue.h"
#include <iostream>

DoubleRectionQueue::DoubleRectionQueue() : first(nullptr), last(nullptr), size(0) {}

DoubleRectionQueue::~DoubleRectionQueue() {
	DoubleRectionNode* cur, * pre = first;
	while (cur != nullptr) {
		pre = cur;
		cur = first->next;
		delete pre;
	}
}

void DoubleRectionQueue::put(int val, bool isFront) {
	DoubleRectionNode* newNode = new DoubleRectionNode();
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

void DoubleRectionQueue::popFront() {
	if (this->size == 0) {
		std::cout << "╤сапн╙©у" << std::endl;
	}
	else {
		
	}
}
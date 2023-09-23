#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


class myException {
public:
	myException(char* str) {
		error = new char[strlen(str) + 1];
		strcpy(error, str);
	}
	~myException() {
		if (error != NULL) {
			delete[] error;
		}
	}
	void what() {
		std::cout << error << std::endl;
	}

private:
	char* error;
};

void func1() {
	throw myException("123"); //这里实参是char[]，形参是char * 可能编译不能通过。将项目->属性->语言->符合模式改为否
}

int main() {
	try {
		func1();
	}
	catch (myException& e) { //这里捕获对象的引用，如果捕获对象会发生异常，不知道为什么？
		e.what();
	}
}
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
	throw myException("123"); //����ʵ����char[]���β���char * ���ܱ��벻��ͨ��������Ŀ->����->����->����ģʽ��Ϊ��
}

int main() {
	try {
		func1();
	}
	catch (myException& e) { //���ﲶ���������ã�����������ᷢ���쳣����֪��Ϊʲô��
		e.what();
	}
}
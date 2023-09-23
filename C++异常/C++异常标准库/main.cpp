#include <iostream>
#include <stdexcept>

class Person {
public:
	Person() {}
	void SetAge(int age) {
		if (age < 1 || age > 200) {
			throw std::out_of_range("����Ӧ����1��200֮�䣡"); //ʹ��C++��׼���쳣
		}
	}

private:
	int mAge;
};

int main() {
	Person* p1 = new Person();
	try { 
		p1->SetAge(300); 
	}
	catch (std::exception& e) { //ʹ�ø�������ò���������쳣
		std::cout << e.what() << std::endl;
	}

}
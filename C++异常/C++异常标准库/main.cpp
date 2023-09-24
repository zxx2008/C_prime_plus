#include <iostream>
#include <stdexcept>

class Person {
public:
	Person() {}
	void SetAge(int age) {
		if (age < 1 || age > 200) {
			throw std::out_of_range("年龄应该在1到200之间！"); //使用C++标准库异常
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
	catch (std::exception& e) { //使用父类的引用捕获子类的异常
		std::cout << e.what() << std::endl;
	}

}
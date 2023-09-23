#include <iostream>

template <class T>
class Person {
public:
	Person(int age = 18, int id = 0);
	void show();
	template <class T>
	friend std::ostream& operator<<(std::ostream& out, Person<T>& src);
private:
	T mAge;
	T mId;
};

template <class T>
Person<T>::Person(int age, int id): mAge(age), mId(id) {

}

template <class T>
void Person<T>::show() {
	std::cout << "Age:" << mAge << "Id:" << mId << std::endl;
}

template <class T>
std::ostream& operator<<(std::ostream& out, Person<T>& src) {
	out << "Age:" << src.mAge << "Id:" << src.mId << std::endl;
	return out;
}

int main() {
	Person<int>* p1 = new Person<int>(19, 1);
	std::cout << 19 << *p1 << std::endl;
}
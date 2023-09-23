# include <iostream>
# include <string>

using namespace std;

class MyString {
	int x;
public:
	MyString(const int x) : x(x) { cout << "111" << endl; }
	MyString(const MyString& other) {
		x = other.x;
		cout << "222" << endl;
	}
};

int main() {
	MyString mystring(3);
	MyString mystring2(mystring);
	MyString mystring3 = mystring;
	mystring2 = mystring3;
	string s = "Hello";
	string::iterator it = s.begin();
	cout << typeid(*it).name() << endl;
}
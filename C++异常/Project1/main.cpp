# include <iostream>

float divide(int a, int b) {
	if (b == 0) {
		throw b;				//抛出异常
	}
	return a / b;
}

float callDivide(int a, int b) {
	return divide(a, b);
}

float testError(int a, int b) {
	float res = 0;
	try {								//callDivde 没有捕获异常，异常向上传递，由tesError捕获了异常
		res = callDivide(a, b);
	} catch(int e) {			//使用int e捕获被抛出的y
		std::cout << "除数不能为" << e << "!" << std::endl; 
	}

	return res;
}

int main() {
	testError(3, 0);
	return 0;
}
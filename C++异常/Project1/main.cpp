# include <iostream>

float divide(int a, int b) {
	if (b == 0) {
		throw b;				//�׳��쳣
	}
	return a / b;
}

float callDivide(int a, int b) {
	return divide(a, b);
}

float testError(int a, int b) {
	float res = 0;
	try {								//callDivde û�в����쳣���쳣���ϴ��ݣ���tesError�������쳣
		res = callDivide(a, b);
	} catch(int e) {			//ʹ��int e�����׳���y
		std::cout << "��������Ϊ" << e << "!" << std::endl; 
	}

	return res;
}

int main() {
	testError(3, 0);
	return 0;
}
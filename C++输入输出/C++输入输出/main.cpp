#include <iostream>

void test01() {
	char ch;
	//每次读取键盘输入的一个字符，缓冲区没有会阻塞
	//一次输入大量字符，会先存放在缓冲区中，程序再从缓冲区一个一个读取，所以就会出现一次输入多个字符，回车后逐个输出。
	//ch = std::cin.get 外面的括号不能省！
	while ((ch = std::cin.get()) != EOF) { 
		std::cout << ch << std::endl;
	}
}

void test02() {
	char buf[256] = { 0 };
	//std::cin.get(buf, 256); // 读取一个字符串
	//std::cout << buf << std::endl;
	//std::cout << "..." << std::endl;
	std::cin.getline(buf, 256); //读取一行
	std::cout << buf << std::endl;
}

void test03() {
	char ch;
	std::cin.get(ch); //从缓冲区中读字符
	std::cout << ch << std::endl;
	std::cin.ignore(); //从缓冲区中忽略一个字符 ignore(2) 忽略两个字符 ignore(10, '\n') 忽略10个字符，入果找到'\n'就提结束忽略
	std::cin.get(ch);
	std::cout << ch << std::endl;
	//std::cin.peek() 返回缓冲区第一个字符，但并不取走
	//cin.putback() 放回缓冲区第一个位置
}
int main() {
	test03();
	//std::cout << "你好" << std::endl;
	return 0;
}
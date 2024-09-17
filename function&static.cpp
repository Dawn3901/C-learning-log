#include<iostream>
using namespace std;
//指针的方式交换
void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
//引用的方式交换
void Swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void func(int& a) {
	a += 80;
}

void log(const char* message) {
	cout << message << endl;
}

void Print_i() {
	static int i = 1;//只在第一次调用时声明和赋值，生存周期是全程，但只能在函数内使用
	cout << i++ << endl;
}

void Print_j() {
	int j = 1;//每次调用会声明和赋值，且调用完就销毁
	cout << j++ << endl;
}

int k=1;//全局变量，生存周期全程，且在任何位置可以使用
void Print_k() {
	cout << k ++<< endl;
}

int main()
{
	Print_i();
	Print_i();
	Print_i();
	Print_i();
	Print_i();

	Print_j();
	Print_j();
	Print_j();
	Print_j();
	Print_j();

	Print_k();
	Print_k();
	Print_k();
	Print_k();
	Print_k();

	return 0;
}

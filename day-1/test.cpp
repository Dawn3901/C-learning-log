#include<iostream>
constexpr auto pai = 3.1415926;
using namespace std;
//配合其他文件使用，函数的定义在其他文件
void log(const char* message);//这里需要声明，定义可以写在另一个文件里
//c++可以函数重载，也就是可以出现同名但又有些许不同的函数声明和定义
double max(double a, double b);
int max(int a,int b);
int max(int a);
void Print(const char* message) {
	for (int i = 0; i < 5; i++) {
		cout <<message << endl;
	}
}
int dup(int n);
void swap(int* a, int* b);
void Swap(int& a, int& b);
void func(int& a);

int main()
{
	cout << "hello c++!" << endl;
	printf("Hello world\n");
	log("Hello C++!");
	cout << sizeof(int) << endl;
	int v = 0;
	int* p = &v;
	cout << sizeof(*p) << endl;
	cout << sizeof(p) << endl;
	char ch = '6';
	cout << sizeof(ch) << endl;
	cout << ch << endl;
	bool check = true;
	if (check) cout << "I am OK." << endl;
	cout << sizeof(bool) << endl;
	cout << max(15.0, 5 * pai) << endl;
	cout << max(15, 19) << endl;
	cout << max(16) << endl;
	Print("你有毛病吧。");

	int n;
	cin >> n;
	cout << dup(n) << endl;

	for (int i = 0; i < 6; ++i) {
		cout << "Hello World" << endl;
	}
	bool b = true;
	int num;
	for (int j=1; b;j++) {
		cin >> num;
		if (num == 0) {
			b = false;
			break;
		}
		cout << "第" << j << "次输入成功！" << endl;
	}
	bool condition = true;
	int k = 1;
	while (condition) {
		cin >> n;
		if (num == 0) {
			condition = false;
			break;
		}
		cout << "第" << k++ << "次输入成功？" << endl;
	}
	
	cout << "你有五次输入机会:\n（但是输入0会停止）" << endl;
	int N,count = 0;
	for (int j = 0; j < 5; j++) {
		cin >> N;
		if (N < 0) continue;//continue跳过本次循环continue之后的进程，直接进入下一次循环
		if (N == 0) break;//break跳出整个循环
		if (N > 0) count++;
	}
	cout << "你输入的正数有" << count << "个" << endl;

	void* pointer = NULL;
	int var = 8;
	int* point = &var;
	*point = 9;
	cout << var << endl;
	int t = 5, m = 6;
	cout << "m=" << m << "  t=" << t << endl;
	swap(&m, &n);
	cout << "m=" << m << "  t=" << t << endl;
	Swap(m, n);
	cout << "m=" << m << "  t=" << t << endl;

	int a = 5;
	int* ptr = &a;
	int& ref = a;//相当于起了一个别名，ref不占内存
	cout << "ref=" << ref << endl;
	ref = 9;//引用一个缺点，必须对应一个变量，而且不能更改
	cout << "a=" << a << endl;
	cout << "*p=" << *ptr << endl;
	func(a);//引用的一个优点，在定义函数是直接使用变量别名可以直接调用变量
	cout << "a=" << a << endl;
	



	system("pause");
	return 0;
}

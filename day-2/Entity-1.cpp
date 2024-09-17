#include<iostream>

using namespace std;

class Entity
{
public:
	float X, Y;
	//构造函数，同名函数可以用于初始化变量
	Entity()
	{
		X = 0.0f;
		Y = 0.0f;
	}
	//构造函数，重载函数可以用于初始化变量为其他值
	Entity(float x, float y)
	{
		X = x;
		Y = y;
	}
	//同名函数加~会在作用域消失后自动调用并清除该类
  //这样的函数也叫 析构函数
	~Entity() 
	{
		cout << "Destroyed Entity!" << endl;
	}
  //初始化类变量的方式之一，每次创建类时调用，比较麻烦
	void Init() {
		X = 0.0f;
		Y = 0.0f;
	}

	void Print() {
		cout << X << "," << Y << endl;
	}
};
//测试析构函数
void Function()
{
	Entity c(0.5, -0.5);
	c.Print();
}

int main()
{
	Entity e;
	e.Print();

	/*e.Init();
	e.Print();*/

	Entity b(0.2, 0.5);
	b.Print();

	Function();//好像会把所有的entity清除？
	return 0;
}

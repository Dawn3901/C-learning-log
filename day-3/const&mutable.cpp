
#include<iostream>

using namespace std;

class Entity
{
private:
	int m_x, m_y;
	string m_name;
	 mutable int m_DebugCount = 0;
public:
	Entity(int x, int y, string name)
	{
		m_x = x;
		m_y = y;
		m_name = name;
	}

	int getX() const //const说明该类函数不会修改类的变量值
	{
		return m_x;
	}

	int getX()
	{
		return m_x;
	}
	void setX(int x) /*const*/
	{
		m_x = x;
	}

	const string& GetName() const
	{
		m_DebugCount++;
		return m_name;
	}
};

void PrintEntity(const Entity& e)//常量引用传递方式，不会再复制对象（减少内存）
{
	cout << e.getX() << endl;
}

int main()
{
	////const 类型设置初始值后无法修改value
	const float pi = 3.14159;
	//pi = 3.141592;

	//const 在* 左侧无法修改指向的值，但是可以修改指向的地址
	const float* p = &pi;
	//*p = 3.1415926;
	p = NULL;

	//const 在* 右侧无法修改指向的地址，但是可以修改指向的值
	float* const ptr = new float;
	*ptr = 2;
	//ptr = (float*)&pi;

	const Entity e(0,0,"Dawn");
	e.GetName();

	int x = 8;
	auto f = [&]()
	{
		int y = x;
		y++;
		cout << x << endl;
	};
	f();
	auto F = [=]() mutable
		{
			x++;
			cout << x << endl;
		};
	F();
	return 0;
}

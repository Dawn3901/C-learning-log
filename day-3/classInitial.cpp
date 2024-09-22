#include<iostream>

using namespace std;

class Example
{
public:
	Example()
	{
		cout << "create Example!" << endl;
	}

	Example(int x)
	{
		cout << "create Example with " << x << endl;
	}
};

class Entity
{
private:
	string m_name;
	int m_score;
	Example m_example;
public:
	/*Entity()
	{
		m_name = "Unknown";
	}
	Entity(const string& name)
	{
		m_name = name;
	}*/

	//列表初始化
	Entity()
		:m_name("Unknown"), m_score(0),m_example()
	{
		//其他表达式
	}

	Entity(const int& score, const string& name,const int &ex)
		:m_score(score), m_name(name), m_example(ex)
	{
		//其他表达式
	}

	//Entity(const int& score, const string& name, const int& ex)
	//{
	//	m_name = name;
	//	m_score = score;
	//	m_example = ex;//class的嵌套初始化这种方式会一次生成两个子类！！
	//}

	const string& GetName() const
	{
		return m_name;
	}
};

int main()
{
	Entity e0;
	cout << e0.GetName() << endl;

	Entity e1(100,"Dawn",8);
	cout << e1.GetName() << endl;

	//超出作用域后自动销毁（栈），所以运行到 } 时e所指的内容消失(F10可看)
	/*Entity* e;
	{
		Entity entity(80,"ZXH",7);
		e = &entity;
		cout << entity.GetName() << endl;
	}*/


	//使用 new 关键字在堆上创建，（慢），需要自己手动delete（所以生存期可控)
	Entity* e;
	{
		Entity* entity = new Entity(80, "ZXH", 7);
		e = entity;
		//cout << (*entity).GetName() << endl;
		cout << entity->GetName() << endl;

	}
	system("pause");
	delete e;
	return 0;
}

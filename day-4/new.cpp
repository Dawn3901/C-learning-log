#include<iostream>

using namespace std;

class Entity
{
private:
	string m_name;
public:
	Entity()
		:m_name("Unknown")
	{
		cout << "Create Entity!" << endl;
	}
	Entity(const string& name)
		:m_name(name)
	{
		cout << "Create Entity of " << name << endl;
	}
	~Entity() {
		cout << "Entity has been destroyed!" << endl;
	}
};
int main()
{
	int* a = new int;
	int* b = new int[5];
	Entity* e = new Entity();//比下面的多一点在会执行class的构造函数
	Entity* E = (Entity*)malloc(sizeof(Entity));//两种都会开辟内存并返回一个指向该内存的指针

	delete[] b;//delete清理new开的内存时，new带[],delete也要带[]
	delete e;
	free(E);//同样 malloc 的释放free 也不会执行 class 的析构函数

	return 0;
}

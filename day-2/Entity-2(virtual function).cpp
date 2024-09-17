#include<iostream>

using namespace std;

class Entity {
public:
	virtual string GetName() { return "Entity"; }//虚函数-->line 20
};

class Player : public Entity
{
private:
	string my_name;
public:
	/*Player(const string& name) {
		my_name = name;
	}*/
	Player(const string& name) : my_name(name) {}//等效于上面的赋值，构造函数的一种简化写法

	string GetName() override { return my_name; }//覆写函数
};

void PrintName(Entity* entity)
{
	cout << entity->GetName() << endl;
}

int main()
{
	Entity* e = new Entity();
	PrintName(e);

	Player* p = new Player("Dawn");
	PrintName(p);

	return 0;
}

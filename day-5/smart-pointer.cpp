#include<iostream>

class Entity
{
public:
	Entity() {
		std::cout << "Create Entity!" << std::endl;
	}
	~Entity()
	{
		std::cout << "Destroyed Entity!" << std::endl;
	}
	void Print()
	{
		std::cout << "调用成功!" << std::endl;
	}
};

int main()
{
	{
		//std::unique_ptr<Entity> entity1;//本身就是栈上建立？没有调用构造函数和析构函数？
		{
			std::unique_ptr<Entity> entity(new Entity());//堆上建立，但是智能指针会自己找时间自毁
			entity->Print();
		}//F10逐步看，就会看到unique_ptr在作用域结束时自动销毁

		//make_unique相对更加 安全
		std::unique_ptr<Entity> e = std::make_unique<Entity>();
		e->Print();
		//std::unique_ptr<Entity> e2 = e;//unique_ptr不能复制（防止一个销毁后另一个是空引用）
	}


	{
		std::shared_ptr<Entity> E;
		{
			std::shared_ptr<Entity> E1 = std::make_shared<Entity>();
			E = E1;
		}
	}
	return 0;
}

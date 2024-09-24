#include<iostream>
#include<string>
using namespace std;

//this 是一个指向this所在 class 的指针
class Entity
{
public:
	int x, y;
	/*Entity(const int& x, const int& y)
		:x(x), y(y) {}*/
	Entity(const int& x, const int& y) {
		//x=x 不再可行
		this->x = x;
		this->y = y;
		cout << "Create Entity with ";
		printf("(%d,%d)\n", this->x, this->y);
	}
	void log() const//带const就不能使用this来修改类变量
	{
		printf("(%d,%d)\n",x,y);
	}
	int size()
	{
		return x * y;
	}
	Entity GetMax(const Entity& other) {
		return Entity(this->x > other.x ? this->x : other.x, this->y > other.y ? this->y : other.y);
	}//这里的this->x换成x没有任何影响
	
	bool equals(Entity& other) {
		if (this->size() == other.size()) return true;
		else return false;
	}	
};

int main()
{
	Entity e(39, 1);
	Entity E(27, 39);
	Entity max = E.GetMax(e);
	max.log();
	if (!max.equals(E)) cout << "Not Equal!" << endl;
 	return 0;
}

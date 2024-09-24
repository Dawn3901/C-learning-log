#include<iostream>
#include<string>
using namespace std;

class Entity
{
private:
	string my_name;
	int my_score;
public:
	Entity()
		:my_name("Unknown"), my_score(0)
	{
		cout << "Create Entity!" << endl;
	}
	Entity(const string& name, const int& score)
		:my_name(name), my_score(score)
	{
		cout << "Create Entity of " << name << endl;
	}
	Entity(const string& name)
		:my_name(name),my_score(0){}
	explicit Entity(const int& score)
		:my_name("Unknown"),my_score(score) {}

};

int main()
{
	Entity a("Dawn");
	Entity b(80);
	Entity c = "Jiayue";//没懂隐式转换
	Entity d = 80;//explicit 可以禁用隐式转换,用来防止意外转换
	return 0;
}

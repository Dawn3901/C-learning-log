#include<iostream>
#include<string>
#include<stdlib.h>

using namespace std;
/*
void PrintString(string message)
{
	cout << message << endl;
}*/
//这种写法函数调用时会 copy 一个新的message，有时没有这个必要可写作下面的类型
void PrintString(const string& message)//&说明不是copy，const说明该函数不修改它
{
	cout << message << endl;
}

int main()
{
	const char* name = "Dawn";//vs 2022 must use "const"
	char Name[5] = { 'D','a','w','n',0 };//0 是终止符
	cout << name << endl;
	cout << Name << endl;

	std::string nameOfFriend = "Jiayue";//这相当于建立了一个const char*
	nameOfFriend += "Wang";

	bool contains = nameOfFriend.find("ia") != string::npos;
	if(contains) PrintString(nameOfFriend);

	const char str[9] = "ada\0aws";
	cout << strlen(str) << endl;//与实际的8不同，因为到\0终止
	cout << str << endl;

	string str1 = "hello ";
	string str2 = "World";
	string str3;
	int length;
	//copy
	str3 = str1;
	cout << str3 << endl;
	//connect
	str3 = str1 + str2;
	cout << str3 << endl;
	//size
	length = str3.size();
	cout << length << endl;
	//append在末尾添加
	str3.append("!");
	cout << str3 << endl;
	//find 查找 返回位置
	cout << str3.find("lo") << endl;
	//cout << str3.find("ol") << endl;
	//insert 
	str3.insert(5," C++");
	cout << str3 << endl;
	//replace
	str3.replace(4,6,"|what|");
	cout << str3 << endl;

	return 0;
}

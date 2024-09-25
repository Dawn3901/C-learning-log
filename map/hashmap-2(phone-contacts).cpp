#include<iostream>
#include<unordered_map>

using namespace std;

class PhoneBook
{
private:
	unordered_map<string, string> hashmap;
public:
	void addContact(const string& name,string& number)
	{
		
		if (hashmap.find(name) != hashmap.end())
		{
			number.append("/");
			number.append(hashmap[name]);
		}
		hashmap[name] = number;
		cout << "成功添加!" << endl;
	}
	string findphone(const string& name)
	{
		auto it = hashmap.find(name);
		if (it != hashmap.end()) {
			return it->second;
		}
		else {
			cout << "NOT FOUND!" << endl;
			return "NULL";
		}
	}
	void DisplayBook()
	{
		/*for (auto& pair : hashmap)
			cout << "Name:" << pair.first << "\t" << "Phone:" << pair.second << endl;
		*/
		cout << "Name\tPhone" << endl;
		for (const auto& pair : hashmap) {
			cout << pair.first << "\t" << pair.second << endl;
		}
	}
};
int main()
{
	PhoneBook contact;
	string* name = new string;
	string* phone = new string;
	
	while (1)
	{
		cout << "输入指令:(add/find/display/over)" << endl;
		string order;
		cin >> order;
		if (order == "over")
		{
			delete name;
			delete phone;
			return 0;
		}
		else if (order == "find")
		{

			cin >> *name;
			*phone = contact.findphone(*name);
			if (*phone != "NULL") cout << *name << "的电话是：" << *phone << endl;
			else cout << "未找到联系人" << endl;
		}
		else if (order == "display") {
			contact.DisplayBook();
		}
		else if (order == "add") {
			cout << "输入姓名和电话：" << endl;
			cin >> *name >> *phone;
			contact.addContact(*name, *phone);
		}
		else cout << "指令不存在！" << endl;
	}
}

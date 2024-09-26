#include<iostream>
#include<queue>
using namespace std;

queue<string> Queue;

int main()
{
	cout << "输入命令:(arrive/leave/first/last/length/over)" << endl;
	string* name = new string;
	string* FirstPerson = new string;
	string* LastPerson = new string;
	while (1)
	{
		string order;
		cin >> order;
		if (order == "arrive") {
			cin >> *name;
			Queue.push(*name);
		}
		if (order == "leave") {
			if (!Queue.empty()) {
				*FirstPerson = Queue.front();
				Queue.pop();
				cout << *FirstPerson << " left" << endl;
			}
			else cout << "Wrong! There is no person in line." << endl;
		}
		if (order == "first") {
			if (!Queue.empty()) {
				*FirstPerson = Queue.front();
				cout << "The first person is " << *FirstPerson << endl;
			}
			else cout << "Wrong! There is no person in line." << endl;
		}
		if (order == "last") {
			if (!Queue.empty()) {
				*LastPerson = Queue.back();
				cout << "The last person is " << *LastPerson << endl;
			}
			else cout << "Wrong! There is no person in line." << endl;
		}
		if (order == "length") {
			cout<<"The length of queue is " << Queue.size() << endl;
		}
		if(order == "over") break;
	}
	return 0;
}

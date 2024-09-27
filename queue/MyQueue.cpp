#include<iostream>
#include<string>
using namespace std;

struct Node
{
	string name;
	Node* next;
};

class Queue
{
private:
	Node* front;
	Node* rear;
	int size;
public:
	Queue() :front(nullptr), rear(nullptr) ,size(0) {}
  //入队
	void push(const string& name)
	{
		Node* newname = new Node;
		newname->name= name;
		if (rear == nullptr) {
			front = rear = newname;
		}
		else{
			rear->next = newname;
			rear = newname;
		}
		size++;
	}
  //出队
	string pop()
	{
		string pop;
		if (rear == nullptr) {
			pop = "NONE";
		}
		else {
			pop = front->name;
			size--;
			if (front == rear) front = rear = nullptr;
			else front = front->next;
		}
		return pop;
	}
  //队首
	string Frist()
	{
		if (rear == nullptr) {
			return "NONE";
		}
		else return front->name;
	}
 //队尾
	string Last()
	{
		if (rear == nullptr) {
			return "NONE";
		}
		else return rear->name;
	}
  //队长(chang)
	int Size()
	{
		return size;
	}
};

int main()
{
	Queue q;
	q.push("ZhangXX");
	q.push("NB");
	cout << q.Size() << endl;
	cout << q.Frist() << endl;
	cout << q.Last() << endl;
	q.pop();
	cout << q.Size() << endl;
	cout << q.Frist() << endl;
	cout << q.pop() << endl;
	cout << q.Size() << endl;
	cout << q.Frist() << endl;
	cout << q.Size() << endl;
	return 0;
}

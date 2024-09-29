#include<iostream>
#include <stdexcept>
//利用数组构造栈，简单易访问但是需要初始容量且有溢栈风险
class Stack
{
private:
	char* arr;
	int top;
	int capacity;
public:
	Stack(const int& size)
		:top(-1),capacity(size)
	{
		arr = new char[size];
	}
	~Stack()
	{
		delete[] arr;
	}

	bool isEmpty()
	{
		return top == -1;
	}

	void push(const char& ch)
	{
		if (top == capacity - 1) {
			throw std::overflow_error("The stack is Full!");
		}
		arr[++top] = ch;
	}

	char pop()
	{
		if (isEmpty()) {
			throw std::underflow_error("The Stack is Empty!");
		}
		return arr[top--];
	}

	char peek()
	{
		if (isEmpty()) {
			throw std::underflow_error("The Stack is Empty!");
		}
		return arr[top];
	}

	int size()
	{
		return top + 1;
	}
};

//链表实现栈，优点是随开随用，不会内存溢出或浪费，缺点是构造麻烦
struct Node
{
	char data;
	Node* next;
	Node(const char& ch)
		:data(ch), next(nullptr) {}
};

class Stack_chain
{
private:
	Node* top;
	int size;
public:
	Stack_chain()
		:top(nullptr),size(0) {}
	~Stack_chain()
	{
		while (top != nullptr) {
			pop();
		}
	}

	void push(const char& ch)
	{
		Node* newNode = new Node(ch);
		newNode->next = top;//新节点指向上一个（现栈顶）元素
		top = newNode;
		size++;
	}
	char pop()
	{
		if (top == nullptr) throw std::underflow_error("The Stack is Empty!");
		Node* tmp = top;
		char pop = top->data;
		top = top->next;
		delete tmp;
		size--;
		return pop;
	}
	char peek()
	{
		if (top == nullptr) throw std::underflow_error("The Stack is Empty!");
		return top->data;
	}
	int Size()
	{
		return size;
	}
};

int main()
{
	const int MAX = 100;
	Stack s1(MAX);
	///s1.pop();
	s1.push('a');
	std::cout << s1.pop() << std::endl;
	for (int i = 0; i < 5; i++) {
		s1.push('b');
	}
	std::cout << s1.pop() << std::endl;
	std::cout << s1.peek() << std::endl;
	std::cout << s1.size() << std::endl;

	Stack_chain s2;
	s2.push('(');
	std::cout << s2.pop() << std::endl;
	for (int i = 0; i < 5; i++) {
		s2.push(')');
	}
	std::cout << s2.peek() << std::endl;
	std::cout << s2.Size() << std::endl;
}

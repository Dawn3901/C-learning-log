#include<iostream>
#include <stdexcept>

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
	bool isOverflow()
	{
		return top == capacity - 1;
	}
	void push(const char& ch)
	{
		if (isOverflow()) {
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

	void pop(char& ch) {
		if (isEmpty()) {
			throw std::underflow_error("The Stack is Empty!");
		}
		ch = arr[top--];
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

void EnQueue(Stack& S1, Stack& S2, char& ch) {
	S1.push(ch);
}
void DeQueue(Stack& S1, Stack& S2, char& ch) {
	if (S2.isEmpty()) {
		while (!S1.isEmpty()) {
			S2.push(S1.pop());
		}
	}
	if (S2.isEmpty()) throw std::underflow_error("The Stacks are Empty!");
	else S2.pop(ch);
}
bool QueueEmpty(Stack& S1, Stack& S2) {
	return S1.isEmpty() && S2.isEmpty();
}

int main()
{
	
	const int max_size = 110;
	Stack S1(max_size);
	Stack S2(max_size);
	char ch = 't';
	EnQueue(S1, S2, ch);
	ch = 'e';
	EnQueue(S1, S2, ch);
	ch = 's';
	EnQueue(S1, S2, ch);
	ch = 't';
	EnQueue(S1, S2, ch);

	DeQueue(S1, S2, ch);
	std::cout << ch;
	DeQueue(S1, S2, ch);
	std::cout << ch; 
	DeQueue(S1, S2, ch);
	std::cout << ch; 
	DeQueue(S1, S2, ch);
	std::cout << ch;

	if (QueueEmpty(S1, S2)) std::cout << "\nEmpty" << std::endl;
	return 0;
}

/*入队 时间复杂度O(1),空间复杂度O(n)
FUNCTION Enqueue(S1, S2, x):
	Push(S1, x) // 将元素 x 压入栈 S1
END FUNCTION
*/
/*出队 时间复杂度O(1)~O(n),空间复杂度O(n)
FUNCTION Dequeue(S1, S2, x):
	IF StackEmpty(S2) THEN
		WHILE NOT StackEmpty(S1) DO
			Pop(S1, temp) // 从 S1 弹出元素
			Push(S2, temp) // 将元素压入 S2
		END WHILE
	END IF

	IF NOT StackEmpty(S2) THEN
		Pop(S2, x) // 从 S2 弹出元素并赋值给 x
	ELSE
		抛出异常
	END IF
END FUNCTION
*/
/*验空 时间复杂度O(1)，空间复杂度O(n)
FUNCTION QueueEmpty(S1, S2):
	RETURN StackEmpty(S1) && StackEmpty(S2) // 若 S1 和 S2 均为空，则队列为空
END FUNCTION
*/

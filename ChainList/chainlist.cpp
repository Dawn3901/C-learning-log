#include<iostream>
using namespace std;

typedef struct Node {
	int data;
	Node* next;
	Node(const int& n)
		:data(n), next(nullptr) {}
};
//typedef struct Node* List;

class ChainList
{
private:
	Node* List;
public:
	ChainList()
	{
		Node* head = new Node(-1);
		List = head;
	}
	~ChainList() 
	{
		Node* cur = this->List->next;
		while (cur != nullptr) {
			Node* tmp = cur;
			cur = cur->next;
			delete tmp;
		}
	}

	void PushBack(const int& n){
		Node* NewNode = new Node(n);
		Node* cur = this->List;
		while (cur->next != nullptr) { cur = cur->next; }
		cur->next = NewNode;
	}

	void PopBack() {
		Node* cur = this->List;
		while (cur->next->next != nullptr) {
			cur = cur->next;
		}
		Node* tmp = cur->next;
		delete tmp;
		cur->next = nullptr;
	}

	void PushFront(const int& n) {
		Node* NewNode = new Node(n);
		Node* cur = this->List;
		NewNode->next = cur->next;
		cur->next = NewNode;
	}

	void PopFront() {
		Node* tmp = this->List->next;
		List->next = tmp->next;
		delete tmp;
	}

	void Print() {
		Node* cur = this->List->next;
		while (cur->next != nullptr) {
			cout << cur->data << "->";
			cur = cur->next;
		}
		cout <<cur->data << endl;
	}

	void Reverse() {
		Node* cur = this->List->next;
		Node* next = nullptr;
		Node* prev = nullptr;
		while (cur != nullptr) {
			next = cur->next;
			cur->next = prev;
			prev = cur;
			cur = next;
		}
		this->List->next = prev;
	}

	void DeleteMin() {
		if (this->List->next == nullptr) return;
		else {
			Node* cur = this->List->next;
			Node* prev = this->List;
			Node* MinNode = cur;
			while (cur->next != nullptr) {
				if (cur->next->data < MinNode->data) {
					MinNode = cur->next;
					prev = cur;
				}
				cur = cur->next;
			}
			prev->next = MinNode->next;
			delete MinNode;
		}
	}
};

int main()
{
	ChainList list;
	list.PushBack(5);
	list.PushBack(6);
	list.PushBack(5);
	list.PushBack(8);
	list.PushBack(5);
	list.Print();
	list.PopBack();
	list.Print();

	ChainList lis;
	lis.PushFront(5);
	lis.PushFront(6);
	lis.PushFront(7);
	lis.PushFront(8);
	lis.Print();

	lis.DeleteMin();
	lis.Print();

	lis.PopFront();
	lis.Print();

	lis.Reverse();
	lis.Print();
	
	return 0;
}

/*
FUNCTION ReverseList(head):
    // head是链表的头结点
    PREV = NULL
    CURRENT = head.next // 从第一个结点开始
    NEXT = NULL

    WHILE CURRENT != NULL:
        NEXT = CURRENT.next // 保存下一个结点
        CURRENT.next = PREV // 将当前结点的指针反转
        PREV = CURRENT // 更新PREV为当前结点
        CURRENT = NEXT // 移动到下一个结点

    head.next = PREV // 更新头结点指向新的头结点
END FUNCTION
*/
/*
时间复杂度O(n)，需要遍历一次链表
空间复杂度O(1)
*/

/*
FUNCTION DeleteMinNode(head):
	IF head.next IS NULL:
		RETURN // 链表为空

	MIN_NODE = head.next // 从第一个结点开始查找最小值
	MIN_PREV = head // 保存最小值结点的前驱结点
	CURRENT = head.next // 当前结点

	WHILE CURRENT ≠ NULL:
		IF CURRENT.value < MIN_NODE.value:
			MIN_NODE = CURRENT // 更新最小值结点
			MIN_PREV = CURRENT.prev // 更新最小值结点的前驱
		CURRENT = CURRENT.next

	// 删除最小值结点
	MIN_PREV.next = MIN_NODE.next // 更新前驱结点的next指针
END FUNCTION
*/
/*
时间复杂度O(n)，需要遍历一次链表
空间复杂度O(1)
*/

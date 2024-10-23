//第一行输入链表的元素（整数）（以空格分隔）
//第二行输入N
#include<iostream>
#include<string>
#include<sstream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {} 
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class List {
public:
    ListNode* head;
public:
    List()
        :head(nullptr) {}
    List(ListNode* head)
        :head(head) {}
    void append(const int& x) {
        ListNode* NewNode = new ListNode(x);
        if (head == nullptr) head = NewNode;
        else {
            ListNode* cur = head;
            while (cur->next != nullptr) {
                cur = cur->next;
            }
            cur->next = NewNode;
        }
    }
    void display() {
        ListNode* cur = head;
        while (cur->next != nullptr) {
            cout << cur->val << ",";
            cur = cur->next;
        }
        cout << cur->val << endl;
    }
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* NewHead = new ListNode(0);
        NewHead->next = head;
        ListNode* cur = NewHead;
        ListNode* Del = NewHead;
        while (n-- && cur != nullptr) {
            cur = cur->next;
        }
        cur = cur->next;
        while (cur != nullptr) {
            cur = cur->next;
            Del = Del->next;
        }
        ListNode* tmp = Del->next;
        Del->next = tmp->next;
        delete tmp;
        return NewHead->next;
    }
};

void RemoveNthFromEnd_19() {
    List list;
    int n,x;
    string input;
    getline(cin, input);
    istringstream iss(input);
    while (iss >> x) {
        list.append(x);
    }
    cin >>n;
    Solution sol;
    List* NewList = new List(sol.removeNthFromEnd(list.head, n));
    NewList->display();
}

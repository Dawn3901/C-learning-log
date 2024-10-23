//两行分别输入两个有序链表的元素（整数，以空格分隔）
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
            while (cur->next!=nullptr) {
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode;
        ListNode* cur = head;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                cur->next = list1;
                list1 = list1->next;
            }
            else {
                cur->next = list2;
                list2 = list2->next;
            }
            cur = cur->next;
        }
        cur->next = list1 == nullptr ? list2 : list1;
        return head->next;
    }
};

void MergeList_21() {
    List list1, list2;
    string input;
    getline(cin, input);
    istringstream iss1(input);
    int x;
    while (iss1 >> x) {
        list1.append(x);
    }
    getline(cin, input);
    istringstream iss2(input);
    while (iss2 >> x) {
        list2.append(x);
    }
    Solution sol;
    List* NewList = new List(sol.mergeTwoLists(list1.head,list2.head));
    NewList->display();
}

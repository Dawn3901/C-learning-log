//第一行输入链表元素（整数，以空格分隔）
//第二行输入K
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* NewHead = new ListNode;
        NewHead->next = head;
        ListNode* cur = NewHead;
        ListNode* late = NewHead;
        int* stack = new int[k];
        while (cur != nullptr) {
            for (int i = 0; i < k; i++) {
                cur = cur->next;
                if (cur == nullptr) break;
                stack[i] = cur->val;
            }
            if (cur == nullptr) break;
            for (int i = k - 1; i >= 0; i--) {
                late = late->next;
                late->val = stack[i];
            }
        }
        return head;
    }
};

void ReverseKGroup_25() {
    int k,x;
    List list;
    string input;
    getline(cin, input);
    istringstream iss(input);
    while (iss >> x) {
        list.append(x);
    }
    cin >> k;
    Solution sol;
    List* NewList = new List(sol.reverseKGroup(list.head, k));
    NewList->display();
}

//时间复杂度O(n)
//空间复杂度O(K) 

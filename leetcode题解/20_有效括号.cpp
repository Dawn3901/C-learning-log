//输入内容只能是 {}()[]的组合
#include<iostream>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        const int MAX = 10000;
        char stack[10001];
        int top = -1;
        for (int i = 0; i < s.length(); i++) {
            if (top == -1)  stack[++top] = s[i];
            else if ((s[i] == ')' && stack[top] == '(') ||
                (s[i] == ']' && stack[top] == '[') ||
                s[i] == '}' && stack[top] == '{') {
                top--;
            }
            else
                stack[++top] = s[i];
        }
        if (top == -1)
            return true;
        else
            return false;
    }
};

void IsVaild_20() {
    string s;
    cin >> s;
    Solution sol;
    if (sol.isValid(s)) cout << "True" << endl;
    else cout << "False" << endl;
}

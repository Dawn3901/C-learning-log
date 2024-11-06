#include<iostream>
#include<vector>

using namespace std;
const int MAX = 100;
//优先级设定
int prior(const char& op) {
	switch (op) {
	case '#':return -1;
	case '!':return 5;
	case '&':return 4;
	case '|':return 3;
	case '-':return 2;
	case '+':return 1;
	case '(':return 0;
	default:return 0;
	}
}
//将原式转化为逆序波兰表达式（用两个栈实现）
string getRPN(const string& s) {
	char RPN[MAX] = { '\0' };
	char stack[MAX] = { '#' };
	int top_RPN = -1, top_stack = -1;
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] >= 'a' && s[i] <= 'z') {
			RPN[++top_RPN] = s[i]; continue;
		}
		if (s[i] == '!' || s[i] == '&' || s[i] == '+' || s[i] == '-' || s[i] == '|') {
			while (prior(s[i]) <= prior(stack[top_stack]) && top_stack > -1) RPN[++top_RPN] = stack[top_stack--];
			stack[++top_stack] = s[i]; continue;
		}
		if (s[i] == '(') {
			stack[++top_stack] = s[i]; continue;
		}
		if (s[i] == ')') {
			while (stack[top_stack] != '(' && top_stack > -1) RPN[++top_RPN] = stack[top_stack--];
			top_stack--; continue;
		}
	}
	while (top_stack > -1) RPN[++top_RPN] = stack[top_stack--];
	return RPN;
}
//根据逆序波兰表达式求真值
bool calculate(const string& RPN, const vector<bool>& values, const vector<char>& variables) {
	vector<bool> stack;
	for (int i = 0; i < RPN.length(); ++i) {
		if (RPN[i] >= 'a' && RPN[i] <= 'z') {
			int j = 0;
			//寻找命题变量对应的赋值
			for (j = 0; j < variables.size(); ++j) {
				if (variables[j] == RPN[i]) break;
			}
			stack.push_back(values[j]);
		}
		if (RPN[i] == '!') {
			bool a = stack.back();
			stack.pop_back();
			stack.push_back(!a);
		}
		if (RPN[i] == '&') {
			bool a = stack.back();
			stack.pop_back();
			bool b = stack.back();
			stack.pop_back();
			stack.push_back(a && b);
		}
		if (RPN[i] == '|') {
			bool a = stack.back();
			stack.pop_back();
			bool b = stack.back();
			stack.pop_back();
			stack.push_back(a || b);
		}
		if (RPN[i] == '-') {
			bool a = stack.back();
			stack.pop_back();
			bool b = stack.back();
			stack.pop_back();
			stack.push_back(!a || b);
		}
		if (RPN[i] == '+') {
			bool a = stack.back();
			stack.pop_back();
			bool b = stack.back();
			stack.pop_back();
			stack.push_back(a == b);
		}
	}
	return stack[0];
}

void Print_min(const vector<bool>& min, int rows) {
	cout << "主析取范式:";
	int i = 0;
	while (!min[i]) i++;
	cout << "m" << i;
	while (i < rows - 1) {
		if (min[++i]) cout << " ∨" << " m" << i;
	}
}

void Print_MAX(const vector<bool>& MAX, int rows) {
	cout << "主合取范式:";
	int j = 0;
	while (!MAX[j]) j++;
	cout << "M" << j;
	while (j < rows - 1) {
		if (MAX[++j]) cout << " ∧" << " M" << j;
	}
	cout << endl;
}

void OutPut(const vector<bool>& min, const vector<bool>& MAX, int rows) {
	bool IsTrueForever = true, IsFalseForever = true;
	for (int i = 0; i < rows; ++i) {
		if (!min[i]) IsTrueForever = false;
		if (!MAX[i]) IsFalseForever = false;
	}
	if (IsFalseForever) {
		cout << "矛盾式，主析取范式:0 ; ";
		Print_MAX(MAX, rows);
	}
	else if (IsTrueForever) {
		Print_min(min, rows);
		cout << " ; 重言式，主合取范式:1" << endl;
	}
	else {
		Print_min(min, rows);
		cout << " ; ";
		Print_MAX(MAX, rows);
	}
}

//根据所得真值求真值表以及主范式
void GenerateTruthTable(const string& RPN, const vector<char>& variables) {
	int n = variables.size();//命题变量个数
	int rows = pow(2, n);//真值表行数（也是赋值情况数）
	vector<bool> min(rows, false);
	vector<bool> MAX(rows, false);
	for (int i = 0; i < rows; ++i) {
		vector<bool> values(n);
		for (int j = 0; j < n; ++j) {
			values[j] = (i & (1 << (n - j - 1))) != 0;//循环0 01 10 11 ...
		}
		for (auto i : values) {
			cout << i;
		}
		bool result = calculate(RPN, values, variables);
		if (result) min[i] = true;
		else MAX[i] = true;
		cout << ":" << result << endl;
	}
	
	OutPut(min, MAX, rows);
}

int main()
{
	string formula;
	cin >> formula;
	vector<char> variables;
	for (char ch : formula) {
		if (ch >= 'a' && ch <= 'z' && find(variables.begin(), variables.end(), ch) == variables.end()) {
			variables.push_back(ch);
		}
	}
	GenerateTruthTable(getRPN(formula), variables);
	return 0;
}

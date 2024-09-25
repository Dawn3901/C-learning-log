#include<iostream>
#include<map>
//初次尝试map 和 创建hashmap
using namespace std;

int findminimal(const string& s)
{
	map<char, int> hashmap;
	int n =static_cast<int>(s.length());
	int i = 0;
	for (int j = 0; j < n; j++) {
		if (hashmap.find(s[j]) == hashmap.end())
		{
			hashmap.insert(pair<char, int>(s[j], i++));
			//cout << "Insert letter " << s[j] << " at " << i << endl;
		}
	}
	return i;
}

int main()
{
	string s;
	cin >> s;
	cout << findminimal(s) << endl;;
	return 0;
}

#include<iostream>
#include<vector>
using namespace std;

int main()
{
	//创建vector
	vector<int> vec1;
	vector<string> vec2;

	//初始化vector
	vec1.resize(6);
	cout << "vect1:" << endl;
	for (int i = 0; i < 6; i++) { cout << vec1[i] << " "; }
	
	vec2.resize(5, "Initial!");
	cout << "\nvect2:" << endl;
	for (int i = 0; i < 5; i++) { cout << vec2[i] << " "; }
	
	vector<int> vec3(5, 0);
	cout << "\nvect3:" << endl;
	for (int i = 0; i < 5; i++) { cout << vec3[i] << " "; }

	vector<string> vec4(2, "NO");
	cout << "\nvect4:" << endl;
	for (int i = 0; i < 2; i++) { cout << vec4[i] << " "; }

	vector<int> vec5 = { 1,2,3,5,6 };
	cout << "\nvect5:" << endl;
	for (int i = 0; i < 5; i++) { cout << vec5[i] << " "; }

	vector<int> vec6(vec5);//这种初始化两种vector需要同类型
	//等效于 vector<int> vec6 = vec5;
	cout << "\nvect6:" << endl;
	for (int i = 0; i < 5; i++) { cout << vec6[i] << " "; }

	//二维vector(vector嵌套)
	vector<vector<int>> map;

	vector<vector<bool>> IsLight(5, vector<bool>(6, false));
	vector<vector<int>> vec7(3, vector<int>(4, 39));
	cout << "\nvect7:" << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			cout << vec7[i][j] << " ";
		}
		cout << endl;
	}
	//size 和 capacity 返回vector的大小（二维实际是嵌套所以返回对应层的大小）
	cout << vec7.size() << endl;
	cout << vec7.capacity() << endl;
	//push_back后插元素,pop_back删去尾部元素
	vec1.push_back(5);
		cout << "vect1:" << endl;
		for (int i = 0; i < vec1.size(); i++) { cout << vec1[i] << " "; }
	vec1.pop_back();
		cout << "\nvect1:" << endl;
		for (int i = 0; i < vec1.size(); i++) { cout << vec1[i] << " "; }
	//insert和erase需要提供位置迭代器
	vector<int>::iterator it;
	it = vec1.begin();
	vec1.insert(it + 2, 6);
		cout << "\nvect1:" << endl;
		for (int i = 0; i < vec1.size(); i++) { cout << vec1[i] << " "; }
	vec1.erase(it + 2);
		cout << "\nvect1:" << endl;
		for (int i = 0; i < vec1.size(); i++) { cout << vec1[i] << " "; }
	//这里可以简化
	vec1.insert(vec1.begin() + 2, 5);
		cout << "\nvect1:" << endl;
		for (int i = 0; i < vec1.size(); i++) { cout << vec1[i] << " "; }

	//remove用法有些复杂
	vec5.erase(remove(vec5.begin(), vec5.end(), 2), vec5.end());
	cout << "\nvect5:" << endl;
	for (int i = 0; i < vec5.size(); i++) { cout << vec5[i] << " "; }
	//find
	it = find(vec5.begin(),vec5.end(),5);
	if (it != vec5.end()) {
		cout << "\n5在第" << distance(vec5.begin(), it) << "位";
	}
	else { cout << "未找到" << endl; }
	//clear
	vec1.clear();
		cout << "\nvect1:" << endl;
		cout << vec1.size() << endl;

	//遍历
	cout << "vect5:" << endl;
	for (int it : vec5) {
		cout << it <<" ";
	}
	cout << "\nvect4:" << endl;
	for (auto it : vec4) {
		cout << it << " ";
	}
	return 0;
}

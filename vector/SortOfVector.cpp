#include<iostream>
#include<vector>
#include<algorithm>

void Print(const std::vector<int>& v) {
	for (auto i : v) { std::cout << i << " "; }
	std::cout << std::endl;
}

bool cmp_1(const int& a, const int& b) {
	return a > b;//降序
}
bool cmp_2(const int& a, const int& b) {
	return a < b;//升序
}
bool cmp_3(const int& a, const int& b) {
	return abs(a) > abs(b);//绝对值降序
}

int main()
{
	std::vector<int> v = { 5,9,-5,5,6,-8,2,6,84,-1,0,5,6 };
	std::cout << "原数组为:" << std::endl;
	Print(v);

	std::sort(v.begin(), v.end());
	std::cout << "排序结果:" << std::endl;
	Print(v);
	
	std::reverse(v.begin(), v.end());
	std::cout << "逆序结果:" << std::endl;
	Print(v);
	
	std::sort(v.begin(), v.end(), cmp_1);
	std::cout << "降序排序结果:" << std::endl;
	Print(v);
	
	std::sort(v.begin(), v.end(), cmp_2);
	std::cout << "升序排序结果:" << std::endl;
	Print(v); 
	
	std::sort(v.begin(), v.end(), cmp_3);
	std::cout << "绝对降序排序结果:" << std::endl;
	Print(v);

	std::vector<int>::reverse_iterator it;
	std::cout <<"使用rbegin和rend逆向输出结果:" << std::endl;
	for (it = v.rbegin(); it != v.rend(); it++) {
		std::cout << *it << " ";
	}
  return 0;
}

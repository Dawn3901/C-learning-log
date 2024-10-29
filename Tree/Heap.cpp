#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void PrintHeap(const vector<int>& v) {
	for (auto i : v) {
		cout << i << " ";
	}
	cout << endl;
}

int main()
{
	//建立堆（默认大根堆）
	vector<int> max_hp = { 5,10,6,18,52,27,39,1 };
	make_heap(max_hp.begin(), max_hp.end());
	PrintHeap(max_hp);
	//添加元素
	max_hp.push_back(21);
	push_heap(max_hp.begin(), max_hp.end());
	PrintHeap(max_hp);
	//删去堆顶
	pop_heap(max_hp.begin(),max_hp.end());//这个只是把堆顶放到了数组末尾
	max_hp.pop_back();
	PrintHeap(max_hp);
	//堆排序？大根堆出来的是升序
	sort_heap(max_hp.begin(), max_hp.end());
	PrintHeap(max_hp);

	//建立小根堆
	vector<int> min_hp = { 15,5,8,6,4,46,8,39,27,65 };
	//make_heap参数最后一个是比较函数
	make_heap(min_hp.begin(), min_hp.end(), greater<int>());
	PrintHeap(min_hp);
	//堆排序？小根堆出来的是降序
	sort_heap(min_hp.begin(), min_hp.end(), greater<int>());
	PrintHeap(min_hp);

	return 0;
}

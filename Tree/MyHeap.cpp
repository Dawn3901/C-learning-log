#include<iostream>
#include<vector>

class MinHeap {
private:
	std::vector<int> heap;
	//上浮
	void siftUp(int index) {
		while (index > 0) {
			int parent = index / 2;
			if (heap[index] < heap[parent]) {
				std::swap(heap[index], heap[parent]);
				index = parent;
			}
			else break;
		}
	}
	//下沉
	void siftDown(int index) {
		while (index < heap.size()) {
			int Left = index * 2 + 1;
			int Right = index * 2 + 2;
			int Smallest = index;
			//在左孩子，右孩子和自身中找最小，如果自身小于两个孩子就已经到了合适位置，否则下移
			if (Left < heap.size() && heap[Left] < heap[index]) {
				Smallest = Left;
			}
			if (Right < heap.size() && heap[Right] < heap[index]) {
				Smallest = Right;
			}
			if (Smallest != index) {
				std::swap(heap[index], heap[Smallest]);
				index = Smallest;
			}
			else break;
		}
	}
public:
	MinHeap(std::vector<int>& v)
		:heap(v)
	{
		//反复下移排序得到小根堆
		for (int i = heap.size() / 2 - 1; i >= 0; --i) {
			siftDown(i);
		}
	}

	void push(int x) {
		heap.push_back(x);
		siftUp(heap.size()-1);
	}
	int pop() {
		if (heap.empty()) throw std::runtime_error("Heap is empty!");
		int pop = heap[0];//取头
		heap[0] = heap.back();//最后一个元素放到头部并将其下沉
		heap.pop_back();//弹出多余的最后一个元素
		siftDown(0);
		return pop;
	}
	void Print() {
		for (auto it : heap) {
			std::cout << it << " ";
		}
		std::cout << std:: endl;
	}
};


int main()
{
	std::vector<int> v = { 5,8,1,6,4,9,21,39,27 };
	MinHeap* min = new MinHeap(v);
	min->Print();
	min->push(2);
	min->Print();
	int min_x = min->pop();
	std::cout << "min_x=" << min_x << std::endl;
	min->Print();
	return 0;
}

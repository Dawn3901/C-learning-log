#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
//邻接链表的节点
typedef struct GNode {
	int vertice;
	GNode* next;
	GNode()
		:vertice(0), next(nullptr) {}
	GNode(const int& val)
		:vertice(val), next(nullptr) {}
};

class MyGragh {
private:
	int v, e;
	std::vector<int> vex;//储存元素值
	std::vector<std::vector<int>> edge;//邻接矩阵
	std::vector<GNode> vertices;//邻接链表
	std::vector<bool> visited;//DFS用，防重复
public:
	MyGragh(const int& v)
		:v(v), e(0)
	{
		vex.resize(v);
		vertices.resize(v);
		visited.resize(v, false);
		edge.resize(v, vex);
	}
	void addEdge(const int& u, const int& v) {
		edge[u][v] = 1;
		//edge[v][u] = 1;//无向边时增加
		GNode* cur = &vertices[u];
		while (cur->next != nullptr) cur = cur->next;
		GNode* NewNode = new GNode(vex[v]);
		cur->next = NewNode;
	}

	void setVex(const int& index, const int& value) {
		vex[index] = value;
		vertices[index].vertice = value;
	}

	void PrintEdgeOfGragh() {
		for (int i = 0; i < v; ++i) {
			for (int j = 0; j < v; ++j) {
				std::cout << edge[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}
	void PrintListOfGragh() {
		for (int i = 0; i < v; ++i) {
			std::cout << vex[i] << ":";
			for (int j = 0; j < v; ++j) {
				if (edge[i][j]) {
					std::cout << "->" << vex[j];
				}
			}
			std::cout << std::endl;
		}
	}
	void PrintVertices() {
		for (int i = 0; i < v; ++i) {
			GNode* cur = &vertices[i];
			while (cur != nullptr) {
				std::cout << cur->vertice << "->";
				cur = cur->next;
			}
			std::cout << "end" << std::endl;
		}
	}
	void dfs(int index) {
		visited.resize(v, false);//每次调用都要还原这个visited
		std::cout << vex[index] << "->";
		visited[index] = true;
		for (int j = 0; j < v; ++j) {
			if (edge[index][j] && !visited[j]) dfs(j);
		}
	}
};


int main()
{
	MyGragh Gra(3);
	Gra.setVex(0, 54);
	Gra.setVex(1, 39);
	Gra.setVex(2, 27);
	Gra.addEdge(0, 1);
	Gra.addEdge(0, 2);
	Gra.addEdge(1, 2);
	Gra.PrintEdgeOfGragh();
	Gra.PrintListOfGragh();
	Gra.PrintVertices();

	return 0;
}

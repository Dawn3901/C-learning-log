#include<iostream>
#include<vector>
#include<climits>
#include<queue>

const int INF=INT_MAX;
using namespace std;

class Gragh {
protected:
	vector<vector<int>> matrix;//邻接矩阵
	vector<char> vertex;//顶点
	vector<bool> visited;
	int n;
public:
	Gragh() :n(0) {
		vertex.resize(0);
		matrix.resize(0);
	}
	Gragh(int n):n(n) {
		vertex.resize(n);
		vector<int> tmp(n,INF);
		matrix.resize(n, tmp);
	}
	Gragh(vector<vector<int>> m) {
		matrix = m;
		n = static_cast<int>(m.size());
		vertex.resize(n,'a');
	}
	//初始化图（需要一个二维数组（边）和一维数组（顶点））
	Gragh(vector<char> name, vector<vector<int>> m) :vertex(name), matrix(m) {
		n = static_cast<int>(name.size());
		visited.resize(n, false);
	}
	void ClearVisited() {
		for (int i = 0; i < n; ++i) { visited[i] = false; }
	}
	void newEdge(int i, int j, int val) {
		matrix[i][j] = val;
		//matrix[j][i] = val;//无向图
	}
	int getVertex(int i, int j) {
		return matrix[i][j];
	}
	//虚函数
	virtual void Print() {
		cout << "  ";
		for (int i = 0; i < n; ++i) {
			cout << vertex[i] << " ";
		}
		cout << endl;
		for (int i = 0; i < n; ++i) {
			cout << vertex[i]<<" ";
			for (int j = 0; j < n; ++j) {
				if (matrix[i][j] == INF) cout << "x ";
				else cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
	}
	friend void DFS(Gragh& g,int index);
	friend void BFS(Gragh& g,int start);
};

struct GNode {
	int val;
	char name;
	GNode* next;
	GNode(int val,char name) :val(val),name(name), next(nullptr) {}
};

void PushBack(int val, char name,GNode*& list) {
	GNode* NewNode = new GNode(val, name);
	if (list == nullptr) {
		list = NewNode;
		return;
	}
	GNode* cur = list;
	while (cur->next != nullptr) { cur = cur->next; }
	cur->next = NewNode;
}
//邻接链表
class Gragh_List : public Gragh {
private:
	vector<GNode*> List;
public:
	Gragh_List(vector<vector<int>> m):Gragh(m){
		List.resize(n, nullptr);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (matrix[i][j] == INF||i==j) continue;
				else PushBack(matrix[i][j], vertex[j], List[i]);
			}
		}
	}
	Gragh_List(vector<char> name,vector<vector<int>> m) :Gragh(name,m) {
		List.resize(n, nullptr);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (matrix[i][j] == INF || i == j) continue;
				else PushBack(matrix[i][j], vertex[j], List[i]);
			}
		}
	}
	//虚函数覆写
	void Print() override {
		for (int i = 0; i < n; ++i) {
			cout << vertex[i] ;
			GNode* cur = List[i];
			while (cur != nullptr) {
				cout << "-" << cur->val << "->" << cur->name ;
				cur = cur->next;
			}
			cout << endl;
		}
	}
};
//递归实现深搜
void DFS(Gragh& g,int index) {
	cout << g.vertex[index] << " ";
	g.visited[index] = true;
	for (int j = 0; j < g.n; ++j) {
		if (!g.visited[j] && g.matrix[index][j] != INF && index != j) DFS(g, j);
	}
}
//队列实现广搜
void BFS(Gragh& g, int start) {
	queue<char> q;
	q.push(g.vertex[start]);
	g.visited[start] = true;

	while (!q.empty()) {
		char pop = q.front();
		q.pop();
		cout << pop << " ";
		int index = 0;
		for (index; index < g.n ; ++index) {
			if (g.vertex[index] == pop) break;
		}
		for (int j = 0; j < g.n; ++j) {
			if (!g.visited[j] && g.matrix[index][j] != INF && index != j) {
				q.push(g.vertex[j]);
				g.visited[j] = true;
			}
		}
	}
}


int main()
{
	vector<char> name= {'a', 'b', 'c','d'};
	vector<vector<int>> m = { {0,INF,INF,5} ,{INF,0,3,INF} ,{1,INF,0,3},{INF,2,INF,0} };
	Gragh m_gragh(name, m);
	m_gragh.Print();
	m_gragh.newEdge(1, 2, 5);
	m_gragh.Print();

	Gragh_List other(name,m);
	other.Print();
	
	DFS(m_gragh, 0);
	m_gragh.ClearVisited();
	cout << endl;
	BFS(m_gragh, 0);
	return 0;
}

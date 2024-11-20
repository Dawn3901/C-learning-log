#include<iostream>
#include<vector>
#include<climits>

const int INF=INT_MAX;
using namespace std;
//邻接矩阵图
class Gragh {
protected:
	vector<vector<int>> matrix;
	vector<char> edge;
	int n;
public:
	Gragh() :n(0) {
		edge.resize(0);
		matrix.resize(0);
	}
	Gragh(int n):n(n) {
		edge.resize(n);
		vector<int> tmp(n,INF);
		matrix.resize(n, tmp);
	}
	Gragh(vector<vector<int>> m) {
		matrix = m;
		n = static_cast<int>(m.size());
		edge.resize(n,'a');
	}
	Gragh(vector<char> name, vector<vector<int>> m) :edge(name), matrix(m) {
		n = static_cast<int>(name.size());
	}

	void newEdge(int i, int j, int val) {
		matrix[i][j] = val;
		//matrix[j][i] = val;//无向图
	}
	int getEdge(int i, int j) {
		return matrix[i][j];
	}
	virtual void Print() {
		cout << "  ";
		for (int i = 0; i < n; ++i) {
			cout << edge[i] << " ";
		}
		cout << endl;
		for (int i = 0; i < n; ++i) {
			cout << edge[i]<<" ";
			for (int j = 0; j < n; ++j) {
				if (matrix[i][j] == INF) cout << "x ";
				else cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
	}
};
//邻接链表节点
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
				else PushBack(matrix[i][j], edge[j], List[i]);
			}
		}
	}
	Gragh_List(vector<char> name,vector<vector<int>> m) :Gragh(name,m) {
		List.resize(n, nullptr);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (matrix[i][j] == INF || i == j) continue;
				else PushBack(matrix[i][j], edge[j], List[i]);
			}
		}
	}
	void Print() override {
		for (int i = 0; i < n; ++i) {
			cout << edge[i] ;
			GNode* cur = List[i];
			while (cur != nullptr) {
				cout << "-" << cur->val << "->" << cur->name ;
				cur = cur->next;
			}
			cout << endl;
		}
	}
};


int main()
{
	vector<char> name= {'a', 'b', 'c','d'};
	vector<vector<int>> m = { {1,INF,3,5} ,{INF,2,3,1} ,{1,INF,0,INF},{INF,INF,INF,0} };
	Gragh m_gragh(name, m);
	m_gragh.Print();
	m_gragh.newEdge(1, 2, 5);
	m_gragh.Print();

	Gragh_List other(name,m);
	other.Print();

	return 0;
}

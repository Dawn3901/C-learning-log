#include<iostream>
#include<queue>
#include<vector>

using namespace std;
//链式存储树
typedef struct TreeNode {
	int value;
	int height;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(const int& n,const int& h)
		:value(n), height(h), left(nullptr), right(nullptr) {}
};
//创建二叉树
//		1
//    2   3
//  4  5 6  7
TreeNode* createTree() {
	TreeNode* root = new TreeNode(1,1);          
	root->left = new TreeNode(2,2);       
	root->right = new TreeNode(3,2);             
	root->left->left = new TreeNode(4,3);         
	root->left->right = new TreeNode(5,3);        
	root->right->left = new TreeNode(6,3);        
	root->right->right = new TreeNode(7,3);       
	return root;
}
//前序遍历
void preOrder(TreeNode* root) {
	if (root == nullptr) return;
	cout << root->value << " ";
	preOrder(root->left);
	preOrder(root->right);
}
//保存在vector中的写法
void dfs(TreeNode* root, vector<int>& res) {
	if (root == nullptr) return;
	res.push_back(root->value);
	dfs(root->left, res);
	dfs(root->right, res);
}
vector<int> PreOrder(TreeNode* root) {
	vector<int> res;
	dfs(root, res);
	return res;
}


//中序遍历
void inOrder(TreeNode* root) {
	if (root == nullptr) return;
	inOrder(root->left);
	cout << root->value << " ";
	inOrder(root->right);
}
//后序遍历
void postOrder(TreeNode* root) {
	if (root == nullptr) return;
	postOrder(root->left);
	postOrder(root->right);
	cout << root->value << " ";
}
//层序遍历
void levelOrder(TreeNode* root) {
	if (root == nullptr) return;
	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty()) {
		TreeNode* cur = q.front();
		q.pop();
		cout << cur->value << " ";
		if (cur->left != nullptr) q.push(cur->left);
		if (cur->right != nullptr) q.push(cur->right);
	}
}

vector<vector<int>> LevelOrder(TreeNode* root) {
	if (!root) return vector<vector<int>>();
	queue<TreeNode*> que;
	vector<vector<int>> res;
	que.push(root);
	while (!que.empty()) {
		res.push_back(vector<int>());
		int size = que.size();
		for (int i = 0; i < size; ++i) {
			TreeNode* cur = que.front();
			que.pop();
			res.back().push_back(cur->value);
			if (cur->left) que.push(cur->left);
			if (cur->right) que.push(cur->right);
		}
	}
	return res;
}

//顺序存储树-完全二叉树
const int MAX = 15;
typedef struct SqBTree {
	int n=0;//结点个数
	int value[MAX] = { 0 };
};

int main()
{
	SqBTree T1;
	while(T1.n < MAX){
		T1.value[T1.n++] = rand() % (15);
	}
	for (int i=0; i < MAX; i++) {
		printf(" %2d ", i);
	}
	cout << endl;
	for (int i = 0; i < MAX; i++) {
		printf(" %2d ", T1.value[i]);
	}
	cout << endl;

	TreeNode* root = createTree();
	cout << "前序遍历：";
	preOrder(root);
	cout << endl;
	cout << "中序遍历：";
	inOrder(root);
	cout << endl;
	cout << "后序遍历：";
	postOrder(root);
	cout << endl;
	cout << "层序遍历：";
	levelOrder(root);
	cout << endl;

	vector<int> Tree = PreOrder(root);
	cout << "存储的前序遍历:" << endl;
	for (auto i : Tree) { cout << i << " "; }
	cout << endl;
	return 0;
}

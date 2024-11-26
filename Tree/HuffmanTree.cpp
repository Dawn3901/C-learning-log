#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
/*输入测试
A 27
B 8
C 15
D 15
E 30
F 5
*/

using namespace std;

struct TreeNode {
	int weight;
	char data;
	string code;
	TreeNode* left;
	TreeNode* right;
	TreeNode() :weight(0), data('\0'),code("\0") ,left(nullptr), right(nullptr) {}
	TreeNode(char name, int w) :weight(w), data(name), code("\0"),left(nullptr), right(nullptr) {}
	TreeNode(int w,TreeNode* left,TreeNode* right) :weight(w), data('#'),code("\0") ,left(left), right(right) {}
};

bool cmp(const TreeNode* a, const TreeNode* b) {
	if (a->weight > b->weight) return true;
	else return false;
}

void Code(TreeNode* root) {
	if (root == nullptr) return;
	if(root->left!=nullptr) root->left->code =root->code+ "0";
	if(root->right!=nullptr) root->right->code =root->code+ "1";
	Code(root->left);
	Code(root->right);
}

TreeNode* CreateHFMtree(vector<TreeNode*> datas) {
	while (datas.size() > 1) {
		sort(datas.begin(), datas.end(), cmp);
		TreeNode* left = datas.back();
		datas.pop_back();
		TreeNode* right = datas.back();
		datas.pop_back();
		TreeNode* root = new TreeNode(left->weight + right->weight, left, right);
		datas.push_back(root);
	}
	TreeNode* root = datas[0];
	Code(root);
	return root;
}

void InOrderTraversal(TreeNode* root,vector<TreeNode*>& res) {
	if (root == nullptr) return;
	InOrderTraversal(root->left,res);
	if(root->data!='#') res.push_back(root);
	InOrderTraversal(root->right,res);
}

int Find(char ch, vector<TreeNode*> datas) {
	for (int i = 0; i < datas.size(); ++i) {
		if (ch == datas[i]->data) return i;
	}
}

void Compression(string text,vector<TreeNode*> datas) {
	for (int i = 0; i < text.length(); ++i) {
		int j = Find(text[i], datas);
		cout << datas[j]->code;
	}
}

void DeCompression(string Code, TreeNode* root) {
	TreeNode* cur = root;
	for (int i = 0; i < Code.length(); ++i) {
		if (Code[i] == '0') cur = cur->left;
		if (Code[i] == '1') cur = cur->right;
		if (cur->data != '#') {
			cout << cur->data;
			cur = root;
		}
	}

}

int main() {
	vector<TreeNode*> datas;
	for (int i = 0; i < 6; ++i) {
		int w;
		char n;
		cin >> n >> w;
		TreeNode* newNode = new TreeNode(n ,w);
		datas.push_back(newNode);
	}
	sort(datas.begin(), datas.end(), cmp);
	for (int i = 0; i < 6; ++i) {
		cout << datas[i]->data << datas[i]->weight << " ";
	}
	cout << endl;

	TreeNode* root = CreateHFMtree(datas);
	vector<TreeNode*> res;
	InOrderTraversal(root,res);
	for (int i = 0; i < res.size(); ++i) {
		cout << res[i]->data << res[i]->code << " ";
	}
	cout << endl;
	string text = "BADCADFEED";
	Compression(text, res);
	cout << endl;
	string Code = "100101101000110110001111101";
	DeCompression(Code,root);
	return 0;
}

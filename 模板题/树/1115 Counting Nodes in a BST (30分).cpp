#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 10;
struct node {
	int value;
	node* left;
	node* right;
};

int level[maxn], cnt;

node* insert(node* root, int value) {
	if (root == nullptr) {
		root = new node;
		root->value = value;
		root->left = nullptr;
		root->right = nullptr;
		return root;
	}
	if (value <= root->value)
		root->left = insert(root->left, value);
	else if (value > root->value)
		root->right = insert(root->right, value);
	return root;
}

void DFS(node* root, int deep) {
	if (root == nullptr)
		return;
	if (deep > cnt)
		cnt = deep;
	level[deep]++;
	DFS(root->left, deep + 1);
	DFS(root->right, deep + 1);
}

int main(int argc, char const *argv[])
{
	int N, t;
	cin >> N;
	node* root = nullptr;
	for (int i = 0; i < N; ++i) {
		cin >> t;
		root = insert(root, t);
	}
	DFS(root, 0);
	printf("%d + %d = %d\n", level[cnt], level[cnt - 1], level[cnt] + level[cnt - 1]);

	return 0;
}
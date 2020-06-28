#include <bits/stdc++.h>
using namespace std;
const int maxn = 50;

struct node {
	node* left, *right;
	int data;
};
int pre[maxn];

node* build(node* root, int data) {
	if (root == NULL) {
		root = new node;
		root->left = NULL;
		root->right = NULL;
		root->data = data;
		return root;
	}
	if (abs(root->data) >= abs(data))
		root->left = build(root->left, data);
	else
		root->right = build(root->right, data);
	return root;
}

// 判断红黑结点
bool judge1(node* root) {
	if (root == NULL)
		return true;
	if (root->data < 0) {  // 红结点
		// 判断两个儿子结点是不是黑结点
		if (root->left != NULL && root->left->data < 0)
			return false;
		if (root->right != NULL && root->right->data < 0)
			return false;
	}
	return judge1(root->left) && judge1(root->right);
}

// 返回结点高度 这里的高度指黑色结点的个数(由题目条件5)
int Height(node* root) {
	if (root == NULL)
		return 0;
	int l = Height(root->left);
	int r = Height(root->right);
	return root->data > 0 ? max(l, r) + 1 : max(l, r);
}

// 判断是否平衡,根据题目条件4
bool judge2(node* root) {
	if (root == NULL)
		return true;
	int l = Height(root->left);
	int r = Height(root->right);
	if (l != r)
		return false;
	return judge2(root->left) && judge2(root->right);
}

int main(int argc, char const *argv[])
{
	int K, N;
	cin >> K;
	while (K--) {
		cin >> N;
		node* root = NULL;
		for (int i = 0; i < N; ++i) {
			cin >> pre[i];
			root = build(root, pre[i]);
		}
		if (pre[0] < 0 || !judge1(root) || !judge2(root))
			printf("No\n");
		else
			printf("Yes\n");
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int maxn = 10000 + 10;

struct node {
	int val;
	node* left;
	node* right;
};

int pre[maxn], in[maxn];
map<int, node*> mp;

node* build(int preLeft, int preRight, int inLeft, int inRight) {
	if (preLeft > preRight)
		return NULL;
	int i;
	for (i = inLeft; i <= inRight; i++)
		if (in[i] == pre[preLeft])
			break;
	node* root = new node;
	root->val = pre[preLeft];
	int leftnum = i - inLeft;
	root->left = build(preLeft + 1, preLeft + leftnum, inLeft, i - 1);
	root->right = build(preLeft + leftnum + 1, preRight, i + 1, inRight);
	mp[root->val] = root;
	return root;
}

node* LCA(node* root, node* a, node* b) {
	if (root == NULL || root == a || root == b)
		return root;
	node* left = LCA(root->left, a, b);
	node* right = LCA(root->right, a, b);
	if (left && right)
		return root;
	if (left)
		return left;
	if (right)
		return right;
	return NULL;
}

int main(int argc, char const *argv[])
{
	int M, N;
	cin >> M >> N;
	for (int i = 0; i < N; ++i)
		cin >> in[i];
	for (int i = 0; i < N; ++i)
		cin >> pre[i];
	node* root;
	root = build(0, N - 1, 0, N - 1);
	for (int i = 0; i < M; ++i) {
		int u, v;
		cin >> u >> v;
		if (!mp.count(u) && !mp.count(v))
			printf("ERROR: %d and %d are not found.\n", u, v );
		else if (!mp.count(u))
			printf("ERROR: %d is not found.\n", u);
		else if (!mp.count(v))
			printf("ERROR: %d is not found.\n", v);
		else {
			node* ans = LCA(root, mp[u], mp[v]);
			if (ans->val == u)
				printf("%d is an ancestor of %d.\n", u, v );
			else if (ans->val == v)
				printf("%d is an ancestor of %d.\n", v, u );
			else
				printf("LCA of %d and %d is %d.\n", u, v, ans->val);
		}
	}

	return 0;
}
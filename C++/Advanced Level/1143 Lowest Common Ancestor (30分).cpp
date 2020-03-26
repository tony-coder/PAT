#include <bits/stdc++.h>
using namespace std;

struct node {
	int val;
	node* left;
	node* right;
};

map<int, node*>mp;

node* insert(node* root, int v) {
	if (root == NULL) {
		root = new node;
		root->val = v;
		root->left = NULL;
		root->right = NULL;
		mp[root->val] = root;
		return root;
	}
	if (v > root->val)
		root->right = insert(root->right, v);
	else
		root->left = insert(root->left, v);
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
	int M, N, t;
	cin >> M >> N;
	node* root = NULL;
	for (int i = 0; i < N; ++i) {
		cin >> t;
		root = insert(root, t);
	}
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		if (!mp.count(a) && !mp.count(b))
			printf("ERROR: %d and %d are not found.\n", a, b );
		else if (!mp.count(a))
			printf("ERROR: %d is not found.\n", a);
		else if (!mp.count(b))
			printf("ERROR: %d is not found.\n", b);
		else {
			node* ans = LCA(root, mp[a], mp[b]);
			if (ans->val == a)
				printf("%d is an ancestor of %d.\n", a, b );
			else if (ans->val == b)
				printf("%d is an ancestor of %d.\n", b, a );
			else
				printf("LCA of %d and %d is %d.\n", a, b, ans->val);
		}
	}

	return 0;
}
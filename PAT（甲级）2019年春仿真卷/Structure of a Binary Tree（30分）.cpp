#include <bits/stdc++.h>
using namespace std;
const int maxn = 40;

struct node {
	node* left, *right, *parent;
	int val;
};
int post[maxn], in[maxn];

bool isfull = true;
map<int, int> level;
map<int, node*>mp;

node* build(int postLeft, int postRight, int inLeft, int inRight, int depth) {
	if (postLeft > postRight)
		return NULL;
	int i;
	for (i = inLeft; i < inRight; i++) {
		if (in[i] == post[postRight])
			break;
	}
	int numleft = i - inLeft;
	node* root = new node;
	root->val = post[postRight];
	level[post[postRight]] = depth;
	root->left = build(postLeft, postLeft + numleft - 1, inLeft, i - 1, depth + 1 );
	root->right = build(postLeft + numleft, postRight - 1, i + 1, inRight, depth + 1);
	if (root->left)
		root->left->parent = root;
	if (root->right)
		root->right->parent = root;
	if ((!root->left && root->right) || (root->right && !root->right))
		isfull = false;
	mp[post[postRight]] = root;
	return root;
}

void solve(string &s, node* root) {
	if (s.find("root") != string::npos) {
		int num;
		sscanf(s.c_str(), "%d is the root", &num);
		root->val == num ? printf("Yes\n") : printf("No\n");;
	} else if (s.find("siblings") != string::npos) {
		int a, b;
		sscanf(s.c_str(), "%d and %d are siblings", &a, &b);
		node* p = mp[a];
		node* q = mp[b];
		p->parent == q->parent ? printf("Yes\n") : printf("No\n");
	} else if (s.find("parent") != string::npos) {
		int a, b;
		sscanf(s.c_str(), "%d is the parent of %d", &a, &b);
		node*p = mp[a];
		node*q = mp[b];
		p == q->parent ? printf("Yes\n") : printf("No\n");
	} else if (s.find("left child") != string::npos) {
		int a, b;
		sscanf(s.c_str(), "%d is the left child of %d", &a, &b);
		node* p = mp[a], *q = mp[b];
		p == q->left ? printf("Yes\n") : printf("No\n");
	} else if (s.find("right child") != string::npos) {
		int a, b;
		sscanf(s.c_str(), "%d is the right child of %d", &a, &b);
		node *p = mp[a], *q = mp[b];
		p == q->right ? printf("Yes\n") : printf("No\n");
	} else if (s.find("level") != string::npos) {
		int a, b;
		sscanf(s.c_str(), "%d and %d are on the same level", &a, &b);
		level[a] == level[b] ? printf("Yes\n") : printf("No\n");
	} else if (s.find("full") != string::npos) {
		isfull ? printf("Yes\n") : printf("No\n");
	}
}

int main(int argc, char const *argv[])
{
	int N, M;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
		scanf("%d", &post[i]);
	for (int i = 0; i < N; ++i)
		scanf("%d", &in[i]);
	node* root = build(0, N - 1, 0, N - 1, 1);
	scanf("%d", &M);
	getchar();
	while (M--) {
		string s;
		getline(cin, s);
		solve(s, root);
	}
	return 0;
}
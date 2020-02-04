#include <bits/stdc++.h>
using namespace std;

struct node
{
	int value;
	node* left;
	node* right;
};

vector<int>pre, premirror, post, postmirror;

void insert(node*& root, int x) {
	if (root == nullptr) {
		root = new node;
		root->value = x;
		root->left = nullptr;
		root->right = nullptr;
		return;
	}
	if (x < root->value)
		insert(root->left, x);
	else
		insert(root->right, x);
}
//先序遍历
void preorder(node* root) {
	if (root == nullptr)
		return;
	pre.push_back(root->value);
	preorder(root->left);
	preorder(root->right);
}
//镜像的先序遍历
void preorder_mirror(node* root) {
	if (root == nullptr)
		return;
	premirror.push_back(root->value);
	preorder_mirror(root->right);
	preorder_mirror(root->left);
}
//后序遍历
void postorder(node* root) {
	if (root == nullptr)
		return;
	postorder(root->left);
	postorder(root->right);
	post.push_back(root->value);
}
//镜像的后序遍历
void postorder_mirror(node* root) {
	if (root == nullptr)
		return;
	postorder_mirror(root->right);
	postorder_mirror(root->left);
	postmirror.push_back(root->value);
}

bool issame(vector<int> &a, vector<int> &b) {
	for (int i = 0; i < a.size(); ++i) {
		if (a[i] != b[i])
			return false;
	}
	return true;
}

void show(vector<int> v) {
	int i;
	for (i = 0; i < v.size() - 1; ++i)
		printf("%d ", v[i] );
	printf("%d\n", v[i]);
}

int main(int argc, char const *argv[])
{
	int N;
	scanf("%d", &N);
	vector<int> v(N);
	node* root = nullptr;
	for (int i = 0; i < N; ++i) {
		scanf("%d", &v[i]);
		insert(root, v[i]);
	}
	preorder(root);
	preorder_mirror(root);
	if (issame(v, pre)) {
		printf("YES\n");
		postorder(root);
		show(post);
	} else if (issame(v, premirror)) {
		printf("YES\n");
		postorder_mirror(root);
		show(postmirror);
	}
	else
		printf("NO\n");

	return 0;
}
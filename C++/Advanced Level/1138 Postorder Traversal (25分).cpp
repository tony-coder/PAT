#include <bits/stdc++.h>
using namespace std;
const int maxn = 50000 + 10;

struct node
{
	int value;
	node* left;
	node* right;
};

int pre[maxn], in[maxn];

node* createTree(int preLeft, int preRight, int inLeft, int inRight) {
	if (preLeft > preRight)
		return nullptr;;
	int k;
	for (k = inLeft; k <= inRight; k++) {
		if (in[k] == pre[preLeft])
			break;
	}
	int numLeft = k - inLeft;
	node* root = new node;
	root->value = pre[preLeft];
	root->left = createTree(preLeft + 1, preLeft + numLeft, inLeft, k - 1);
	root->right = createTree(preLeft + numLeft + 1, preRight, k + 1, inRight);
	return root;
}

void solve(node* root, bool& flag) {
	if (!root)
		return;
	if (flag)
		solve(root->left, flag);
	if (flag)
		solve(root->right, flag);
	if (flag)
		cout << root->value << endl;
	flag = false;
}

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> pre[i];
	for (int i = 0; i < N; ++i)
		cin >> in[i];
	node* root = createTree(0, N - 1, 0, N - 1);
	bool flag = true;
	solve(root, flag);

	return 0;
}
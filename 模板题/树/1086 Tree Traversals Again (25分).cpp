#include <bits/stdc++.h>
using namespace std;

struct node {
	int value;
	node*left;
	node*right;
};
vector<int> pre, in, post;

node* build(int preLeft, int preRight, int inLeft, int inRight) {
	if (preLeft > preRight) {
		return nullptr;
	}
	int k;
	for (k = inLeft; k <= inRight; ++k) {
		if (in[k] == pre[preLeft])
			break;
	}
	int numLeft = k - inLeft;
	node* root = new node;
	root->value = pre[preLeft];
	root->left = build(preLeft + 1, preLeft + numLeft, inLeft, k - 1);
	root->right = build(preLeft + numLeft + 1, preRight, k + 1, inRight);
	return root;
}

void postOrder(node* root) {
	if (root == nullptr)
		return;
	postOrder(root->left);
	postOrder(root->right);
	post.push_back(root->value);
}

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	string op;
	int x;
	stack<int> st;
	for (int i = 0; i < 2 * N; ++i) {
		cin >> op;
		if (op == "Push") {
			cin >> x;
			pre.push_back(x);
			st.push(x);
		}
		else if (op == "Pop") {
			in.push_back(st.top());
			st.pop();
		}
	}

	node* root = build(0, N - 1, 0, N - 1);
	postOrder(root);

	int i;
	for (i = 0; i < post.size() - 1; ++i)
		printf("%d ", post[i]);
	printf("%d\n", post[i]);

	return 0;
}
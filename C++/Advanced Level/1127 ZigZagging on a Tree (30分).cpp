#include <bits/stdc++.h>
using namespace std;
const int maxn = 30 + 10;

int in[maxn], post[maxn];
vector<int> ans;
struct node {
	int val, level;
	node*left;
	node*right;
};

node* build(int postLeft, int posRight, int inLeft, int inRight) {
	if (postLeft > posRight)
		return nullptr;
	int i, numLeft;
	for (i = inLeft; i <= inRight; i++) {
		if (in[i] == post[posRight])
			break;
	}
	numLeft = i - inLeft;
	node* root = new node;
	root->val = post[posRight];
	root->left = build(postLeft, postLeft + numLeft - 1, inLeft, i - 1);
	root->right = build(postLeft + numLeft, posRight - 1, i + 1, inRight);
	return root;
}

void zigzagging_order(node* root) {
	queue<node*> q;
	root->level = 0;
	q.push(root);
	int left = 0, right = 0, level = 0;
	while (!q.empty()) {
		node* tmp = q.front();
		q.pop();
		ans.push_back(tmp->val);

		if (level != tmp->level) {
			if (level % 2 == 0)
				reverse(ans.begin() + left, ans.begin() + right );
			left = right;
		}
		if (tmp->left) {
			tmp->left->level = tmp->level + 1;
			q.push(tmp->left);
		}
		if (tmp->right) {
			tmp->right->level = tmp->level + 1;
			q.push(tmp->right);
		}
		level = tmp->level;
		right++;
	}
	if (level % 2 == 0) {
		reverse(ans.begin() + left, ans.begin() + right );
	}
}

int main(int argc, char const *argv[])
{
	int N, i;
	cin >> N;
	for (i = 0; i < N; ++i)
		cin >> in[i];
	for (i = 0; i < N; ++i)
		cin >> post[i];
	node* root = build(0, N - 1, 0, N - 1);
	zigzagging_order(root);
	for (i = 0; i < ans.size() - 1; ++i)
		cout << ans[i] << " ";
	cout << ans[i] << endl;

	return 0;
}
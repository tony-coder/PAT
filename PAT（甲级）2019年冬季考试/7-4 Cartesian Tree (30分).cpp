#include <bits/stdc++.h>
using namespace std;
const int maxn = 30 + 10;
const int INF = 0x3f3f3f3f;
struct node {
	int val;
	node* left, *right;
};

int a[maxn];

node* build(int pos, int left, int right) {
	if (left > right)
		return nullptr;
	int l = right, r = left, Min = INF;
	for (int i = left; i < pos; ++i) {
		if (a[i] > a[pos] && a[i] < Min) {
			Min = a[i];
			l = i;
		}
	}
	Min = INF;
	for (int i = pos + 1; i <= right; ++i) {
		if (a[i] > a[pos] && a[i] < Min) {
			Min = a[i];
			r = i;
		}
	}
	// cout << a[pos] << endl;
	node* root = new node();
	root->val = a[pos];
	root->left = build(l, left, pos - 1);
	root->right = build(r, pos + 1, right);

	return root;
}

vector<int> ans;
void levelOrder(node* root) {
	queue<node* >q;
	q.push(root);

	while (!q.empty()) {
		node* tmp = q.front();
		q.pop();
		ans.push_back(tmp->val);
		// cout << tmp->val << endl;
		if (tmp->left != nullptr)
			q.push(tmp->left);
		if (tmp->right != nullptr)
			q.push(tmp->right);
	}
}

int main(int argc, char const *argv[])
{
	int N, pos, Min = INF;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
		if (a[i] < Min) {
			Min = a[i];
			pos = i;
		}
	}
	node* root = build(pos, 0, N - 1);
	levelOrder(root);
	int i;
	for (i = 0; i < ans.size() - 1; ++i)
		printf("%d ", ans[i] );
	printf("%d\n", ans[i]);

	return 0;
}
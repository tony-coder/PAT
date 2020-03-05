#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 + 10;

struct node {
	int value;
	int left, right;
} tree[maxn];

int a[maxn], cnt;
vector<int> level_order;

void in_order(int root) {
	if (root == -1)
		return;
	in_order(tree[root].left);
	tree[root].value = a[cnt++];
	in_order(tree[root].right);
}

void BFS(int root) {
	queue<int> q;
	q.push(root);
	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		level_order.push_back(tree[tmp].value);
		if (tree[tmp].left != -1)
			q.push(tree[tmp].left);
		if (tree[tmp].right != -1)
			q.push(tree[tmp].right);
	}
}

int main(int argc, char const *argv[])
{
	int N, i;
	cin >> N;
	for (i = 0; i < N; ++i)
		cin >> tree[i].left >> tree[i].right;
	for (i = 0; i < N; ++i)
		cin >> a[i];
	sort(a, a + N);
	cnt = 0;
	in_order(0);
	BFS(0);
	for (i = 0; i < N - 1; ++i)
		cout << level_order[i] << " ";
	cout << level_order[i] << endl;

	return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;

struct node
{
	int left, right;
} tree[maxn];
int vis[maxn];

int Max = -1, ans;
void dfs(int root, int index) {
	if (index > Max) {
		ans = root;
		Max = index;
	}
	if (tree[root].left != -1)
		dfs(tree[root].left, index * 2);
	if (tree[root].right != -1)
		dfs(tree[root].right, index * 2 + 1);
}

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		string left, right;
		cin >> left >> right;
		if (left == "-")
			tree[i].left = -1;
		else {
			tree[i].left = stoi(left);
			vis[stoi(left)]++;
		}

		if (right == "-")
			tree[i].right = -1;
		else {
			tree[i].right = stoi(right);
			vis[stoi(right)]++;
		}
	}
	int root = 0;
	while (vis[root])
		root++;

	dfs(root, 1);
	if (Max == N)
		printf("YES %d\n", ans);
	else
		printf("NO %d\n", root);

	return 0;
}
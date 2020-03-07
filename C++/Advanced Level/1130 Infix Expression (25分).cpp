#include <bits/stdc++.h>
using namespace std;
const int maxn = 20 + 10;

struct node {
	string ch;
	int left, right;
} tree[maxn];
bool vis[maxn];

void DFS(int root, bool flag) {
	if (root == -1)
		return;
	if (flag)
		cout << "(";
	if (tree[root].left != -1) {
		if (tree[tree[root].left].left != -1 || tree[tree[root].left].right != -1)
			DFS(tree[root].left, true);  //不是叶子节点
		else
			DFS(tree[root].left, false);  //叶子节点
	}
	cout << tree[root].ch;
	if (tree[root].right != -1) {
		if (tree[tree[root].right].left != -1 || tree[tree[root].right].right != -1)
			DFS(tree[root].right, true);  //不是叶子节点
		else
			DFS(tree[root].right, false);  //叶子节点
	}
	if (flag)
		cout << ")";
}

int main(int argc, char const *argv[])
{
	int N, root = 1;
	cin >> N;
	memset(vis, false, sizeof(vis));
	for (int i = 1; i <= N; ++i) {
		cin >> tree[i].ch >> tree[i].left >> tree[i].right;
		vis[tree[i].left] = vis[tree[i].right] = true;
	}
	while (vis[root])
		root++;
	DFS(root, false);

	return 0;
}
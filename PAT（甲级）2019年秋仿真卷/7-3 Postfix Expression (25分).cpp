#include <bits/stdc++.h>
using namespace std;
const int maxn = 20 + 10;

struct node {
	char data[12];
	int left, right;
	bool flag = false;
} tree[maxn];

bool vis[maxn];

vector<char*>ans;
void solve(int root) {
	if (root == -1)
		return;
	ans.push_back("(");
	if (!tree[root].flag && strcmp(tree[root].data, "-") == 0 && (tree[root].left == -1 || tree[root].right == -1) ) {
		tree[root].flag = true;
		ans.push_back(tree[root].data);
	}
	if (!tree[root].flag && strcmp(tree[root].data, "+") == 0 && (tree[root].left == -1 || tree[root].right == -1) ) {
		tree[root].flag = true;
		ans.push_back(tree[root].data);
	}
	solve(tree[root].left);
	solve(tree[root].right);
	if (!tree[root].flag) {
		tree[root].flag = true;
		ans.push_back(tree[root].data);
	}

	ans.push_back(")");
}

int main(int argc, char const *argv[])
{
	int N;
	memset(vis, false, sizeof(vis));
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) {
		scanf("%s %d %d", tree[i].data, &tree[i].left, &tree[i].right);
		if (tree[i].left != -1)
			vis[tree[i].left] = tree;
		if (tree[i].right != -1)
			vis[tree[i].right] = tree;
	}
	int root;
	for (int i = 1; i <= N; ++i) {
		if (!vis[i])
			root = i;
	}
	// cout << root << endl;
	solve(root);
	for (int i = 0; i < ans.size(); ++i) {
		printf("%s", ans[i] );
	}

	return 0;
}
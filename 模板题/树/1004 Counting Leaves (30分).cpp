#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 + 10;

struct node
{
	int level;
	vector<int> child;
} tree[maxn];
bool vis[maxn];
int ans[maxn];

int level;
void BFS(int root) {
	queue<int> q;
	q.push(root);
	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		if (tree[tmp].child.size() == 0)
			ans[tree[tmp].level]++;
		if (tree[tmp].level > level)
			level = tree[tmp].level;
		for (int i = 0; i < tree[tmp].child.size(); ++i) {
			tree[tree[tmp].child[i]].level = tree[tmp].level + 1;
			q.push(tree[tmp].child[i]);
		}
	}
}

int main(int argc, char const *argv[])
{
	int N, M, root, k;
	cin >> N >> M;
	memset(vis, false, sizeof(vis));
	for (int i = 0; i < M; ++i) {
		int ID, K, t;
		cin >> ID >> K;
		for (int j = 0; j < K; ++j) {
			cin >> t;
			tree[ID].child.push_back(t);
			vis[t] = true;
		}
	}
	for (int i = 1; i <= N; ++i) {
		if (!vis[i]) {
			root = i;
			break;
		}
	}
	tree[root].level = 0, level = 0;
	BFS(root);
	for (k = 0; k <= level - 1; ++k)
		cout << ans[k] << " ";
	cout << ans[k] << endl;

	return 0;
}
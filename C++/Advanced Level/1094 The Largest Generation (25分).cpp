#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 + 10;

vector<int> tree[maxn];
int level[maxn];
bool vis[maxn];

void DFS(int root, int cnt) {
	level[cnt]++;
	for (int i = 0; i < tree[root].size(); ++i)
		DFS(tree[root][i], cnt + 1);
}

int main(int argc, char const *argv[])
{
	int N, M, j = 1, cnt = 0, ans, root;
	cin >> N >> M;
	memset(vis, false, sizeof(vis));
	for (int i = 0; i < M; ++i) {
		int ID, K, t;
		cin >> ID >> K;
		for (int j = 0; j < K; ++j) {
			cin >> t;
			tree[ID].push_back(t);
			vis[t] = true;
		}
	}
	for (int i = 1; i <= N; ++i) {
		if (!vis[i]) {
			root = i;
			break;
		}
	}
	DFS(root, 1);
	while (level[j] != 0) {
		if (level[j] > cnt) {
			ans = j;
			cnt = level[j];
		}
		j++;
	}
	cout << cnt << " " << ans << endl;

	return 0;
}
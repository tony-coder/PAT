#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 10;

vector<int> g[maxn];
bool vis[maxn];

void addEdge(int v, int u) {
	g[v].push_back(u);
}

bool dfs(int v) {
	if (vis[v])
		return false;
	for (int i = 0; i < g[v].size(); ++i) {
		if (!dfs(g[v][i]))
			return false;
	}
	return true;
}

int main(int argc, char const *argv[])
{
	int N, M;
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		addEdge(u, v);
	}
	int K;
	scanf("%d", &K);
	vector<int> ans;
	for (int i = 0; i < K; ++i) {
		memset(vis, false, sizeof(vis));
		vector<int> v(N);
		for (int i = 0; i < N; ++i)
			scanf("%d", &v[i]);
		int j;
		for (j = 0; j < N; ++j) {
			if (!dfs(v[j]))
				break;
			vis[v[j]] = true;
		}
		if (j != N)
			ans.push_back(i);
	}
	int k;
	for (k = 0; k < ans.size() - 1; ++k)
		printf("%d ", ans[k]);
	printf("%d\n", ans[k]);

	return 0;
}
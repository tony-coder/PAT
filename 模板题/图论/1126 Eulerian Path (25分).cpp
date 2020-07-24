#include <bits/stdc++.h>
using namespace std;
const int maxn = 500 + 10;

int degree[maxn];
vector<int> g[maxn];
bool vis[maxn];

void dfs(int v, int & cnt) {
	vis[v] = true;
	cnt++;
	for (size_t i = 0; i < g[v].size(); ++i) {
		if (!vis[g[v][i]])
			dfs(g[v][i], cnt);
	}
}

int main(int argc, char const *argv[])
{
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
		degree[u]++;
		degree[v]++;
	}
	int odd = 0, even = 0, i;
	for (i = 1; i < N; ++i) {
		if (degree[i] % 2 == 0)
			even++;
		else
			odd++;
		printf("%d ", degree[i]);
	}
	if (degree[i] % 2 == 0)
		even++;
	else
		odd++;
	printf("%d\n", degree[i]);
	int cnt = 0;
	dfs(1, cnt);
	if (cnt == N && even == N)
		printf("Eulerian\n");
	else if (cnt == N && odd == 2 && even == N - 2)
		printf("Semi-Eulerian\n");
	else
		printf("Non-Eulerian\n");

	return 0;
}
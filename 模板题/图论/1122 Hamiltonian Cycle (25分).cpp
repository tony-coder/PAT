#include <bits/stdc++.h>
using namespace std;
const int maxn = 200 + 10;

int g[maxn][maxn];
bool vis[maxn];

void addEdge(int u, int v) {
	g[u][v] = 1;
}

int main(int argc, char const *argv[])
{
	int N, M;
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		addEdge(u, v);
		addEdge(v, u);
	}
	int K;
	scanf("%d", &K);
	for (int i = 0; i < K; ++i) {
		memset(vis, false, sizeof(vis));
		int n, j;
		bool flag = true;
		scanf("%d", &n);
		vector<int> v(n);
		for (j = 0; j < n; ++j)
			scanf("%d", &v[j]);
		if (n != N + 1)
			flag = false;
		for (j = 0; j < n - 1; ++j) {
			if (g[v[j]][v[j + 1]] != 1 || vis[v[j]]) {
				flag = false;
				break;
			}
			vis[v[j]] = true;
		}
		if (flag && v[j] != v[0])
			flag = false;
		if (flag)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}
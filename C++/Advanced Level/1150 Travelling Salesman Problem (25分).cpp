#include <bits/stdc++.h>
using namespace std;
const int maxn = 200 + 10;
const int INF = 0x3f3f3f3f;

int g[maxn][maxn];
bool vis[maxn];

int main(int argc, char const *argv[])
{
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int u, v, d;
		cin >> u >> v >> d;
		g[u][v] = g[v][u] = d;
	}
	int K, res = INF, pos = 0;
	cin >> K;
	for (int k = 1; k <= K; k++) {
		memset(vis, false, sizeof(vis));
		int n, u, v, path = 0;
		bool isNa = false, isTs = true, isNot = false;
		cin >> n >> u;
		for (int i = 1; i < n; ++i) {
			cin >> v;
			if (g[u][v]) {
				if (vis[v]) // 已经访问过
					isTs = false;
				vis[v] = true;
				path += g[u][v];
			} else
				isNa = true;
			u = v;
		}
		for (int i = 1; i <= N; i++) {
			if (!vis[i]) {
				isNot = true;
				break;
			}
		}
		if (isNa)
			printf("Path %d: NA (Not a TS cycle)\n", k);
		else if (isNot)
			printf("Path %d: %d (Not a TS cycle)\n", k, path );
		else {
			if (isTs)
				printf("Path %d: %d (TS simple cycle)\n", k, path);
			else
				printf("Path %d: %d (TS cycle)\n", k, path);
			if (path < res) {
				res = path;
				pos = k;
			}
		}
	}
	printf("Shortest Dist(%d) = %d\n", pos, res );

	return 0;
}
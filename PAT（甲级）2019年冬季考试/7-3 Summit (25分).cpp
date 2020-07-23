#include <bits/stdc++.h>
using namespace std;
const int maxn = 200 + 10;

int g[maxn][maxn];
bool vis[maxn];
int main(int argc, char const *argv[])
{
	int N, M, K;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);
		g[u][v] = 1;
		g[v][u] = 1;
	}
	scanf("%d", &K);
	for (int k = 1; k <= K; ++k) {
		memset(vis, false, sizeof(vis));
		int L;
		scanf("%d", &L);
		vector<int> v(L);
		for (int i = 0; i < L; ++i)
			cin >> v[i];
		bool flag = true;
		for (int i = 0; i < L && flag; ++i) {
			for (int j = i + 1; j < L; ++j) {
				if (!g[v[i]][v[j]]) {
					flag = false;
					break;
				}
				vis[v[i]] = true;
			}
		}
		if (!flag)
			printf("Area %d needs help.\n", k);
		else {
			int i, j;
			for (i = 1; i <= N; ++i) {
				if (!vis[i]) {
					for (j = 0; j < L; ++j) {
						if (!g[i][v[j]])
							break;
					}
					if (j == L)
						break;
				}
			}
			if (i == N + 1) {
				printf("Area %d is OK.\n", k );
			} else {
				printf("Area %d may invite more people, such as %d.\n", k, i );
			}
		}
	}

	return 0;
}
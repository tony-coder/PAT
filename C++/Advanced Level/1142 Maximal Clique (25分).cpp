#include <bits/stdc++.h>
using namespace std;
const int maxn = 200 + 10;

int g[maxn][maxn];
int vis[maxn];
int main(int argc, char const *argv[])
{
	int Nv, Ne, M, k;
	cin >> Nv >> Ne;
	for (int i = 0; i < Ne; ++i) {
		int u, v;
		cin >> u >> v;
		g[u][v] = g[v][u] = 1;
	}
	cin >> M;
	while (M--) {
		bool isclique = true, ismaximal = true;
		cin >> k;
		vector<int>v(k);
		memset(vis, false, sizeof(vis));
		for (int i = 0; i < k; ++i) {
			cin >> v[i];
			vis[v[i]] = true;
		}
		for (int i = 0; i < k; ++i) {
			for (int j = i + 1; j < k; ++j) {
				if (g[v[i]][v[j]] != 1) {
					isclique = false;
					printf("Not a Clique\n");
					break;
				}
			}
			if (!isclique)
				break;
		}
		if (!isclique)
			continue;
		for (int i = 1; i <= Nv; ++i) {
			if (!vis[i]) {
				int j;
				for (j = 0; j < k; ++j) {
					if (g[i][v[j]] == 0)
						break;
				}
				if (j == k) {
					printf("Not Maximal\n");
					ismaximal = false;
				}
			}
			if (!ismaximal)
				break;
		}
		if (isclique && ismaximal)
			printf("Yes\n");
	}

	return 0;
}
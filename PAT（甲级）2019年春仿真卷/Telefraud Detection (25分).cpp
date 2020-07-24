#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;

int g[maxn][maxn];
int pre[maxn];
bool vis[maxn];

void init(int n) {
	for (int i = 0; i <= n; ++i)
		pre[i] = i;
}

int find(int x) {
	return x == pre[x] ? x : find(pre[x]);
}

void unite(int x, int y) {
	int fx = find(x);
	int fy = find(y);
	if (fx > fy)
		pre[fx] = fy;
	else if (fx < fy)
		pre[fy] = fx;
}

int main(int argc, char const *argv[])
{
	int K, N, M;
	scanf("%d %d %d", &K, &N, &M);
	init(N);
	memset(vis, false, sizeof(vis));
	for (int i = 0; i < M; ++i) {
		int caller , receiver , duration;
		scanf("%d %d %d", &caller, &receiver, &duration);
		g[caller][receiver] += duration;
	}
	vector<int>ans;
	for (int i = 1; i <= N; ++i) {
		int a = 0, b = 0;
		for (int j = 1; j <= N; ++j) {
			if (i == j)
				continue;
			if (g[i][j] > 0 && g[i][j] <= 5) {
				a++;
				if (g[j][i] > 0)
					b++;
			}
		}
		if (a > K && b * 5 < a)
			ans.push_back(i);
	}
	for (int i = 0; i < ans.size(); ++i) {
		for (int j = 0; j < ans.size(); ++j) {
			if (i == j)
				continue;
			int x = ans[i], y = ans[j];
			if (g[x][y] && g[y][x])
				unite(x, y);
		}
	}
	for (int i = 0; i < ans.size(); ++i) {
		int x = ans[i];
		if (vis[x])
			continue;
		vis[x] = true;
		printf("%d", x );
		for (int j = i + 1; j < ans.size(); ++j) {
			int y = ans[j];
			if (!vis[y] && find(x) == find(y)) {
				vis[y] = true;
				printf(" %d", y );
			}
		}
		printf("\n");
	}
	if (ans.size() == 0)
		printf("None\n");

	return 0;
}
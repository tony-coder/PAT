#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

vector<vector<int> > g(10000);
unordered_map<int, int> line; // 保存相邻两站中间的线路
bool vis[10000];
vector<int> path;
int minTransfer, minCnt;

int getTransfer(vector<int> path) {
	int cnt = 0, current = -1;
	for (int i = 1; i < path.size(); ++i) {
		if (line[path[i - 1] * 10000 + path[i]] != current)
			cnt++;
		current = line[path[i - 1] * 10000 + path[i]];
	}
	return cnt;
}

void DFS(int node, int end, int cnt, vector<int> tmpPath) {
	if (cnt > minCnt)
		return;
	tmpPath.push_back(node);
	if (node == end && (cnt < minCnt || cnt == minCnt && getTransfer(tmpPath) < minTransfer)) {
		minCnt = cnt;
		minTransfer = getTransfer(tmpPath);
		path = tmpPath;
		return;
	}
	if (node == end)
		return;
	for (int i = 0; i < g[node].size(); ++i) {
		if (!vis[g[node][i]]) {
			vis[g[node][i]] = true;
			DFS(g[node][i], end, cnt + 1, tmpPath);
			vis[g[node][i]] = false;
		}
	}
}

int main(int argc, char const *argv[])
{
	int N, K;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		int m, u, v;
		scanf("%d %d", &m, &u);
		for (int j = 1; j < m; ++j) {
			scanf("%d", &v);
			g[u].push_back(v);
			g[v].push_back(u);
			line[u * 10000 + v] = i + 1;
			line[v * 10000 + u] = i + 1;
			u = v;
		}
	}
	scanf("%d", &K);
	for (int i = 0; i < K; ++i) {
		memset(vis, false, sizeof(vis));
		int T1, T2;
		scanf("%d %d", &T1, &T2);
		path.clear();
		minCnt = minTransfer = INF;
		vector<int> tmp;
		vis[T1] = true;
		DFS(T1, T2, 0, tmp);
		printf("%d\n", minCnt);
		// for (int i = 0; i < path.size(); ++i) {
		// 	printf("%d ", path[i] );
		// }
		// printf("\n");
		int current = 0, preTransfer = T1;
		for (int i = 1; i < path.size(); ++i) {
			if (line[path[i - 1] * 10000 + path[i]] != current) {
				if (current != 0)
					printf("Take Line#%d from %04d to %04d.\n", current, preTransfer, path[i - 1] );
				current = line[path[i - 1] * 10000 + path[i]];
				preTransfer = path[i - 1];
			}
		}
		printf("Take Line#%d from %04d to %04d.\n", current, preTransfer, T2 );
	}

	return 0;
}
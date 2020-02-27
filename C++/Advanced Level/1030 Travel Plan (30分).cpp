#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 10;
const int INF = 0x3f3f3f3f;

int cost[maxn][maxn];
int dist[maxn][maxn];

int lowcost[maxn], lowdist[maxn];
bool vis[maxn];
int pre[maxn];

void init(int n) {
	memset(dist, INF, sizeof(dist));
	memset(cost, INF, sizeof(cost));
	for (int i = 0; i <= n; ++i) {
		lowcost[i] = INF;
		lowdist[i] = INF;
		vis[i] = false;
		pre[i] = -1;
	}
}

void Dijkstra(int n, int begin) {
	lowdist[begin] = lowcost[begin] = 0;

	for (int i = 0; i < n; ++i) {
		int k = -1;
		int Min = INF;
		for (int j = 0; j < n; ++j) {
			if (!vis[j] && lowdist[j] < Min) {
				Min = lowdist[j];
				k = j;
			}
		}
		if (k == -1)
			break;
		vis[k] = true;
		for (int i = 0; i < n; ++i) {
			if (!vis[i] && lowdist[k] + dist[k][i] < lowdist[i]) {
				lowdist[i] = lowdist[k] + dist[k][i];
				lowcost[i] = lowcost[k] + cost[k][i];
				pre[i] = k;
			} else if (!vis[i] && lowdist[k] + dist[k][i] == lowdist[i] && lowcost[k] + cost[k][i] < lowcost[i]) {
				lowcost[i] = lowcost[k] + cost[k][i];
				pre[i] = k;
			}
		}
	}
}

void addEdge(int cost[][maxn], int u, int v, int val) {
	cost[u][v] = val;
	cost[v][u] = val;
}

void show(int v) {
	if (pre[v] != -1) {
		show(pre[v]);
	}
	printf("%d ", v);
}

int main(int argc, char const *argv[])
{
	int N, M, S, D;
	cin >> N >> M >> S >> D;
	init(N);
	for (int i = 0; i < M; ++i) {
		int City1 , City2, Distance, Cost;
		cin >> City1 >> City2 >> Distance >> Cost;
		addEdge(dist, City1, City2, Distance);
		addEdge(cost, City1, City2, Cost);
	}
	Dijkstra(N, S);
	show(D);
	printf("%d %d\n", lowdist[D], lowcost[D]);

	return 0;
}
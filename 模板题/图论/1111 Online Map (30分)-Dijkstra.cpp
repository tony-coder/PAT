#include <bits/stdc++.h>
using namespace std;
const int maxn = 500 + 10;
const int INF = 0x3f3f3f3f;
int cost[maxn][maxn];
int Time[maxn][maxn];
int vis[maxn];
int lowcost[maxn];
int lowTime[maxn];
int pre[maxn];  // 记录路径

void init() {
	memset(cost, INF, sizeof(cost));
	memset(Time, INF, sizeof(Time));
}

// 以cost为主，time为辅
void Dijkstra1(int n, int begin) {
	// init
	for (int i = 0; i < n; ++i) {
		lowcost[i] = INF;
		lowTime[i] = INF;
		pre[i] = -1;
		vis[i] = false;
	}
	lowcost[begin] = lowTime[begin] = 0;
	for (int j = 0; j < n; ++j)
	{
		int k = -1, Min = INF;
		for (int i = 0; i < n; ++i) {
			if (!vis[i] && lowcost[i] < Min) {
				Min = lowcost[i];
				k = i;
			}
		}
		if (k == -1)
			break;
		vis[k] = true;
		// 松弛操作
		for (int i = 0; i < n; ++i) {
			if (!vis[i] && lowcost[k] + cost[k][i] < lowcost[i]) {
				lowcost[i] = lowcost[k] + cost[k][i];
				lowTime[i] = lowTime[k] + Time[k][i];
				pre[i] = k;
			} else if (!vis[i] && lowcost[k] + cost[k][i] == lowcost[i] && lowTime[k] + Time[k][i] < lowTime[i]) {
				lowTime[i] = lowTime[k] + Time[k][i];
				pre[i] = k;
			}
		}
	}
}

// 以time为主，cost为辅
void Dijkstra2(int n, int begin) {
	// init
	for (int i = 0; i < n; ++i) {
		lowcost[i] = INF;
		lowTime[i] = INF;
		pre[i] = -1;
		vis[i] = false;
	}
	lowcost[begin] = lowTime[begin] = 0;
	for (int j = 0; j < n; ++j)
	{
		int k = -1, Min = INF;
		for (int i = 0; i < n; ++i) {
			if (!vis[i] && lowTime[i] < Min) {
				Min = lowTime[i];
				k = i;
			}
		}
		if (k == -1)
			break;
		vis[k] = true;
		// 松弛操作
		for (int i = 0; i < n; ++i) {
			if (!vis[i] && lowTime[k] + Time[k][i] < lowTime[i]) {
				// lowcost[i] = lowcost[k] + cost[k][i];
				lowcost[i] = lowcost[k] + 1;
				lowTime[i] = lowTime[k] + Time[k][i];
				pre[i] = k;
			} else if (!vis[i] && lowTime[k] + Time[k][i] == lowTime[i] && lowcost[k] + 1 < lowcost[i]) {
				lowcost[i] = lowcost[k] + 1;
				pre[i] = k;
			}
		}
	}
}

void getPath(int p, vector<int>& path) {
	if (p == -1)
		return;
	path.push_back(p);
	getPath(pre[p], path);
}

int main(int argc, char const *argv[])
{
	init();
	int N, M, s, e;
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int v1, v2, one_way, l, t;
		cin >> v1 >> v2 >> one_way >> l >> t;
		if (one_way == 1) {
			cost[v1][v2] = l;
			Time[v1][v2] = t;
		} else {
			cost[v1][v2] = l;
			cost[v2][v1] = l;
			Time[v1][v2] = t;
			Time[v2][v1] = t;
		}
	}
	cin >> s >> e;

	Dijkstra1(N, s);
	int Distance = lowcost[e];
	vector<int> path1, path2;
	getPath(e, path1);

	Dijkstra2(N, s);
	int time_res = lowTime[e];
	getPath(e, path2);
	if (path1 == path2) {
		printf("Distance = %d; Time = %d: ", Distance, time_res );
		for (int i = path1.size() - 1; i > 0; --i)
			printf("%d -> ", path1[i]);
		cout << path1[0] << endl;
	} else {
		printf("Distance = %d: ", Distance );
		for (int i = path1.size() - 1; i > 0; --i)
			printf("%d -> ", path1[i]);
		cout << path1[0] << endl;
		printf("Time = %d: ", time_res );
		for (int i = path2.size() - 1; i > 0; --i)
			printf("%d -> ", path2[i]);
		cout << path2[0] << endl;
	}

	return 0;
}
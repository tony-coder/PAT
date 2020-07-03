#include <bits/stdc++.h>
using namespace std;
const int maxn = 500 + 10;
const int INF = 0x3f3f3f3f;

int cost[maxn][maxn];
int bike[maxn];
int lowcost[maxn];
bool vis[maxn];
vector<int> pre[maxn];

void init(int n) {
	memset(cost, INF, sizeof(cost));
	for (int i = 0; i <= n; ++i) {
		lowcost[i] = INF;
		vis[i] = false;
		pre[i].clear();
	}
}

void Dijkstra(int n, int begin) {
	lowcost[begin] = 0;
	for (int i = 0; i <= n; ++i) {
		int k = -1, Min = INF;
		for (int j = 0; j <= n; ++j) {
			if (!vis[j] && lowcost[j] < Min) {
				Min = lowcost[j];
				k = j;
			}
		}
		if (k == -1)
			break;
		vis[k] = true;
		for (int j = 0; j <= n; ++j) {
			if (!vis[j] && lowcost[k] + cost[k][j] < lowcost[j]) {
				lowcost[j] = lowcost[k] + cost[k][j];
				pre[j].clear();
				pre[j].push_back(k);  // 从根往后
			} else if (!vis[j] && lowcost[k] + cost[k][j] == lowcost[j]) {
				pre[j].push_back(k);
			}
		}
	}
}

int MinReq = INF, MinRes = INF;
vector<int>ans;
void DFS(int root, vector<int> tmpPath, int Cmax) {
	tmpPath.push_back(root);
	if (root == 0) {
		int curr = 0, need = 0;
		for (int i = tmpPath.size() - 2; i >= 0; --i) {
			int node = tmpPath[i];
			if (bike[node] + curr < Cmax / 2 ) {
				need += (Cmax / 2 - bike[node] - curr);
				curr = 0;
			} else {
				if (bike[node] > Cmax / 2)
					curr += bike[node] - Cmax / 2;
				else
					curr -= (Cmax / 2 - bike[node]);
			}
		}
		if (need < MinReq) {
			MinReq = need;
			MinRes = curr;
			ans = tmpPath;
		} else if (need == MinReq && curr < MinRes) {
			MinRes = curr;
			ans = tmpPath;
		}
		return;
	}
	for (size_t i = 0; i < pre[root].size(); ++i) {
		DFS(pre[root][i], tmpPath, Cmax);
	}
}

int main(int argc, char const *argv[])
{
	int Cmax, N, Sp, M;
	cin >> Cmax >> N >> Sp >> M;
	init(N);
	for (int i = 1; i <= N; ++i) {
		cin >> bike[i];
	}
	for (int i = 0; i < M; ++i) {
		int si, sj, tij;
		cin >> si >> sj >> tij;
		cost[si][sj] = tij;
		cost[sj][si] = tij;
	}
	Dijkstra(N, 0);
	vector<int> tmp;
	DFS(Sp, tmp, Cmax);
	printf("%d ", MinReq);
	for (int i = ans.size() - 1; i > 0 ; --i)
		printf("%d->", ans[i]);
	printf("%d ", ans[0]);
	printf("%d\n", MinRes );

	return 0;
}
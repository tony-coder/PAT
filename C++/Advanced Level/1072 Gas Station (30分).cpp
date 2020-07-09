#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 1000 + 10 + 10;

// vector<int> cost[maxn];
int cost[maxn][maxn];
int lowcost[maxn];
int vis[maxn];

void Dijkstra(int n, int begin) {
	for (int i = 1; i <= n; ++i) {
		lowcost[i] = INF;
		vis[i] = false;
	}
	lowcost[begin] = 0;
	for (int j = 0; j < n; ++j) {
		int k = -1, Min = INF;
		for (int i = 1; i <= n; ++i) {
			if (!vis[i] && lowcost[i] < Min) {
				Min = lowcost[i];
				k = i;
			}
		}
		if (k == -1)
			break;
		vis[k] = true;
		for (int i = 1; i <= n; ++i) {
			if (!vis[i] && lowcost[k] + cost[k][i] < lowcost[i]) {
				lowcost[i] = lowcost[k] + cost[k][i];
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	int N, M, K, Ds;
	scanf("%d %d %d %d", &N, &M, &K, &Ds);
	memset(cost, INF, sizeof(cost));
	memset(lowcost, INF, sizeof(INF));
	memset(vis, false, sizeof(vis));
	for (int i = 0; i < K; ++i) {
		string P1, P2;
		int Dist, u, v;
		cin >> P1 >> P2 >> Dist;
		if (P1[0] == 'G')
			u = N + P1[1] - '0';
		else
			u = stoi(P1);
		if (P2[0] == 'G')
			v = N + P2[1] - '0';
		else
			v = stoi(P2);
		if (Dist < cost[u][v])
			cost[u][v] = Dist;
		if (Dist < cost[v][u])
			cost[v][u] = Dist;
	}
	// 测试每个候选点
	int ans_id = -1, max_dist = 0, tot_dist = 0;
	for (int i = N + 1; i <= N + M; ++i) {
		Dijkstra(N + M, i);
		int temp_tot_dist = 0, temp_min_dist = INF, j;
		for (j = 1; j <= N; ++j) {
			temp_tot_dist += lowcost[j];
			if (lowcost[j] < temp_min_dist)
				temp_min_dist = lowcost[j];
			if (lowcost[j] > Ds)
				break;
		}
		if (j != N + 1)
			continue;
		if (temp_min_dist > max_dist) {
			max_dist = temp_min_dist;
			tot_dist = temp_tot_dist ;
			ans_id = i;
		} else if (temp_min_dist == max_dist) {
			if (temp_tot_dist < tot_dist) {
				tot_dist = temp_tot_dist ;
				ans_id = i;
			}
		}
	}
	if (ans_id != -1) {
		// 精度四舍五入到小数点后一位
		double average_dist = double(tot_dist) / N;
		int temp = round(average_dist * 10);
		average_dist = double(temp) / 10;
		printf("G%d\n", ans_id - N);
		printf("%.1f %.1f\n", double(max_dist), average_dist );
	} else
		printf("No Solution\n");

	return 0;
}
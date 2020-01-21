#include <bits/stdc++.h>
using namespace std;
const int maxn = 500 + 10;
const int INF = 0x3f3f3f3f;

int cost[maxn][maxn];  //邻接矩阵
int lowcost[maxn];  //lowcost[x]是起点到x的距离的估算距离
bool vis[maxn];
int pre[maxn];
int person[maxn];
int lowperson[maxn];
int num[maxn];
int n;

void Dijkstra(int cost[][maxn], int lowcost[], int n, int begin)
{
	//init
	for (int i = 0; i < n; ++i)
	{
		lowcost[i] = INF;
		lowperson[i] = -1;
		num[i] = 0;
		vis[i] = false;
		pre[i] = -1;
	}

	lowcost[begin] = 0;
	lowperson[begin] = person[begin];
	num[begin] = 1;
	for (int i = 0; i < n; ++i)
	{
		int k = -1;
		int Min = INF;
		//找到在未访问过顶点中权值最小的点
		for (int i = 0; i < n; ++i)
		{
			if (!vis[i] && lowcost[i] < Min)
			{
				Min = lowcost[i];
				k = i;
			}
		}
		if (k == -1)
			break;
		vis[k] = true;
		//松弛操作
		for (int i = 0; i < n; ++i)
		{
			if (!vis[i] && (lowcost[k] + cost[k][i] < lowcost[i] ))
			{
				lowcost[i] = lowcost[k] + cost[k][i];
				lowperson[i] = lowperson[k] + person[i];
				pre[i] = k;
				num[i] = num[k];
			}
			else if (lowcost[k] + cost[k][i] == lowcost[i])
			{
				if (lowperson[k] + person[i] > lowperson[i])
				{
					lowcost[i] = lowcost[k] + cost[k][i];
					lowperson[i] = lowperson[k] + person[i];
					pre[i] = k;
				}
				num[i] = num[i] + num[k];
			}
		}
	}
}

void addedge(int cost[][maxn], int u, int v, int val)
{
	cost[u][v] = val;
	cost[v][u] = val;
}

int main(int argc, char const *argv[])
{
	int N, M, C1, C2;
	cin >> N >> M >> C1 >> C2;
	for (int i = 0; i < N; i++)
	{
		cin >> person[i];
	}
	memset(cost, INF, sizeof(cost));

	for (int i = 0; i < M; i++)
	{
		int c1, c2, L;
		cin >> c1 >> c2 >> L;
		addedge(cost, c1, c2, L);
	}

	Dijkstra(cost, lowcost, N, C1);;

	// for (int i = 0; i < N; ++i)
	// {
	// 	cout << num[i] << " " << lowcost[i] << "  " << lowperson[i] << endl;
	// }
	cout << num[C2] << " " << lowperson[C2];

	return 0;
}
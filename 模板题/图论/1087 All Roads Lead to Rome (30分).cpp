#include <bits/stdc++.h>
using namespace std;
const int maxn = 200 + 10;
const int INF = 0x3f3f3f3f;

int cost[maxn][maxn];
int happiness[maxn];
int lowcost[maxn], mosthappiness[maxn];
bool vis[maxn];
int pre[maxn];
int node[maxn];  // 从起点到i点经过的顶点数
int num[maxn];  // 路径个数

int cnt;
map<string, int> mp1;
map<int, string> mp2;

void addCity(string c) {
	mp1[c] = cnt;
	mp2[cnt++] = c;
}

void init(int n) {
	// init
	memset(cost, INF, sizeof(cost));
	memset(happiness, 0, sizeof(happiness));
	for (int i = 0; i < n; ++i) {
		lowcost[i] = INF;
		happiness[i] = 0;
		vis[i] = false;
		pre[i] = -1;
		node[i] = 0;
		num[i] = 0;
	}
}

void Dijkstra(int n, int begin) {
	lowcost[begin] = mosthappiness[begin] = 0;
	num[begin] = 1;
	for (int i = 0; i < n; ++i) {
		// 找当前最短路径
		int k = -1, Min = INF;
		for (int j = 0; j < n; ++j) {
			if (!vis[j] && lowcost[j] < Min) {
				Min = lowcost[j];
				k = j;
			}
		}
		if (k == -1)
			break;
		// 当前访问节点
		vis[k] = true;
		for (int j = 0; j < n; ++j) {
			if (!vis[j] && lowcost[k] + cost[k][j] < lowcost[j]) {
				lowcost[j] = lowcost[k] + cost[k][j];
				mosthappiness[j] = mosthappiness[k] + happiness[j];
				pre[j] = k;
				node[j] = node[k] + 1;
				num[j] = num[k];
			} else if (!vis[j] && lowcost[k] + cost[k][j] == lowcost[j]) {
				num[j] += num[k];
				if ( mosthappiness[k] + happiness[j] > mosthappiness[j]) {
					mosthappiness[j] = mosthappiness[k] + happiness[j];
					pre[j] = k;
					node[j] = node[k] + 1;
				} else if ( mosthappiness[k] + happiness[j] == mosthappiness[j]) {
					double uAvg = 1.0 * (mosthappiness[k] + happiness[j]) / (node[k] + 1);
					double vAvg = 1.0 * (mosthappiness[j] / node[j]);
					if (uAvg > vAvg) {
						node[j] = node[k] + 1;
						pre[j] = k;
					}
				}
			}
		}
	}
}

vector<string> path;
void getPath(int end) {
	if (end == -1)
		return;
	path.push_back(mp2[end]);
	getPath(pre[end]);
}

int main(int argc, char const *argv[])
{
	int N, K;
	string begin;
	cin >> N >> K >> begin;
	init(N);
	addCity(begin);
	for (int i = 0; i < N - 1; ++i) {
		string c;
		int h;
		cin >> c >> h;
		addCity(c);
		happiness[mp1[c]] = h;
	}
	for (int i = 0; i < K; ++i) {
		string u, v;
		int c;
		cin >> u >> v >> c;
		cost[mp1[u]][mp1[v]] = c;
		cost[mp1[v]][mp1[u]] = c;
	}

	Dijkstra(cnt, mp1[begin]);
	// cout << lowcost[mp1["ROM"]] << endl;
	getPath(mp1["ROM"]);
	cout << num[mp1["ROM"]] << " ";
	cout << lowcost[mp1["ROM"]] << " ";
	cout << mosthappiness[mp1["ROM"]] << " ";
	cout << mosthappiness[mp1["ROM"]] / node[mp1["ROM"]] << endl;
	for (int i = path.size() - 1; i > 0; --i)
		cout << path[i] << "->";
	cout << path[0] << endl;

	return 0;
}
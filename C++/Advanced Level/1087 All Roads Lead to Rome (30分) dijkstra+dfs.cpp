#include <bits/stdc++.h>
using namespace std;
const int maxn = 200 + 10;
const int INF = 0x3f3f3f3f;

int cost[maxn][maxn];
int happiness[maxn];
int lowcost[maxn];
bool vis[maxn];
vector<int>pre[maxn];
vector<int> path;
int cnt;
map<string, int> mp1;
map<int, string> mp2;

void init(int n) {
	memset(cost, INF, sizeof(cost));
	memset(happiness, 0, sizeof(happiness));
	for (int i = 0; i < n; ++i) {
		lowcost[i] = INF;
		vis[i] = false;
		pre[i].clear();
	}
}

void Dijkstra(int n, int begin) {
	lowcost[begin] = 0;
	for (int i = 0; i < n; ++i) {
		int k = -1, Min = INF;
		for (int j = 0; j < n; ++j) {
			if (!vis[j] && lowcost[j] < Min) {
				Min = lowcost[j];
				k = j;
			}
		}
		if (k == -1)
			break;
		vis[k] = true;
		for (int j = 0; j < n; ++j) {
			if (!vis[j] && lowcost[k] + cost[k][j] < lowcost[j]) {
				lowcost[j] = lowcost[k] + cost[k][j];
				pre[j].clear();
				pre[j].push_back(k);
			} else if (!vis[j] && lowcost[k] + cost[k][j] == lowcost[j])
				pre[j].push_back(k);
		}
	}
}

int mosthappiness, pathcnt;

// dfs找符合要求的路径，同时统计信息
void dfs(int root, vector<int> tmpPath, int currentHappiness) {
	tmpPath.push_back(root);
	currentHappiness += happiness[root];
	if (root == 0) {
		pathcnt++;  // 最短路径数
		if (currentHappiness > mosthappiness) {
			mosthappiness = currentHappiness;
			path = tmpPath;
		} else if (currentHappiness == mosthappiness) {
			if (tmpPath.size() < path.size())
				path = tmpPath;
		}

		return;
	}
	for (int i = 0; i < pre[root].size(); ++i)
		dfs(pre[root][i], tmpPath, currentHappiness);
}

void addCity(string c) {
	mp1[c] = cnt;
	mp2[cnt++] = c;
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
	vector<int> tmp;
	dfs(mp1["ROM"], tmp, 0);

	printf("%d %d %d %d\n", pathcnt, lowcost[mp1["ROM"]], mosthappiness, mosthappiness / (path.size() - 1));
	int i;
	for (i = path.size() - 1; i > 0; --i)
		cout << mp2[path[i]] << "->";
	cout << mp2[path[i]] << endl;

	return 0;
}
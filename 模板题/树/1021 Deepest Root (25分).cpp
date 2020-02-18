#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;

vector<int> g[maxn];
bool vis[maxn];
vector<int> tmp;
set<int> ans;

void dfs(int node, int height, int& maxheight) {
	if (height > maxheight) {
		tmp.clear();
		tmp.push_back(node);
		maxheight = height;
	} else if (height == maxheight) {
		tmp.push_back(node);
	}
	vis[node] = true;

	for (int i = 0; i < g[node].size(); ++i) {
		if (!vis[g[node][i]])
			dfs(g[node][i], height + 1, maxheight);
	}

}

void addEdge(int u, int v) {
	g[u].push_back(v);
	g[v].push_back(u);
}

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	memset(vis, false, sizeof(vis));
	for (int i = 0; i < N - 1; ++i) {
		int u, v;
		cin >> u >> v;
		addEdge(u, v);
	}
	int cnt = 0, t, maxheight = 1;
	for (int i = 1; i <= N; ++i) {
		if (!vis[i]) {
			dfs(i, 1, maxheight);
			if (tmp.size() != 0)
				t = tmp[0];
			for (int j = 0; j < tmp.size(); ++j)
				ans.insert(tmp[j]);
			cnt++;
		}
	}

	if (cnt >= 2)
		printf("Error: %d components\n", cnt); //连通分量数
	else {
		tmp.clear();
		memset(vis, false, sizeof(vis));
		maxheight = 1;
		dfs(t, 1, maxheight);
		for (int j = 0; j < tmp.size(); ++j)
			ans.insert(tmp[j]);
		for (auto t : ans)
			cout << t << endl;
	}

	return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 10;

vector<int> g[maxn];
bool vis[maxn];  //vis表示是否已经被访问
int layer[maxn];  //储存每个结点被遍历到时的层数
int N, L;

void dfs(int u, int level) {
	if (level == L + 1)
		return;
	vis[u] = true;  //当前结点置为已访问
	layer[u] = level; //更新被遍历时所处层数
	for (auto i : g[u]) {
		if (!vis[i] || layer[i] > level + 1) { //这个节点以前从未访问过或者这个节点当前被访问时的层数<layer数组中对应的层数
			dfs(i, level + 1);
		}
	}
}

void addEdgr(int u, int v) {
	g[u].push_back(v);
}

int main(int argc, char const *argv[])
{
	cin >> N >> L;
	for (int u = 1; u <= N; ++u) {
		int M, v;
		cin >> M;
		for (int j = 0; j < M; ++j) {
			cin >> v;
			addEdgr(v, u);
		}
	}
	int K, id, ans;
	cin >> K;
	for (int i = 0; i < K; ++i) {
		cin >> id;
		memset(vis, false, sizeof(vis));
		memset(vis, -1, sizeof(layer));
		ans = 0;
		dfs(id, 0);
		for (int i = 1; i <= N ; ++i)  ////遍历layer数组，元素>0的即为符合条件的人，进行递增
			ans += layer[i] > 0 ? 1 : 0;
		cout << ans << endl;
	}

	return 0;
}
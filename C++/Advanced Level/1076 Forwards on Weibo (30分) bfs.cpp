#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 10;

vector<int>g[maxn];
int N, L;

int bfs(int u) {
	int ans = 0, level[N + 1] = {0}; //level表示用户转发时所处的转发层数
	bool vis[N + 1] = {false};
	queue<int>q;
	q.push(u);
	vis[u] = true;
	while (!q.empty()) {
		int t = q.front();
		q.pop();
		for (auto i : g[t]) {
			if (!vis[i] && level[t] < L) {
				ans++;
				level[i] = level[t] + 1;
				vis[i] = true;
				q.push(i);
			}
		}
	}
	return ans;
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
	int K, id;
	cin >> K;
	for (int i = 0; i < K; ++i) {
		cin >> id;
		cout << bfs(id) << endl;

	}
	return 0;
}
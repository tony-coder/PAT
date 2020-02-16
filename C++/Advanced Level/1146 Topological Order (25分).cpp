#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 10;

vector<int> g[maxn];
int in[maxn];  //入度

void addEdge(int u, int v) {
	g[u].push_back(v);
}

int main(int argc, char const *argv[])
{
	int N, M, K, i;
	scanf("%d%d", &N, &M);
	for (i = 0; i < M; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		addEdge(u, v);
		in[v]++;  //入度加1
	}
	scanf("%d", &K);
	vector<int> ans;
	for (i = 0; i < K; ++i) {
		bool judge = true;
		vector<int> tin(in, in + N + 1);
		for (int j = 0; j < N; ++j) {
			int t;
			scanf("%d", &t);
			if (tin[t] != 0) //如果入度不为0，则为假
				judge = false;
			for (auto it : g[t]) //将该点对应的入度减去1
				tin[it]--;
		}
		if (!judge)
			ans.push_back(i);
	}
	for (i = 0; i < ans.size() - 1; ++i)
		printf("%d ", ans[i]);
	printf("%d\n", ans[i]);

	return 0;
}
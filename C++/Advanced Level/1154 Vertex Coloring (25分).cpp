#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;

int main(int argc, char const *argv[])
{
	int N, M, K, u, v, i;
	cin >> N >> M;
	vector<pair<int, int> >g;
	for (i = 0; i < M; ++i) {
		cin >> u >> v;
		g.push_back(make_pair(u, v));
	}
	cin >> K;
	while (K--) {
		set<int> color;
		vector<int> a(N);
		for (i = 0; i < N; ++i) {
			cin >> a[i];
			color.insert(a[i]);
		}
		for (i = 0; i < M; ++i)
			if (a[g[i].first] == a[g[i].second])
				break;
		if (i == M)
			printf("%d-coloring\n", color.size());
		else
			printf("No\n");
	}

	return 0;
}
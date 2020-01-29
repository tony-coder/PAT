#include <bits/stdc++.h>
using namespace std;
const int maxn = 2500 + 10;

vector<string> vis[maxn];
int main(int argc, char const *argv[])
{
	// ios::sync_with_stdio(false);
	// cin.tie(0);
	int N, K;
	// cin >> N >> K;
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; ++i)
	{
		string name;
		name.resize(5);
		int cnt, c;
		// cin >> name >> cnt;
		scanf("%s %d", &name[0], &cnt);
		for (int i = 0; i < cnt; ++i)
		{
			scanf("%d", &c);
			vis[c].push_back(name);
		}
	}
	for (int i = 1; i <= K; ++i)
	{
		// cout << i << " " << vis[i].size() << endl;
		printf("%d %d\n", i, vis[i].size());
		if (vis[i].size() == 0)
			continue;
		sort(vis[i].begin(), vis[i].end());
		for (int j = 0; j < vis[i].size(); ++j)
			printf("%s\n", vis[i][j].c_str());
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int N, M;
	scanf("%d%d", &N, &M);
	map<int, vector<int> > mp;
	for (int i = 0; i < N; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	set<int> s;
	for (int i = 0; i < M; ++i) {
		int K, t, j;
		scanf("%d", &K);
		s.clear();
		for (j = 0; j < K; ++j) {
			scanf("%d", &t);
			s.insert(t);
		}
		auto it = s.begin();
		for (; it != s.end(); it++) {
			if (mp.count(*it)) {
				bool flag = false;
				for (int k = 0; k < mp[*it].size(); ++k) {
					if (s.find(mp[*it][k]) != s.end()) {
						flag = true;
						break;
					}
				}
				if (flag)
					break;
			}
		}
		if (it != s.end())
			printf("No\n");
		else
			printf("Yes\n");
	}

	return 0;
}
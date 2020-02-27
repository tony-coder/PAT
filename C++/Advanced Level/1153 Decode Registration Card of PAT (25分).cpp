#include <bits/stdc++.h>
using namespace std;

struct node
{
	string type;
	int term;
};

bool cmp(node& a, node& b) {
	return a.term == b.term ? a.type<b.type: a.term>b.term;
}

int main(int argc, char const *argv[])
{
	int N, M;
	cin >> N >> M;
	vector<node> v(N);
	for (int i = 0; i < N; ++i)
		cin >> v[i].type >> v[i].term;
	int type;
	string s;
	for (int i = 1; i <= M; ++i) {
		cin >> type >> s;
		vector<node> ans;
		printf("Case %d: %d %s\n", i, type, s.c_str());
		int cnt = 0, sum = 0;
		if (type == 1) {
			for (int j = 0; j < N; ++j) {
				if (v[j].type[0] == s[0])
					ans.push_back(v[j]);
			}
		} else if (type == 2) {
			for (int j = 0; j < N; ++j) {
				if (v[j].type.substr(1, 3) == s) {
					cnt++;
					sum += v[j].term;
				}
			}
			if (cnt != 0)
				printf("%d %d\n", cnt, sum);
		} else if (type == 3) {
			unordered_map<string, int> mp;
			for (int j = 0; j < N; ++j) {
				if (v[j].type.substr(4, 6) == s)
					mp[v[j].type.substr(1, 3)]++;
			}
			for (auto t : mp)
				ans.push_back({t.first, t.second});
		}
		sort(ans.begin(), ans.end(), cmp);
		if (((type == 1 || type == 3) && ans.size() == 0) || (type == 2 && cnt == 0))
			printf("NA\n");
		else {
			for (auto t : ans)
				printf("%s %d\n", t.type.c_str(), t.term);
		}
	}

	return 0;
}
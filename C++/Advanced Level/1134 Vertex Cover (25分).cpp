#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;

int main(int argc, char const *argv[])
{
	vector<pair<int, int> >edges;
	int N, M, K;
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int u, v;
		cin >> u >> v;
		edges.push_back(make_pair(u, v));
	}
	cin >> K;
	for (int i = 0; i < K; ++i) {
		int Nv, t;
		cin >> Nv;
		set<int> v;
		for (int i = 0; i < Nv; ++i) {
			cin >> t;
			v.insert(t);
		}
		bool flag = true;
		for (int i = 0; i < M; ++i) {
			if (v.find(edges[i].first) == v.end()
			        && v.find(edges[i].second) == v.end()) {
				flag = false;
				break;
			}
		}
		if (flag)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}

	return 0;
}
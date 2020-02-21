#include <bits/stdc++.h>
using namespace std;

struct node
{
	string id;
	int Gp, mid_term, final, G;
	node(): Gp(-1), mid_term(-1), final(-1), G(-1) {}

	bool operator<(const node& n)const {
		return G == n.G ? id < n.id : G > n.G;
	}
};

int main(int argc, char const *argv[])
{
	int P, M, N;
	cin >> P >> M >> N;
	unordered_map<string, node> mp;
	string id;
	int t;
	for (int i = 0; i < P; ++i) {
		cin >> id >> t;
		mp[id].id = id;
		mp[id].Gp = t;
	}
	for (int i = 0; i < M; ++i) {
		cin >> id >> t;
		mp[id].mid_term = t;
	}
	for (int i = 0; i < N; ++i) {
		cin >> id >> t;
		mp[id].final = t;
	}
	vector<node> ans;
	for (auto& t : mp) {
		if (t.second.mid_term > t.second.final)
			t.second.G = round((double)t.second.mid_term * (0.4) + (double)t.second.final * 0.6);
		else
			t.second.G = t.second.final;

		if (t.second.Gp >= 200 && (t.second.G <= 100 && t.second.G >= 60))
			ans.push_back(t.second);
	}
	sort(ans.begin(), ans.end());

	for (auto t : ans) {
		printf("%s %d %d %d %d\n", t.id.c_str(), t.Gp, t.mid_term, t.final, t.G);
	}

	return 0;
}
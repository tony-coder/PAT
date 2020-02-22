#include <bits/stdc++.h>
using namespace std;

struct node {
	string School;
	int A, B, T, TwS, Ns, Rank;
};

bool cmp(node& a, node& b) {
	if (a.TwS == b.TwS) {
		if (a.Ns == b.Ns)
			return a.School < b.School;
		else
			return a.Ns < b.Ns;
	} else
		return a.TwS > b.TwS;
}

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	unordered_map<string, node> mp;
	for (int i = 0; i < N; ++i)
	{
		string id, school;
		int score;
		cin >> id >> score >> school;
		transform(school.begin(), school.end(), school.begin(), ::tolower);
		if (mp.count(school) == 0)
			mp[school] = {school, 0, 0, 0, 0, 0, 0};
		if (id[0] == 'B')
			mp[school].B += score;
		else if (id[0] == 'A')
			mp[school].A += score;
		else
			mp[school].T += score;
		mp[school].Ns++;
	}
	vector<node>ans;
	for (auto& t : mp) {
		t.second.TwS = int(t.second.A + double(t.second.B) / 1.5 + double(t.second.T) * 1.5);
		ans.push_back(t.second);
	}
	sort(ans.begin(), ans.end(), cmp);
	ans[0].Rank = 1;
	for (int i = 1; i < ans.size(); ++i) {
		if (ans[i].TwS == ans[i - 1].TwS)
			ans[i].Rank = ans[i - 1].Rank;
		else
			ans[i].Rank = i + 1;
	}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i].Rank << " " << ans[i].School << " " << (int)ans[i].TwS << " " << ans[i].Ns << endl;
	}

	return 0;
}
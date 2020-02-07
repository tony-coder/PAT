#include <bits/stdc++.h>
using namespace std;

struct node
{
	string name, ID;
	int grade;
};

bool cmp(node& n1, node& n2) {
	if (n1.grade == n2.grade)
		return n1.ID < n2.ID;
	return n1.grade > n2.grade;
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<node> v(N);
	for (int i = 0; i < N; ++i)
		cin >> v[i].name >> v[i].ID >> v[i].grade;
	int grade1, grade2;
	cin >> grade1 >> grade2;
	sort(v.begin(), v.end(), cmp);
	vector<node> ans;
	for (int i = 0; i < N; ++i) {
		if (v[i].grade >= grade1 && v[i].grade <= grade2)
			ans.push_back(v[i]);
	}
	if (ans.size()) {
		for (int i = 0; i < ans.size(); ++i)
			cout << ans[i].name << " " << ans[i].ID << endl;
	} else
		cout << "NONE" << endl;

	return 0;
}
#include <bits/stdc++.h>
using namespace std;

map<string, set<int> >mp;
int main(int argc, char const *argv[])
{
	std::ios::sync_with_stdio(false);
	int N, K;
	cin >> N >> K;
	vector<string> stu(N);
	for (int i = 0; i < K; ++i) {
		int id, num;
		string name;
		// scanf("%d %d", &id, &num);
		cin >> id >> num;
		for (int i = 0; i < num; ++i) {
			cin >> name;
			mp[name].insert(id);
		}
	}
	for (int i = 0; i < N; ++i)
		cin >> stu[i];
	for (int i = 0; i < N; ++i) {
		int len = mp[stu[i]].size();
		cout << stu[i] << " " << len;
		if (len == 0) {
			cout << endl;
			continue;
		}
		cout << " ";
		set<int>::iterator it = mp[stu[i]].begin();
		for (; it != --mp[stu[i]].end(); ++it)
			// printf("%d ", *it);
			cout << *it << " ";
		// printf("%d\n", *it);
		cout << *it << endl;
	}

	return 0;
}
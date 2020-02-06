#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int M, N, S;
	cin >> M >> N >> S;
	vector<string> v(M);
	for (int i = 0; i < M; ++i)
		cin >> v[i];
	set<string>s;
	vector<string> ans;
	for (int i = S - 1; i < M;) {
		if (s.find(v[i]) == s.end()) {
			s.insert(v[i]);
			ans.push_back(v[i]);
			i += N;
		}
		else
			i++;
	}
	if (ans.size()) {
		for (int i = 0; i < ans.size(); ++i)
			cout << ans[i] << endl;
	} else
		cout << "Keep going..." << endl;

	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	set<int> ans;
	string s;
	for (int i = 0; i < N; ++i) {
		int tmp = 0;
		cin >> s;
		for (int j = 0; j < s.length(); ++j)
			tmp += s[j] - '0';
		ans.insert(tmp);
	}
	cout << ans.size() << endl;
	auto it = ans.begin();
	for (; it != --ans.end(); ++it)
		cout << *it << " ";
	cout << *it << endl;
	return 0;
}
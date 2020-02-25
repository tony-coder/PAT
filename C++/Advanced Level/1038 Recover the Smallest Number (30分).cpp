#include <bits/stdc++.h>
using namespace std;

bool cmp(string a, string b) {
	return a + b < b + a;
}

int main(int argc, char const *argv[])
{
	int N, i;
	cin >> N;
	vector<string> v(N);
	for (i = 0; i < N; ++i)
		cin >> v[i];
	sort(v.begin(), v.end(), cmp);
	string ans = "";
	for (i = 0; i < N; ++i)
		ans += v[i];
	i = 0;
	while (ans[i] == '0')
		i++;
	if (i == ans.size())
		cout << "0" << endl;
	else {
		for (; i < ans.size(); ++i)
			cout << ans[i];
		cout << endl;
	}

	return 0;
}
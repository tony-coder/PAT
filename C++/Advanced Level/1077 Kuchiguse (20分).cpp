#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 + 10;

string s[maxn];
int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	string ans;
	cin.get();
	for (int i = 0; i < N; ++i) {
		getline(cin, s[i]);
		reverse(s[i].begin(), s[i].end());
	}
	int pos = 0; char ch;
	for (int i = 0;; ++i) {
		if (i == N) {
			ans += ch;
			i = -1;
			pos++;
			continue;
		}
		if (pos >= s[i].size())
			break;
		if (i == 0)
			ch = s[i][pos];
		else if (ch != s[i][pos])
			break;
	}
	if (ans.size() == 0)
		cout << "nai" << endl;
	else
	{
		reverse(ans.begin(), ans.end());
		cout << ans << endl;
	}

	return 0;
}
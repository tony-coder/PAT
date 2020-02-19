#include <bits/stdc++.h>
using namespace std;

bool vis[256];
bool isused[256];
int main(int argc, char const *argv[])
{
	int k, i, j;
	cin >> k;
	string s;
	cin.get();
	getline(cin, s);
	memset(vis, true, sizeof(vis));
	memset(isused, false, sizeof(isused));
	i = 0; j = 1;
	while (i < s.length()) {
		while (j < s.length() && s[j] == s[j - 1])
			j++;
		if ((j - i) % k != 0)
			vis[s[i]] = false;
		i = j;
		j++;
	}
	for (i = 0; i < s.length(); ++i) {
		if (vis[s[i]] && !isused[s[i]]) {
			cout << s[i];
			isused[s[i]] = true;
		}
	}
	cout << endl;
	for (i = 0; i < s.length(); ++i) {
		cout << s[i];
		if (vis[s[i]])
			i += k - 1;
	}
	cout << endl;

	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	string s1, s2, ans;
	cin >> s1 >> s2;
	for (int i = 0; i < s1.length(); ++i) {
		if (s2.find(s1[i]) == string::npos && ans.find(toupper(s1[i])) == string::npos)
			ans += toupper(s1[i]);
	}
	cout << ans << endl;

	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	string s, tmp;
	map<string, int>mp;
	getline(cin, s);
	for (size_t i = 0; i < s.length(); ++i) {
		if (isalnum(s[i])) {
			tmp += tolower(s[i]);
		} else if (!isalnum(s[i])) {
			if (tmp.length())
				mp[tmp]++;
			tmp = "";
		}
	}
	if (tmp.length())
		mp[tmp]++;
	int Max = 0;
	string ans;
	for (auto t : mp) {
		if (t.second > Max) {
			Max = t.second;
			ans = t.first;
		}
	}
	printf("%s %d\n", ans.c_str(), Max);
	return 0;
}
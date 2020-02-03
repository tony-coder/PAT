#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	string str, tmp;
	getline(cin, str);
	map<string, int> mp;
	for (int i = 0; i < str.length(); ++i) {
		if (isalnum(str[i])) {
			tmp += tolower(str[i]);
		} else if (!isalnum(str[i]) && i != str.length() - 1) {
			if (tmp.length())
				mp[tmp]++;
			tmp = "";
		}
		if (i == str.length() - 1) {
			if (tmp.length())
				mp[tmp]++;
			tmp = "";
		}
	}
	int Max = 0;
	string ans;
	for (auto& t : mp) {
		if (t.second > Max) {
			Max = t.second;
			ans = t.first;
		}
	}
	cout << ans << " " << mp[ans] << endl;

	return 0;
}
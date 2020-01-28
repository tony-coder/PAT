#include <bits/stdc++.h>
using namespace std;

int vis[256];
int main(int argc, char const *argv[])
{
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	for (int i = 0; i < s2.size(); ++i)
		vis[s2[i]] = 1;
	for (int i = 0; i < s1.size(); ++i)
	{
		if (vis[s1[i]] == 1)
			continue;
		cout << s1[i];
	}

	return 0;
}
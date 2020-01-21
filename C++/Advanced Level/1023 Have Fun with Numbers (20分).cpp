#include <bits/stdc++.h>
using namespace std;

int vis[12];
int main(int argc, char const *argv[])
{
	memset(vis, 0, sizeof(vis));
	string a, b;
	cin >> a;
	for (int i = 0; i < a.size(); ++i)
		vis[a[i] - '0']++;

	int tmp = 0;
	for (int i = a.size() - 1; i >= 0; --i)
	{
		b += ((a[i] - '0') * 2 + tmp) % 10 + '0';
		tmp = ((a[i] - '0') * 2 + tmp) / 10;
	}
	while (tmp)
	{
		b += tmp % 10 + '0';
		vis[tmp % 10]--;
		tmp /= 10;
	}
	reverse(b.begin(), b.end());

	for (int i = 0; i < b.size(); ++i)
		vis[b[i] - '0']--;

	for (int i = 0; i < a.size(); ++i)
	{
		if (vis[i] != 0)
		{
			cout << "No" << endl;
			cout << b << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	cout << b << endl;

	return 0;
}
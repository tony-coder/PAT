#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD = 1000000007;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	string s;
	cin >> s;
	LL p = 0, t = 0;
	for (int i = 0; i < s.length(); ++i)
		if (s[i] == 'T')
			t++;
	LL ans = 0;
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == 'P')
			p++;
		else if (s[i] == 'T')
			t--;
		else if (s[i] == 'A')
			ans += p * t % MOD;
	}
	printf("%d\n", ans % MOD);

	return 0;
}
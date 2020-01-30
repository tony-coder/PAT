#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(int argc, char const *argv[])
{
	int T;
	cin >> T;
	long double A, B, C;
	for (int i = 1; i <= T; ++i)
	{
		cin >> A >> B >> C;
		if (A + B > C)
			printf("Case #%d: true\n", i );
		else
			printf("Case #%d: false\n", i );
	}
	return 0;
}
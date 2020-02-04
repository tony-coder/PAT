#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
typedef long long LL;

LL v[maxn];
int main(int argc, char const *argv[])
{
	int N, p;
	scanf("%d%d", &N, &p);
	for (int i = 0; i < N; ++i)
		scanf("%lld", &v[i]);
	sort(v, v + N);
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		int pos = upper_bound(v + i, v + N, v[i] * p) - v;
		if (pos - i > ans)
			ans = pos - i;
	}
	printf("%d\n", ans);

	return 0;
}
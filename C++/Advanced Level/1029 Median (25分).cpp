#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
typedef long long LL;

LL s1[maxn];
LL s2[maxn];
LL ans[maxn << 2];
int main(int argc, char const *argv[])
{
	int N, M;
	cin >> N;
	for (int i = 0; i < N; ++i)
		scanf("%lld", &s1[i]);
	cin >> M;
	for (int i = 0; i < M; ++i)
		scanf("%lld", &s2[i]);
	int cnt = 0;
	int i = 0, j = 0;
	while (i < N && j < M)
	{
		if (s1[i] < s2[j])
			ans[cnt++] = s1[i++];
		else
			ans[cnt++] = s2[j++];
	}
	while (i < N)
		ans[cnt++] = s1[i++];
	while (j < M)
		ans[cnt++] = s2[j++];
	int mid = (N + M) % 2 == 0 ? (M + N) / 2 - 1 : (M + N) / 2;
	cout << ans[mid] << endl;

	return 0;
}
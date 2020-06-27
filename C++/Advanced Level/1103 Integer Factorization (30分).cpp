#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
vector<int> v, ans, fac;
int N, K, P, maxfactorSum = -1;

int qpow(int a, int k)
{
	int ans = 1, base = a;
	while (k != 0)
	{
		if (k & 1 != 0)
			ans = ans * base % MOD;
		base = base * base % MOD;
		k >>= 1;
	}
	return ans;
}

void DFS(int i, int cnt, int tmpSum, int factSum) {
	if (cnt == K) {
		if (tmpSum == N && factSum > maxfactorSum) {
			ans = fac;
			maxfactorSum = factSum;
		}
		return;
	}
	for (; i >= 1; --i) {
		if (tmpSum + v[i] <= N) {
			fac[cnt] = i;
			DFS(i, cnt + 1, tmpSum + v[i], factSum + i);
		}
	}
	return;
}

int main(int argc, char const *argv[])
{
	int tmp = 0;
	scanf("%d %d %d", &N, &K, &P);
	fac.resize(K);
	v.push_back(0);
	for (int i = 1; i <= N && tmp <= N; ++i) {
		tmp = qpow(i, P);
		v.push_back(tmp);
	}

	DFS(v.size() - 1, 0, 0, 0);

	if (maxfactorSum == -1)
		printf("Impossible\n");
	else {
		printf("%d = %d^%d", N, ans[0], P);
		for (size_t i = 1; i < ans.size(); ++i) {
			printf(" + %d^%d", ans[i], P );
		}
		printf("\n");
	}

	return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
typedef long long LL;

int prime[maxn];
LL factor[maxn][2];

void init() {
	memset(prime, 0, sizeof(prime));
	prime[0] = prime[1] = 1;
	for (int i = 2; i < maxn; ++i) {
		if (!prime[i]) {
			if (i > maxn / i)
				continue;
			for (int j = i * i; j < maxn; j += i)
				prime[j] = 1;
		}
	}
}

int getFactors(LL n) {
	int cnt = 0;
	for (int i = 2; n >= 2; ++i) {
		if (prime[i] == 0 && n % i == 0) {
			while (n % i == 0) {
				factor[cnt][0] = i;
				factor[cnt][1]++;
				n /= i;
			}
			cnt++;
		}
	}
	return cnt;
}

int main(int argc, char const *argv[])
{
	init();
	LL N;
	cin >> N;
	int cnt = getFactors(N);
	int i;
	printf("%lld=", N);
	if (N == 1) {
		printf("1\n");
		return 0;
	}
	for (i = 0; i < cnt - 1; ++i) {
		if (factor[i][1] != 1)
			printf("%lld^%d*", factor[i][0], factor[i][1] );
		else
			printf("%lld*", factor[i][0]);
	}
	if (factor[i][1] != 1)
		printf("%lld^%d\n", factor[i][0], factor[i][1] );
	else
		printf("%lld\n", factor[i][0]);

	return 0;
}
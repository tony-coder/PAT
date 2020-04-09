#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;

int prime[maxn];

void getPrime() {
	memset(prime, 0, sizeof(prime));
	prime[0] = prime[1] = 1;
	for (int i = 2; i < maxn; i++) {
		if (!prime[i]) {
			if (i > maxn / i)
				continue;
			for (int j = i * i; j < maxn; j += i)
				prime[j] = 1;
		}
	}
}

int main(int argc, char const *argv[])
{
	getPrime();
	int N, M, K;
	cin >> N >> M >> K;
	int Ts = N;
	while (prime[Ts])
		Ts++;
	vector<int>table(Ts), ans(N, -1);
	for (int i = 0; i < M; ++i) {
		int t, index, j;
		cin >> t;
		for (j = 0; j < Ts; j++) {
			index = (t + j * j) % Ts;
			if (table[index] == 0) {
				table[index] = t;
				break;
			}
		}
		if (j == Ts)
			printf("%d cannot be inserted.\n", t );
	}
	double tot = 0.0;
	for (int i = 0; i < K; i++) {
		int t, index, cnt = 1;
		cin >> t;
		for (int j = 0; j < Ts; j++) {
			index = (t + j * j) % Ts;
			if (table[index] == t || table[index] == 0)
				break;
			cnt++;
		}
		tot += cnt;
	}
	printf("%.1f\n", tot / K);

	return 0;
}
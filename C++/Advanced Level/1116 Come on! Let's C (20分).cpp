#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
int prime[maxn];
int vis[maxn];
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

int main(int argc, char const *argv[])
{
	init();
	int N, id;
	cin >> N;
	map<int, int> mp;
	for (int i = 1; i <= N; ++i) {
		cin >> id;
		mp[id] = i;
	}
	int K;
	cin >> K;
	for (int i = 0; i < K; ++i) {
		cin >> id;
		if (mp.count(id)) {
			if (vis[id]++ > 0)
				printf("%04d: Checked\n", id );
			else if (mp[id] == 1)
				printf("%04d: Mystery Award\n", id );
			else if (prime[mp[id]] == 0)
				printf("%04d: Minion\n", id);
			else
				printf("%04d: Chocolate\n", id);
		} else {
			printf("%04d: Are you kidding?\n", id );
		}
	}

	return 0;
}
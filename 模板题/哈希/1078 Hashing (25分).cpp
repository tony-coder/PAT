#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;

int prime[maxn];
void init() {
	memset(prime, 0, sizeof(prime));
	prime[0] = 1;
	prime[1] = 1;
	for (int i = 2; i < maxn; ++i) {
		if (prime[i] == 0) {
			if (i > maxn / i)
				continue;
			for (int j = i * i; j < maxn; j += i)
				prime[j] = 1;
		}
	}
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	init();
	int M, N, i;
	cin >> M >> N;
	int Ts = M;
	while (prime[Ts])
		Ts++;
	vector<int> table(Ts), ans(N, -1);
	for (i = 0; i < N; ++i) {
		int tmp, index;
		cin >> tmp;
		for (int j = 0; j < Ts; ++j) {
			//平方探测法，解决冲突
			index = (tmp + j * j) % Ts;
			if (table[index] == 0) {
				table[index] = 1;
				ans[i] = index;
				break;
			}
		}
	}
	for (i = 0; i < ans.size() - 1; ++i) {
		if (ans[i] != -1)
			cout << ans[i] << " ";
		else
			cout << "- ";
	}
	if (ans[i] != -1)
		cout << ans[i] << endl;
	else
		cout << "-" << endl;

	return 0;
}
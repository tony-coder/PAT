#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;

int s[200 + 10], a[maxn], dp[maxn];

int LIS_m(int n) {
	int Max, ans = 1;
	dp[0] = 1;
	for (int i = 1; i < n; ++i) {
		Max = 0;
		for (int j = 0; j < i; ++j) {
			if (a[i] >= a[j] && Max < dp[j])
				Max = dp[j];
		}
		dp[i] = Max + 1;
		ans = max(ans, dp[i]);
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	int N, n, m, x;
	cin >> N;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> x;
		s[x] = i;
	}
	int num = 0;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> x;
		if (s[x] > 0)
			a[num++] = s[x];
	}
	// 现在只要找a的最长不下降子序列即可
	cout << LIS_m(num) << endl;

	return 0;
}
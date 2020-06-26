#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;

int coins[maxn];
int dp[maxn];
int choice[maxn][maxn];  // 记录最优解
int main(int argc, char const *argv[])
{
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
		cin >> coins[i];
	// 使得输出从小到大的排列
	sort(coins + 1, coins + N + 1, [](int a, int b) {return a > b;});

	for (int i = 1; i <= N; ++i) {
		for (int j = M; j >= coins[i]; --j) {
			//dp[j] = max(dp[j], dp[j - coins[i]] + coins[i]);
			if (dp[j - coins[i]] + coins[i] >= dp[j]) {
				choice[i][j] = true;
				dp[j] = dp[j - coins[i]] + coins[i];
			} else {
				choice[i][j] = false;
			}
		}
	}

	if (dp[M] != M) {
		printf("No Solution\n");
		return 0;
	}

	vector<int> ans;
	while (N > 0) {
		if (choice[N][M]) {  // 是否选择，因为coins[]已调整为从大到小排列，所以可以保证较小的数值优先选择
			ans.push_back(coins[N]);
			M -= coins[N];
		}
		N--;
	}

	for (size_t i = 0; i < ans.size() - 1; ++i)
		printf("%d ", ans[i]);
	printf("%d\n", ans[ans.size() - 1]);

	return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5;
const int INF = 0x3f3f3f3f;

int a[maxn], max_left[maxn], min_right[maxn];
int main(int argc, char const *argv[])
{
	int N, i;
	cin >> N;
	max_left[0] = 0;
	min_right[N + 1] = INF;
	for (i = 1; i <= N; ++i) {
		cin >> a[i];
		if (i == 1)
			max_left[i] = a[i];
		else
			max_left[i] = max(max_left[i - 1], a[i]);
	}
	for (i = N; i > 0; --i) {
		if (i == N)
			min_right[i] = a[i];
		else
			min_right[i] = min(min_right[i + 1], a[i]);
	}
	vector<int> ans;
	for (i = 1; i <= N; ++i) {
		if (a[i] >= max_left[i - 1] && a[i] <= min_right[i + 1])
			ans.push_back(a[i]);
	}
	cout << ans.size() << endl;
	if (ans.size() > 0) {
		sort(ans.begin(), ans.end());
		for (i = 0; i < ans.size() - 1; ++i)
			cout << ans[i] << " ";
		cout << ans[i];
	}
	cout << endl;
	return 0;
}
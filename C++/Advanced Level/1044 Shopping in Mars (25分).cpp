#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int main(int argc, char const *argv[])
{
	int N, M;
	scanf("%d%d", &N, &M);
	int tmp;
	vector<int>pre(N + 1, 0);
	for (int i = 1; i <= N; ++i) {
		scanf("%d", &tmp);
		pre[i] = pre[i - 1] + tmp;
	}
	int Min = INF, i = 1, j = 1;
	vector<pair<int, int> > ans;

	while (i <= N && j <= N) {
		int t = pre[j] - pre[i - 1];
		if (t < M)
			j++;
		else if (t >= M && t <= Min) {
			if (t < Min) {
				Min = t;
				ans.clear();
			}
			ans.push_back(make_pair(i, j));
			i++;
		} else {
			i++;
		}
	}
	for (int i = 0; i < ans.size(); ++i)
		printf("%d-%d\n", ans[i].first, ans[i].second);

	return 0;
}
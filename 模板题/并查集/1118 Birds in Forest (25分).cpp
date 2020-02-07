#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;

int pre[maxn];
void init() {
	for (int i = 0; i <= 10000; ++i)
		pre[i] = i;
}

int find(int x) {
	return x == pre[x] ? x : find(pre[x]);
}

void unite(int x, int y) {
	int fx = find(x);
	int fy = find(y);
	if (fx != fy)
		pre[fx] = fy;
}

bool issame(int x, int y) {
	return find(x) == find(y);
}

int main(int argc, char const *argv[])
{
	init();
	int N, K;
	scanf("%d", &N);
	// set<int> s;
	int b1, b2, Max = 0, ans = 0;
	for (int i = 0; i < N; ++i) {
		scanf("%d%d", &K, & b1);
		Max = max(Max, b1);
		for (int i = 1; i < K; ++i) {
			cin >> b2;
			Max = max(Max, b2);
			unite(b1, b2);
		}
	}
	for (int i = 1; i <= Max; ++i)
		if (pre[i] == i)
			ans++;
	printf("%d %d\n", ans, Max);
	int Q;
	cin >> Q;
	for (int i = 0; i < Q; ++i) {
		int b1, b2;
		scanf("%d%d", &b1, &b2);
		if (issame(b1, b2))
			printf("Yes\n");
		else
			printf("No\n");
	}

	return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;

int couples[maxn];
int main(int argc, char const *argv[])
{
	int N;
	memset(couples, -1, sizeof(couples));
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		int c1, c2;
		scanf("%d%d", &c1, &c2);
		couples[c1] = c2;
		couples[c2] = c1;
	}
	int M;
	scanf("%d", &M);
	vector<int> guests(M);
	for (int i = 0; i < M; ++i)
		scanf("%d", &guests[i]);
	sort(guests.begin(), guests.end());
	vector<int> ans;
	for (int i = 0; i < M; ++i) {
		if (!binary_search(guests.begin(), guests.end(), couples[guests[i]]))
			ans.push_back(guests[i]);
	}
	printf("%d\n", ans.size());
	if (ans.size()) {
		int i;
		for (i = 0; i < ans.size() - 1; ++i)
			printf("%05d ", ans[i] );
		printf("%05d\n", ans[i]);
	}

	return 0;
}
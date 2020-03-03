#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 10;

int a[maxn], ans[maxn], cnt, N, i;
void in_order(int root) {
	if (root > N)
		return;
	in_order(root * 2);
	ans[root] = a[cnt++];
	in_order(root * 2 + 1);
}

int main(int argc, char const *argv[])
{
	cin >> N;
	for (i = 0; i < N; ++i)
		cin >> a[i];
	sort(a, a + N);
	cnt = 0;
	in_order(1);
	for (i = 1; i <= N - 1; ++i)
		cout << ans[i] << " ";
	cout << ans[i] << endl;

	return 0;
}
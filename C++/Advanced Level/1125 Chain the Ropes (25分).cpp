#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;

int a[maxn];
int main(int argc, char const *argv[])
{
	int N, ans;
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> a[i];
	sort(a, a + N);
	ans = a[0];
	for (int i = 1; i < N; ++i)
		ans = (ans + a[i]) / 2;
	cout << ans << endl;

	return 0;
}
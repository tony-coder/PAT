#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;

int D1[maxn];
int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	int d, tot = 0;
	for (int i = 1; i <= N; ++i)
	{
		cin >> d;
		D1[i] = d + D1[i - 1];
		tot += d;
	}
	int M, a, b;
	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		cin >> a >> b;
		if (a > b)
			swap(a, b);
		int tmp = D1[b - 1] - D1[a - 1];
		cout << min(tmp, tot - tmp) << endl;
	}

	return 0;
}
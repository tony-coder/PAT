#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;

double data[maxn];
int main(int argc, char const *argv[])
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
		scanf("%lf", &data[i]);
	double ans = 0.0;
	for (int i = 0; i < N; i++)
		ans += data[i] * (N - i) * (i + 1);
	printf("%.2f\n", ans);

	return 0;
}
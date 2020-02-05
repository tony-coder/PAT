#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;

int v[maxn];
int main(int argc, char const *argv[])
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
		scanf("%d", &v[i]);
	sort(v, v + N);
	if (N % 2 == 0)
		printf("0 %d\n", accumulate(v + N / 2, v + N, 0) - accumulate(v, v + N / 2, 0));
	else
		printf("1 %d\n", accumulate(v + N / 2, v + N, 0) - accumulate(v, v + N / 2, 0));

	return 0;
}
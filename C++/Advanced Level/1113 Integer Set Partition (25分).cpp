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
	int Max = 0, Min = 0, i;
	if (N % 2 == 0) {
		for (i = 0; i < N / 2; ++i)
			Min += v[i];
		for (; i < N; ++i)
			Max += v[i];
		printf("0 %d\n", Max - Min);
	} else {
		for (i = 0; i < N / 2; ++i)
			Min += v[i];
		i++;
		for (; i < N; ++i)
			Max += v[i];
		printf("1 %d\n", max(Max + v[N / 2] - Min, Max - v[N / 2] - Min));
	}

	return 0;
}
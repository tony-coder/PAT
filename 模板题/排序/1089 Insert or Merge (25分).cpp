#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int N;
	scanf("%d", &N);
	vector<int> a(N), b(N);
	for (int i = 0; i < N; ++i)
		scanf("%d", &a[i]);
	for (int i = 0; i < N; ++i)
		scanf("%d", &b[i]);

	int i, j;
	for (i = 0; i < N - 1; ++i) {
		if (b[i] > b[i + 1])
			break;
	}
	for (j = i + 1; j < N; ++j) {
		if (a[j] != b[j])
			break;
	}
	if (j == N) {
		printf("Insertion Sort\n");
		sort(a.begin(), a.begin() + i + 2);
	} else {
		printf("Merge Sort\n");
		int k = 1, flag = 1;
		while (flag) {
			flag = 0;
			for (i = 0; i < N; ++i) {
				if (a[i] != b[i]) {
					flag = 1;
					break;
				}
			}
			k *= 2;
			for (i = 0; i < N / k; ++i)
				sort(a.begin() + i * k, a.begin() + (i + 1)*k);
			sort(a.begin() + N / k * k, a.begin() + N);
		}
	}
	for (i = 0; i < N - 1; ++i)
		printf("%d ", a[i] );
	printf("%d\n", a[i]);

	return 0;
}
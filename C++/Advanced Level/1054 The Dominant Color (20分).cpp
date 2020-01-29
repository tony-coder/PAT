#include <bits/stdc++.h>
using namespace std;

int c[600 * 800 + 10];
int main(int argc, char const *argv[])
{
	int M, N, cnt = 0;
	cin >> M >> N;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			scanf("%d", &c[cnt++]);
	sort(c, c + M * N);
	cout << c[(M * N) / 2] << endl;

	return 0;
}
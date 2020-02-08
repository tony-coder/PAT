#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;

int a[maxn];
int matrix[maxn][maxn];
int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> a[i];
	sort(a, a + N, [](int a, int b) {return a > b;});
	int m = ceil(sqrt(N));
	while (N % m != 0)
		m++;
	int n = N / m;
	int i = 0, j = 0;
	int now = 0;
	while (now < N) {
		while (j < n && matrix[i][j] == 0)
			matrix[i][j++] = a[now++];
		j--; i++;
		while (i < m && matrix[i][j] == 0)
			matrix[i++][j] = a[now++];
		i--; j--;
		while (j >= 0 && matrix[i][j] == 0)
			matrix[i][j--] = a[now++];
		j++; i--;
		while (i >= 0 && matrix[i][j] == 0)
			matrix[i--][j] = a[now++];
		i++; j++;
	}

	for (int i = 0; i < m; ++i) {
		int j;
		for (j = 0; j < n - 1; ++j)
			cout << matrix[i][j] << " ";
		cout << matrix[i][j] << endl;
	}


	return 0;
}
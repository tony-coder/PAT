#include <bits/stdc++.h>
using namespace std;

int find(vector<int>& v, int l, int r, int value) {
	int left = l, right = r, mid;
	while (left <= right) {
		mid = (left + right) >> 1;
		if (v[mid] > value)
			right = mid - 1;
		else if (v[mid] < value)
			left = mid + 1;
		else
			return mid;
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	vector<int> v(N);
	for (int i = 0; i < N; ++i)
		cin >> v[i];
	sort(v.begin(), v.end());
	if (v[N - 1] + v[N - 2] < M)
		printf("No Solution\n");
	else {
		for (int i = 0; i < N; ++i) {
			if (find(v, i + 1, N - 1, M - v[i]) != -1) {
				printf("%d %d\n", v[i], M - v[i]);
				return 0;
			}
		}
	}
	printf("No Solution\n");

	return 0;
}
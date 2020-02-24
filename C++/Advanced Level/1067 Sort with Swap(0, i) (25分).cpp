#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;

int pos[maxn];
int main(int argc, char const *argv[])
{
	int N;
	scanf("%d", &N);
	int left = N - 1;
	for (int i = 0; i < N; ++i) {
		int t;
		scanf("%d", &t);
		pos[t] = i;
		if (t == i && t != 0)
			left--;
	}

	int cnt = 0, k = 1;  //存放除0之外当前不在本位上的最小的数
	while (left > 0) {
		if (pos[0] == 0) {
			while (k < N && pos[k] == k)
				k++;
			swap(pos[0], pos[k]);
			cnt++;
		}
		while (pos[0] != 0) {
			swap(pos[0], pos[pos[0]]);
			cnt++;
			left--;
		}
	}

	printf("%d\n", cnt);

	return 0;
}
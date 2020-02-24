#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;

int a[maxn];
int position[maxn];
int main(int argc, char const *argv[])
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &a[i]);
		position[a[i]] = i;
	}
	int cnt = 0, i;
	while (true) {
		bool flag = true;
		for (i = 0; i < N; ++i) {
			if (a[i] != i) {
				flag = false;
				break;
			}
		}
		if (flag)
			break;
		cnt++;
		if (position[0] != 0) {
			swap(a[position[0]], a[position[position[0]]]);
			swap(position[0], position[position[0]]);
		} else {
			swap(position[0], position[a[i]]);
			swap(a[0], a[i]);
		}
	}
	printf("%d\n", cnt);

	return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 10;

int pre[maxn], hobby[maxn], num[maxn]; // hobby[]示编号为x的爱好属于哪一个人
void init() {
	for (int i = 0; i < maxn; ++i)
		pre[i] = i;
}

int find(int x) {
	return x == pre[x] ? x : find(pre[x]);
}

void unite(int x, int y) {
	int fx = find(x);
	int fy = find(y);
	if (fx != fy)
		pre[fx] = fy;
}

int main(int argc, char const *argv[])
{
	init();
	int N, K, i, cnt = 0;
	scanf("%d", &N);
	for (i = 1; i <= N; ++i) {
		scanf("%d:", &K);
		while (K--) {
			int x;
			cin >> x;
			if (hobby[x] == 0)
				hobby[x] = i;
			else
				unite(i, hobby[x]);
		}
	}
	for (i = 1; i <= N; ++i)
		num[find(i)]++;
	sort(num + 1, num + N + 1, [](int x, int y) {return x > y;});
	for (int i = 1; i <= N; ++i) {
		if (num[i] != 0)
			cnt++;
		else
			break;
	}
	cout << cnt << endl;
	for (i = 1; i <= cnt - 1; ++i)
		cout << num[i] << " ";
	cout << num[i] << endl;

	return 0;
}
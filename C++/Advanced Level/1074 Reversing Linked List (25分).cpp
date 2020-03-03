#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;

struct node {
	int address, data, next;
} List[maxn];

int main(int argc, char const *argv[])
{
	int head, N, K, i, cnt = 0;
	cin >> head >> N >> K;
	for (i = 0; i < N; ++i) {
		int address, data, next;
		cin >> address >> data >> next;
		List[address] = {address, data, next};
	}
	vector<node> v;
	for (i = head; i != -1; i = List[i].next) {
		v.push_back(List[i]);
		cnt++;
	}

	for (int i = 0; i < cnt; i += K) {
		if (i + K <= cnt)
			reverse(v.begin() + i, v.begin() + i + K);
	}

	for (i = 0; i < cnt - 1; ++i)
		printf("%05d %d %05d\n", v[i].address, v[i].data, v[i + 1].address);
	printf("%05d %d %d\n", v[i].address, v[i].data, -1);

	return 0;
}
/*
00100 6 3
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
*/
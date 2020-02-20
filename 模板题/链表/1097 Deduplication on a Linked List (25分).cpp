#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
const int maxm = 1e4 + 10;
struct node
{
	int address, key, next;
} List[maxn];
int vis[maxm] = {0};

int main(int argc, char const *argv[])
{
	int l, N, i;
	scanf("%d%d", &l, &N);
	for (int i = 0; i < N; ++i) {
		int address, key, next;
		scanf("%d%d%d", &address, &key, &next);
		List[address] = {address, key, next};
	}
	vector<node> v1, v2;
	for (i = l; i != -1; i = List[i].next) {
		if (vis[abs(List[i].key)] == 0) {
			v1.push_back(List[i]);
			vis[abs(List[i].key)]++;
		}
		else {
			v2.push_back(List[i]);
		}
	}
	for (i = 0; i < v1.size() - 1; i++)
		printf("%05d %d %05d\n", v1[i].address , v1[i].key, v1[i + 1].address);
	printf("%05d %d %d\n", v1[i].address, v1[i].key, -1 );
	if (v2.size() == 0)
		return 0;
	for (i = 0; i < v2.size() - 1; i++)
		printf("%05d %d %05d\n", v2[i].address , v2[i].key, v2[i + 1].address);
	printf("%05d %d %d\n", v2[i].address, v2[i].key, -1 );

	return 0;
}

/*
00100 5
99999 -7 87654
23854 -15 00000
87654 15 -1
00000 -15 99999
00100 21 23854
*/
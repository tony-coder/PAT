#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6;

struct node {
	char ch;
	int next;
} List[maxn];
map<int, int>mp;

int main(int argc, char const *argv[])
{
	int addr1, addr2, N, i;
	scanf("%d %d %d", &addr1, &addr2, &N);
	for (i = 0; i < N; ++i) {
		int address, next;
		char ch;
		scanf("%d %c %d", &address, &ch, &next);
		List[address] = {ch, next};
	}
	for ( i = addr1; i != -1; i = List[i].next)
		mp[i]++;
	for ( i = addr2; i != -1; i = List[i].next) {
		mp[i]++;
		if (mp[i] == 2)
			break;
	}
	if (i != -1)
		printf("%05d\n", i);
	else
		printf("-1\n");

	return 0;
}
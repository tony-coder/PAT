#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6;

struct node {
	char ch;
	int next;
} List[maxn];

int main(int argc, char const *argv[])
{
	int addr1, addr2, N, i, j;
	scanf("%d %d %d", &addr1, &addr2, &N);
	for (i = 0; i < N; ++i) {
		int address, next;
		char ch;
		scanf("%d %c %d", &address, &ch, &next);
		List[address] = {ch, next};
	}
	for ( i = addr1; i != -1; i = List[i].next) {
		for ( j = addr2; j != -1; j = List[j].next) {
			if (i == j)
				break;
		}
		if (j != -1)
			break;
	}
	if (i != -1)
		printf("%05d\n", i);
	else
		printf("-1\n");

	return 0;
}
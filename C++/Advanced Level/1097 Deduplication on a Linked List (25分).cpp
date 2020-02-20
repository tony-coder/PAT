#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
const int maxm = 1e4 + 10;
struct node
{
	int key, next, pre;
	node(): key(0), next(-1), pre(-1) {}
} List[maxn];
int vis[maxm] = {0};

int main(int argc, char const *argv[])
{
	int l1 = -1, l2 = -1, N;
	scanf("%d%d", &l1, &N);
	for (int i = 0; i < N; ++i) {
		int address, key, next;
		scanf("%d%d%d", &address, &key, &next);
		List[address].key = key;
		List[address].next = next;
		List[next].pre = address;
	}
	int tail = -1, i = l1;
	while (i != -1) {
		if (vis[abs(List[i].key)] == 0) {
			vis[abs(List[i].key)]++;
			i = List[i].next;
		}
		else {
			List[List[i].pre].next = List[i].next;
			if (List[i].next != -1)
				List[List[i].next].pre = List[i].pre;
			int tmp = List[i].next;
			if (l2 == -1) {
				l2 = i;
				List[l2].next = -1;
				List[l2].pre = -1;
				tail = l2;
			} else {
				List[tail].next = i;
				List[i].pre = tail;
				List[i].next = -1;
				tail = i;
			}
			i = tmp;
		}
	}
	for (i = l1; i != -1; i = List[i].next) {
		if (List[i].next != -1)
			printf("%05d %d %05d\n", i, List[i].key, List[i].next);
		else
			printf("%05d %d %d\n", i, List[i].key, -1);
	}

	for (i = l2; i != -1; i = List[i].next) {
		if (List[i].next != -1)
			printf("%05d %d %05d\n", i, List[i].key, List[i].next);
		else
			printf("%05d %d %d\n", i, List[i].key, -1);
	}


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
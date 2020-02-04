#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;

struct node
{
	int Address, Key, Next;
} l[maxn], ans[maxn];

int cmp(node& a, node& b) {
	return a.Key < b.Key;
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int N, head;
	cin >> N >> head;
	for (int i = 1; i <= N; ++i) {
		int address, key, next;
		cin >> address >> key >> next;
		l[address].Address = address;
		l[address].Key = key;
		l[address].Next = next;
	}
	int cnt = 0;
	while (head != -1) {
		cnt++;
		ans[cnt].Address = l[head].Address;
		ans[cnt].Key = l[head].Key;
		head = l[head].Next;
	}
	if (cnt == 0) {
		cout << "0 -1" << endl; //特判 最后一个点
		return 0;
	}
	sort(ans + 1, ans + 1 + cnt, cmp);
	printf("%d %05d\n", cnt, ans[1].Address);
	for (int i = 1; i <= cnt; ++i) {
		if (i != cnt) {
			printf("%05d %d %05d\n", ans[i].Address, ans[i].Key, ans[i + 1].Address);
		} else {
			printf("%05d %d -1\n", ans[i].Address, ans[i].Key );
		}
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;

struct node {
	int Address, Data, Next;
} List[maxn];

int main(int argc, char const *argv[])
{
	int head, N, K;
	scanf("%d %d %d", &head, &N, &K);
	for (int i = 0; i < N; ++i) {
		int Address, Data, Next;
		scanf("%d %d %d", &Address, &Data, &Next);
		List[Address] = {Address, Data, Next};
	}
	vector<node> v;
	int i;
	for (i = head; i != -1; i = List[i].Next) {
		v.push_back(List[i]);
	}
	for (i = 0; i + K < v.size(); i += K) {
		reverse(v.begin() + i, v.begin() + i + K);
	}
	reverse(v.begin() + i, v.end());

	reverse(v.begin(), v.end());
	for (i = 0; i < v.size() - 1; ++i)
		printf("%05d %d %05d\n", v[i].Address, v[i].Data, v[i + 1].Address);
	printf("%05d %d -1\n", v[i].Address, v[i].Data );
	return 0;
}
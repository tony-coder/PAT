#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6;

struct node
{
	int address, data, next;
} List[maxn];

int main(int argc, char const *argv[])
{
	int head, N, K;
	scanf("%d %d %d", &head, &N, &K);
	for (int i = 0; i < N; ++i) {
		int address, data, next;
		scanf("%d %d %d", &address, &data, &next);
		List[address] = {address, data, next};
	}
	vector<node> v1, v2, v3, ans;
	for (int i = head; i != -1; i = List[i].next) {
		if (List[i].data < 0)
			v1.push_back(List[i]);
		else if (List[i].data <= K)
			v2.push_back(List[i]);
		else
			v3.push_back(List[i]);
	}
	// merge(v1.begin(),v1.end(),v2.begin(),v2.end(),ans.begin());
	ans.insert(ans.end(), v1.begin(), v1.end());
	ans.insert(ans.end(), v2.begin(), v2.end());
	ans.insert(ans.end(), v3.begin(), v3.end());
	int i;
	for (i = 0; i < ans.size() - 1; ++i)
		printf("%05d %d %05d\n", ans[i].address, ans[i].data, ans[i + 1].address);
	printf("%05d %d -1\n", ans[i].address, ans[i].data );
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const int INF = 0x3f3f3f3f;

struct node
{
	double value;
	vector<int>child;
} tree[maxn];

int N, cnt;
double P, r, ans;

void DFS(int root) {
	if (tree[root].child.size() == 0 && tree[root].value < ans) {
		ans = tree[root].value;
		cnt = 1;
	} else if (tree[root].child.size() == 0 && tree[root].value == ans)
		cnt++;
	for (int i = 0; i < tree[root].child.size(); ++i) {
		tree[tree[root].child[i]].value = tree[root].value * (1 + r);
		DFS(tree[root].child[i]);
	}
}

int main(int argc, char const *argv[])
{
	cin >> N >> P >> r;
	r /= 100;
	for (int i = 0; i < N; ++i) {
		int k, t;
		cin >> k;
		if (k != 0) {
			for (int j = 0; j < k; ++j) {
				cin >> t;
				tree[i].child.push_back(t);
			}
		}
	}
	cnt = 0, ans = INF;
	tree[0].value = P;
	DFS(0);

	printf("%.4f %d\n", ans, cnt );

	return 0;
}
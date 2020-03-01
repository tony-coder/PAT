#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;

struct node
{
	double value;
	vector<int>child;
} tree[maxn];

int N, cnt;
double P, r, ans;
void DFS(int root) {
	if (tree[root].value > ans) {
		ans = tree[root].value;
		cnt = 1;
	} else if (tree[root].value == ans)
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
	int root;
	for (int i = 0; i < N; ++i) {
		int x;
		cin >> x;
		if (x == -1) {
			root = i;
			tree[root].value = P;
		}
		else
			tree[x].child.push_back(i);
	}
	ans = 0., cnt = 0;
	DFS(root);
	printf("%.2f %d\n", ans, cnt);

	return 0;
}
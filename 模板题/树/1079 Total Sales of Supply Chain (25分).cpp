#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;

struct node
{
	double value;
	int level;
	vector<int> child;
} tree[maxn];

double P, r;

double BFS(int root) {
	double ans = 0.;
	queue<node> q;
	tree[root].level = 0;
	q.push(tree[root]);
	while (!q.empty()) {
		node tmp = q.front();
		q.pop();
		if (tmp.child.size() != 0) {
			for (int i = 0; i < tmp.child.size(); ++i) {
				node v = tree[tmp.child[i]];
				v.level = tmp.level + 1;
				q.push(v);
			}
		} else {
			ans += tmp.value * P * pow(1 + r, tmp.level);
		}
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	int N;
	cin >> N >> P >> r;
	r /= 100;
	for (int i = 0; i < N; ++i) {
		int k, x;
		cin >> k;
		if (k == 0) {
			cin >> tree[i].value;
		} else {
			for (int j = 0; j < k; ++j) {
				cin >> x;
				tree[i].child.push_back(x);
			}
		}
	}
	printf("%.1f\n", BFS(0));
	return 0;
}
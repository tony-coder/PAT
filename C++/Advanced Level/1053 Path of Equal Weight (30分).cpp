#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 + 10;

struct node {
	int id, W;
	vector<int> child;
} tree[maxn];

vector<int> path;
vector<vector<int> >ans;
int N, M, S;

void dfs(int root, int sum) {
	if (sum > S)
		return;
	if (tree[root].child.size() == 0) {
		if (sum == S) {
			vector<int> v;
			for (int i = 0; i < path.size(); i++)
				v.push_back(path[i]);
			ans.push_back(v);
		}
		return;
	}
	for (int i = 0; i < tree[root].child.size(); ++i) {
		path.push_back(tree[tree[root].child[i]].W);
		dfs(tree[root].child[i], sum + tree[tree[root].child[i]].W);
		path.pop_back();
	}
}

bool cmp(vector<int>& a, vector<int>& b) {
	for (int i = 0; i < min(a.size(), b.size()); i++) {
		if (a[i] != b[i])
			return a[i] > b[i];
	}
	return a.size() > b.size();
}

int main(int argc, char const *argv[])
{
	int i, j, t, id, K, root = 0;
	cin >> N >> M >> S;
	for (i = 0; i < N; ++i)
		cin >> tree[i].W;
	for (i = 0; i < M; ++i) {
		cin >> id >> K;
		for (j = 0; j < K; ++j) {
			cin >> t;
			tree[id].child.push_back(t);
		}
	}
	path.push_back(tree[root].W);
	dfs(root, tree[root].W);
	sort(ans.begin(), ans.end(), cmp);
	for (i = 0; i < ans.size(); ++i) {
		for (j = 0; j < ans[i].size() - 1; j++)
			printf("%d ", ans[i][j]);
		printf("%d\n", ans[i][j]);
	}
	return 0;
}
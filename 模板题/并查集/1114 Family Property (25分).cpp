#include <bits/stdc++.h>
using namespace std;
const int maxn = 10000 + 10;

struct Input {
	int id, father, mother, k, M_estate, area;
	int child[10];
} input[maxn];

struct node {
	int id, M;
	double AVG_sets, AVG_area;
	bool flag = false;
} ans[maxn];

int pre[maxn];
bool visit[maxn];

void init() {
	for (int i = 0; i < maxn; ++i)
		pre[i] = i;
	memset(visit, false, sizeof(visit));
}

int Find(int x) {
	return x == pre[x] ? x : Find(pre[x]);
}

void Union(int x, int y) {
	int fx = Find(x);
	int fy = Find(y);
	// 根据题目要求，添加到较小的id下
	if (fx > fy)
		pre[fx] = fy;
	else if (fx < fy)
		pre[fy] = fx;
}

int main(int argc, char const *argv[])
{
	init();
	int N, cnt = 0;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> input[i].id >> input[i].father >> input[i].mother >> input[i].k;
		visit[input[i].id] = true;
		if (input[i].father != -1) {
			Union(input[i].id, input[i].father);
			visit[input[i].father] = true;
		}
		if (input[i].mother != -1) {
			Union(input[i].id, input[i].mother);
			visit[input[i].mother] = true;
		}
		for (int j = 0; j < input[i].k; ++j) {
			cin >> input[i].child[j];
			visit[input[i].child[j]] = true;
			Union(input[i].child[j], input[i].id);
		}
		cin >> input[i].M_estate >> input[i].area;
	}

	for (int i = 0; i < N; ++i) {
		int id = Find(input[i].id);
		ans[id].id = id;
		ans[id].AVG_sets += input[i].M_estate;
		ans[id].AVG_area += input[i].area;
		ans[id].flag = true;
	}
	// 得到每个家庭的成员数和家庭数
	for (int i = 0; i < maxn; ++i) {
		if (visit[i])
			ans[Find(i)].M++;
		if (ans[i].flag)
			cnt++;
	}
	vector<node> t;
	// 计算得到AVG_sets和AVG_area
	for (int i = 0; i < maxn; ++i) {
		if (ans[i].flag) {
			ans[i].AVG_sets = double(ans[i].AVG_sets / ans[i].M);
			ans[i].AVG_area = double(ans[i].AVG_area / ans[i].M);
			t.push_back(ans[i]);
		}
	}
	sort(t.begin(), t.end(), [](node & a, node & b) {return a.AVG_area == b.AVG_area ? a.id<b.id: a.AVG_area>b.AVG_area;});

	printf("%d\n", cnt);
	for (int i = 0; i < cnt; ++i) {
		printf("%04d %d %.3f %.3f\n", t[i].id, t[i].M, t[i].AVG_sets, t[i].AVG_area);
	}

	return 0;
}
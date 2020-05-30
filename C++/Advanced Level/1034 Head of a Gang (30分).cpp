#include <bits/stdc++.h>
using namespace std;
const int maxn = 5000 + 10;

// dfs搜索找联通域
int cnt;
int g[maxn][maxn];
bool vis[maxn];
int weight[maxn];  // 点权
unordered_map<string, int> mp1; // 名字到点映射
unordered_map<int, string> mp2; // 点到名字映射
map<string, int> res; // <老大名字，人数>

int sum;   // 总通话时间
int head;  // 老大编号
int max_w; // 最大点权
int num;   // 人数

void dfs(int root) {
	vis[root] = true;
	num++;
	if (weight[root] > max_w) {
		max_w = weight[root];
		head = root;
	}
	for (int i = 1; i <= cnt; ++i) {
		if (g[root][i] != 0) { // 有联系
			sum += g[root][i];
			g[root][i] = g[i][root] = 0; // 访问标记，防止总分重复加上该段
			if (!vis[i])
				dfs(i);
		}
	}
}

int main(int argc, char const *argv[])
{
	int N, K;
	cin >> N >> K;
	for (int i = 0; i < N; ++i) {
		string name1, name2;
		int time, x, y;
		cin >> name1 >> name2 >> time;
		if (mp1.count(name1) == 0) {
			x = ++cnt;
			mp1[name1] = x;
			mp2[x] = name1;
		} else
			x = mp1[name1];
		if (mp1.count(name2) == 0) {
			y = ++cnt;
			mp1[name2] = y;
			mp2[y] = name2;
		} else
			y = mp1[name2];
		g[x][y] += time;
		g[y][x] += time;

		weight[x] += time;
		weight[y] += time;
	}
	for (int i = 1; i <= cnt; ++i) {
		sum = 0;
		head = 0;
		num = 0;
		max_w = 0;
		if (!vis[i])
			dfs(i);
		if (num > 2 && sum > K)
			res[mp2[head]] = num;
	}
	cout << res.size() << endl;
	for (auto key : res) {
		cout << key.first << " " << key.second << endl;
	}

	return 0;
}
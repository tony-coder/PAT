#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;

struct node {
	int a, b;
};
int main(int argc, char const *argv[])
{
	int N, M, K;
	cin >> N >> M;
	vector<int> v[maxn];
	unordered_map<int, bool> relationship;

	for (int i = 0; i < M; ++i) {
		// 如果用int接收1对朋友，-0000和0000对于int来说都是0，将无法得知这个人的性别，会影响找他的同性朋友的步骤，所以要用字符串接收
		string a, b;
		cin >> a >> b;
		int ta = stoi(a), tb = stoi(b);
		if (a.length() == b.length()) { // 同性
			v[abs(ta)].push_back(abs(tb));
			v[abs(tb)].push_back(abs(ta));
		}
		// 储存关系
		relationship[abs(ta) * 10000 + abs(tb)] = true;
		relationship[abs(tb) * 10000 + abs(ta)] = true;
	}
	cin >> K;
	for (int i = 0; i < K; ++i) {
		int a, b;
		cin >> a >> b;
		vector<node> ans;
		for (size_t i = 0; i < v[abs(a)].size(); ++i) {
			for (size_t j = 0; j < v[abs(b)].size(); ++j) {
				// 同性伴侣的情况去除...
				if (v[abs(a)][i] == abs(b) || v[abs(b)][j] == abs(a))
					continue;
				if (relationship[v[abs(a)][i] * 10000 + v[abs(b)][j]]) { // 有关系
					ans.push_back({v[abs(a)][i], v[abs(b)][j]});
				}
			}
		}
		sort(ans.begin(), ans.end(), [](node & n1, node & n2) {return n1.a == n2.a ? n1.b < n2.b : n1.a < n2.a;});
		printf("%d\n", ans.size());
		for (size_t i = 0; i < ans.size(); ++i)
			printf("%04d %04d\n", ans[i].a, ans[i].b);
	}
	return 0;
}
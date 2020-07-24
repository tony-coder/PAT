#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;

struct node {
	int value;
	int cnt;
	node(int _value, int _cnt): value(_value), cnt(_cnt) {}
	// 注意重载<号
	bool operator<(const node& n)const {
		return cnt == n.cnt ? value<n.value: cnt>n.cnt;
	}
};

int vis[maxn];
int main(int argc, char const *argv[])
{
	int N, K, tmp;
	cin >> N >> K;
	set<node> st;
	cin >> tmp;
	vis[tmp]++;
	st.insert({tmp, vis[tmp]});
	for (int i = 1; i < N; ++i) {
		cin >> tmp;
		printf("%d:", tmp);
		int cnt = 0;
		for (auto t : st) {
			if (cnt >= K)
				break;
			printf(" %d", t.value);
			cnt++;
		}
		printf("\n");
		if (st.find(node(tmp, vis[tmp])) != st.end()) {
			st.erase(node(tmp, vis[tmp]));
		}
		vis[tmp]++;
		st.insert({tmp, vis[tmp]});
	}

	return 0;
}
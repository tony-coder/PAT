#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	map<int, double> p;
	map<int, double, greater<int> > ans;

	int K, N;
	double a;
	cin >> K;
	for (int i = 0; i < K; ++i) {
		cin >> N >> a;
		p[N] = a;
	}
	cin >> K;
	for (int i = 0; i < K; ++i) {
		cin >> N >> a;
		for (auto t : p) {
			int u = t.first + N;
			double v = t.second * a;
			if (ans.count(u)) {
				ans[u] += v;
				if (ans[u] == 0.)  //去除系数为0的情况
					ans.erase(u);
			} else
				ans[u] = v;
		}
	}
	cout << ans.size();
	for (auto t : ans) {
		printf(" %d %.1f", t.first, t.second );
	}
	cout << endl;
	return 0;
}
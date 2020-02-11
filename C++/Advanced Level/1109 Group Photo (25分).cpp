#include <bits/stdc++.h>
using namespace std;

struct node {
	string name;
	int height;
};

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int N, K;
	cin >> N >> K;
	vector<node> v(N);
	vector<string> ans(N, "");
	for (int i = 0; i < N; ++i)
		cin >> v[i].name >> v[i].height;
	sort(v.begin(), v.end(), [](node & a, node & b) {return a.height == b.height ? a.name > b.name : a.height < b.height;});
	int row = K, now;
	K = N / row;
	for (now = 0; now < (row - 1)*K; now += K) {
		int i = now + K / 2 - 1, j = now + K / 2 + 1;
		int pos = now + K - 1;
		ans[now + K / 2] = v[pos--].name;
		for (int k = 0; k < K - 1; ++k) {
			if (k % 2 == 0) {
				ans[i--] = v[pos--].name;
			} else {
				ans[j++] = v[pos--].name;
			}
		}
	}
	int col = N - (row - 1) * K;
	int i = now + col / 2 - 1, j = now + col / 2 + 1;
	int pos = now + col - 1;
	ans[now + col / 2] = v[pos--].name;
	for (int k = 0; k < col - 1; ++k) {
		if (k % 2 == 0) {
			ans[i--] = v[pos--].name;
		} else {
			ans[j++] = v[pos--].name;
		}
	}
	for (j = N - col; j < N - 1; ++j)
		cout << ans[j] << " ";
	cout << ans[j] << endl;
	for (i = row - 2; i >= 0; --i) {
		for (j = i * K; j < (i + 1)*K - 1; ++j)
			cout << ans[j] << " ";
		cout << ans[j] << endl;
	}

	return 0;
}
/*
10 2
Tom 188
Mike 170
Eva 168
Tim 160
Joe 190
Ann 168
Bob 175
Nick 186
Amy 160
John 159
*/
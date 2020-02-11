#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int N, K;
	cin >> N >> K;
	vector<pair<string, int> > a(N);
	for (int i = 0; i < N; ++i)
		cin >> a[i].first >> a[i].second;
	sort(a.begin(), a.end(), [](pair<string, int> &a, pair<string, int> &b)->bool{
		if (a.second == b.second)
			return a.first < b.first;
		return a.second > b.second;
	});
	int s = 0;  //每排输出时保存的开始位置
	int f;  	//结束位置
	for (int i = 0; i < K; ++i) {
		f = (0 == i ? N % K : 0) + N / K + s - 1;
		for (int j = f - 1 + ((f - s) % 2); j >= s; j -= 2)
			cout << a[j].first << " ";
		for (int j = s; j <= f; j += 2) {
			if (j != s)
				cout << " ";
			cout << a[j].first;
		}
		cout << endl;
		s = f + 1;
	}

	return 0;
}
/*
10 4
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
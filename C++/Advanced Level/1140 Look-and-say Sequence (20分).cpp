#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	string D;
	int N;
	cin >> D >> N;
	string ans = D, tmp;
	for (int i = 0; i < N - 1; ++i) {
		tmp = ans;
		ans.clear();
		for (int i = 0; i < tmp.size(); ++i) {
			int cnt = 1;
			while (i < tmp.size() - 1 && tmp[i + 1] == tmp[i]) {
				i++;
				cnt++;
			}
			ans += tmp[i];
			ans += ('0' + cnt);
		}
	}
	cout << ans << endl;

	return 0;
}
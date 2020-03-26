#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int M, N;
	cin >> M >> N;
	vector<int>pre(N);
	map<int, int>mp;
	for (int i = 0; i < N; ++i) {
		cin >> pre[i];
		mp[pre[i]]++;
	}
	for (int i = 0; i < M; ++i) {
		int a, b, ans;
		cin >> a >> b;
		if (!mp.count(a) && !mp.count(b))
			printf("ERROR: %d and %d are not found.\n", a, b );
		else if (!mp.count(a))
			printf("ERROR: %d is not found.\n", a);
		else if (!mp.count(b))
			printf("ERROR: %d is not found.\n", b );
		else {
			for (int j = 0; j < N; ++j) {
				ans = pre[j];
				if ((ans < a && ans > b) || (ans > a && ans < b) || ans == a || ans == b)
					break;
			}
			if (ans == a)
				printf("%d is an ancestor of %d.\n", a, b);
			else if (ans == b)
				printf("%d is an ancestor of %d.\n", b, a );
			else
				printf("LCA of %d and %d is %d.\n", a, b, ans );
		}
	}

	return 0;
}
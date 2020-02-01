#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 10;

int v[maxn];
int main(int argc, char const *argv[])
{
	int M, N, K;
	scanf("%d %d %d", &M, &N, &K);
	while (K--) {
		stack<int> s;
		for (int i = 0; i < N; ++i)
			scanf("%d", &v[i]);
		int t = N;
		bool flag = true;
		for (int i = N - 1; i >= 0; --i) {
			if (s.size() == M && s.top() != t) {
				flag = false;
				break;
			}
			s.push(v[i]);
			while (!s.empty() && s.top() == t) {
				t--;
				s.pop();
			}
		}
		if (flag && s.empty())
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}
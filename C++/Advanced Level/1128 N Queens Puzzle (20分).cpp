#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int K;
	scanf("%d", &K);
	while (K--) {
		int N, i, j;
		scanf("%d", &N);
		vector<int> v(N);
		for (i = 0; i < N; ++i)
			scanf("%d", &v[i]);
		for (i = 0; i < N; ++i) {
			int t1 = v[i], t2 = v[i];
			for (j = i + 1; j < N; ++j) {
				if (v[j] == ++t1)
					break;
				if (v[j] == --t2)
					break;
				if (v[j] == v[i])
					break;
			}
			if (j != N)
				break;
		}
		if (i != N)
			printf("NO\n");
		else
			printf("YES\n");
	}

	return 0;
}
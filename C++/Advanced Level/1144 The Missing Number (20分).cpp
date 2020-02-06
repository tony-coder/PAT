#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int N;
	scanf("%d", &N);
	set<int> s;
	for (int i = 0; i < N; ++i)
	{
		int tmp;
		scanf("%d", &tmp);
		if (tmp > 0)
			s.insert(tmp);
	}
	int i = 1;
	for (auto t : s) {
		if (t != i) {
			printf("%d\n", i);
			return 0;
		}
		i++;
	}

	printf("%d\n", i);

	return 0;
}
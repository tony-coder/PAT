#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int N;
	scanf("%d", &N);
	vector<unordered_set<int> > v(N);
	for (int i = 0; i < N; ++i)
	{
		int M;
		scanf("%d", &M);
		for (int j = 0; j < M; ++j)
		{
			int value;
			scanf("%d", &value);
			v[i].insert(value);
		}
	}
	int K;
	scanf("%d", &K);
	for (int i = 0; i < K; ++i)
	{
		int q1, q2;
		scanf("%d %d", &q1, &q2);
		q1--; q2--;
		double t = 0;
		for (auto x : v[q1])
		{
			if (v[q2].find(x) != v[q2].end())
				t++;
		}
		printf("%.1f%\n", t / (v[q1].size() + v[q2].size() - t) * 100);
	}
	return 0;
}
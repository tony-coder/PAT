#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

struct node
{
	LL id;
	int score;
	int final_rank, location_number, local_rank;
};

bool cmp1(node& n1, node& n2)
{
	return n1.score == n2.score ? n1.id < n2.id : n1.score > n2.score;
}

int main(int argc, char const *argv[])
{
	int N;
	scanf("%d", &N);
	vector<node> v;
	for (int i = 1; i <= N; ++i)
	{
		int K;
		scanf("%d", &K);
		vector<node> tmp(K);
		for (int j = 0; j < K; ++j)
		{
			scanf("%lld %d", &tmp[j].id, &tmp[j].score);
			tmp[j].location_number = i;
		}
		sort(tmp.begin(), tmp.end(), cmp1);
		tmp[0].local_rank = 1;
		v.push_back(tmp[0]);
		for (int j = 1; j < K; ++j)
		{
			if (tmp[j].score == tmp[j - 1].score)
				tmp[j].local_rank = tmp[j - 1].local_rank;
			else
				tmp[j].local_rank = j + 1;
			v.push_back(tmp[j]);
		}
	}
	sort(v.begin(), v.end(), cmp1);
	printf("%d\n", v.size());
	v[0].final_rank = 1;
	printf("%013lld %d %d %d\n", v[0].id, v[0].final_rank, v[0].location_number, v[0].local_rank);
	for (int i = 1; i < v.size(); ++i)
	{
		if (v[i].score == v[i - 1].score)
			v[i].final_rank = v[i - 1].final_rank;
		else
			v[i].final_rank = i + 1;
		printf("%013lld %d %d %d\n", v[i].id, v[i].final_rank, v[i].location_number, v[i].local_rank);
	}

	return 0;
}
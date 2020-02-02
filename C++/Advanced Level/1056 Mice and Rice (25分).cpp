#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 10;

struct node
{
	int weight;
	int rank;
} ans[maxn];

int main(int argc, char const *argv[])
{
	int Np, Ng;
	queue<int>q;
	scanf("%d%d", &Np, &Ng);
	for (int i = 0; i < Np; ++i)
		scanf("%d", &ans[i].weight);

	for (int i = 0; i < Np; ++i) {
		int tmp;
		scanf("%d", &tmp);
		q.push(tmp);
	}
	int cnt = Np;
	while (q.size() > 1) {
		int group = (cnt % Ng == 0) ? cnt / Ng : cnt / Ng + 1;
		for (int i = 0; i < group; ++i) {
			int Max = 0, pos = -1;
			for (int j = 0; j < Ng; ++j) {
				if (i * Ng + j == cnt) //到达末端
					break;
				if (ans[q.front()].weight > Max) {
					Max = ans[q.front()].weight;
					pos = q.front();
				}
				ans[q.front()].rank = group + 1;
				q.pop();
			}
			if (pos != -1)
				q.push(pos);
		}
		cnt = group;
	}
	ans[q.front()].rank = 1;
	printf("%d", ans[0].rank);
	for (int i = 1; i < Np; ++i)
		printf(" %d", ans[i].rank );
	return 0;
}
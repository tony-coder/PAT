#include <bits/stdc++.h>
using namespace std;
const int maxn = 500 + 10;
const int INF = 0x3f3f3f3f;

struct node
{
	double price, dist;
} st[maxn];

bool cmp(node& n1, node& n2)
{
	return n1.dist < n2.dist;
}
int main(int argc, char const *argv[])
{
	int N;
	double C, D, davg;
	cin >> C >> D >> davg >> N;
	for (int i = 0; i < N; ++i)
		cin >> st[i].price >> st[i].dist;
	st[N].dist = D;
	st[N].price = 0;
	sort(st, st + N, cmp);
	if (st[0].dist != 0) {
		printf("The maximum travel distance = 0.00\n");
		return 0;
	}
	int now = 0;
	double ans = 0., nowTank = 0., max_dist = C * davg;
	while (now < N) {
		int k = -1;
		double min_p = INF;
		//寻找当前加油站可到达范围内价格最低的加油站（除了现在的加油站）
		for (int i = now + 1; i <= N && st[i].dist - st[now].dist <= max_dist; ++i) {
			if (st[i].price < min_p) {
				min_p = st[i].price;
				k = i;
				if (min_p < st[now].price)
					break;
			}
		}
		//当前加油站没有可到达的下一个加油站
		if (k == -1)
			break;
		//到达下一加油站需要的油量
		double need = (st[k].dist - st[now].dist) / davg;
		//价格比当前加油站低，应该尽可能去价格低的加油站加油
		if (min_p < st[now].price) {
			if (nowTank < need) {  //油不够
				ans += (need - nowTank) * st[now].price;
				nowTank = 0;
			} else {  //油够了
				nowTank -= need;
			}
		} else {  //当前的油价是可到达范围内最低的，应该加满，然后去价格尽量低的加油站，重复上面的判断步骤
			ans += (C - nowTank) * st[now].price;
			nowTank = C - need;
		}
		now = k;
	}

	if (now == N)
		printf("%.2f\n", ans);
	else
		printf("The maximum travel distance = %.2f\n", st[now].dist + max_dist);


	return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 10;

struct node
{
	double inventory, prices;
} moomcake[maxn];

bool cmp(node& a, node& b) {
	return (a.prices / a.inventory) > (b.prices / b.inventory);
}

int main(int argc, char const *argv[])
{
	int N, D;
	scanf("%d%d", &N, &D);
	for (int i = 0; i < N; ++i)
		scanf("%lf", &moomcake[i].inventory);
	for (int i = 0; i < N; ++i)
		scanf("%lf", &moomcake[i].prices);

	sort(moomcake, moomcake + N, cmp);

	double ans = 0.;
	for (int i = 0; i < N && D; ++i)
	{
		if (moomcake[i].inventory > D) {
			ans += D * moomcake[i].prices / moomcake[i].inventory;
			D = 0;
		} else {
			ans += moomcake[i].prices;
			D -= moomcake[i].inventory;
		}
	}
	printf("%.2f\n", ans);

	return 0;
}
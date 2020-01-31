#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
struct node
{
	LL numerator, denominator;
} num[110];

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	LL gcd = 1;
	for (int i = 0; i < N; ++i)
	{
		scanf("%lld/%lld", &num[i].numerator, &num[i].denominator);
		if (i == 0)
			gcd = num[i].denominator;
		else
			gcd = __gcd(gcd, num[i].denominator);
	}
	LL sum_numerator = 0, sum_denominator = 1;

	for (int i = 0; i < N; ++i)
		sum_denominator *= (num[i].denominator / gcd);
	sum_denominator *= gcd;
	for (int i = 0; i < N; ++i)
		sum_numerator += num[i].numerator * (sum_denominator / num[i].denominator);
	if (sum_numerator == 0)
		printf("0\n");
	else
	{
		if (sum_numerator / sum_denominator != 0)
			printf("%lld ", sum_numerator / sum_denominator);
		sum_numerator -= (sum_numerator / sum_denominator) * sum_denominator;
		if (sum_numerator != 0)
		{
			int tmp = __gcd(sum_numerator, sum_denominator);
			sum_numerator /= tmp;
			sum_denominator /= tmp;
			printf("%lld/%lld", sum_numerator, sum_denominator );
		}
		printf("\n");
	}
	return 0;
}
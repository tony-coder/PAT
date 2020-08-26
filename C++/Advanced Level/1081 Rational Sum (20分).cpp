#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
struct node
{
	LL numerator, denominator;
} num[110];

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	LL gcd;
	for (int i = 0; i < N; ++i) {
		scanf("%lld/%lld", &num[i].numerator, &num[i].denominator);
		int t = __gcd(num[i].numerator, num[i].denominator);
		num[i].numerator /= t;
		num[i].denominator /= t;
	}
	node ans;
	for (int i = 0; i < N; ++i) {
		if (i == 0)
			ans  = {num[i].numerator, num[i].denominator};
		else {
			gcd = __gcd(ans.denominator, num[i].denominator);
			int t = (ans.denominator * num[i].denominator) / gcd;
			ans.numerator = ans.numerator * (t / ans.denominator) + num[i].numerator * (t / num[i].denominator);
			ans.denominator = t;

			//对结果进行约分
			t = __gcd(ans.numerator, ans.denominator);
			ans.numerator /= t;
			ans.denominator /= t;
		}
	}

	if (ans.numerator == 0)
		printf("0\n");
	else {
		if (ans.numerator / ans.denominator != 0)
			printf("%lld", ans.numerator / ans.denominator);
		if (ans.numerator / ans.denominator != 0 && ans.numerator - (ans.numerator / ans.denominator) * ans.denominator != 0)
			printf(" ");
		ans.numerator -= (ans.numerator / ans.denominator) * ans.denominator;
		if (ans.numerator != 0) {
			int tmp = __gcd(ans.numerator, ans.denominator);
			ans.numerator /= tmp;
			ans.denominator /= tmp;
			// 测试用例:
			// 2
			// -2/3 1/3
			// 对应输出应该为:
			// -1/3
			// 你的输出为:
			// 1/-3
			if (ans.denominator < 0) {
				ans.denominator *= -1;
				ans.numerator *= -1;
			}
			printf("%lld/%lld", ans.numerator, ans.denominator );
		}
		printf("\n");
	}
	return 0;
}
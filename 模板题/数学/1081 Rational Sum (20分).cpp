#include <bits/stdc++.h>
using namespace std;

struct Fraction {
	int up, down;
};

// 化简
Fraction reduction(Fraction result) {
	if (result.down < 0) {
		result.up *= -1;
		result.down *= -1;
	}
	if (result.up == 0)
		result.down = 1;
	else {
		int t = __gcd(abs(result.up), abs(result.down));
		result.up /= t;
		result.down /= t;
	}
	return result;
}

// 分数加法
Fraction add(Fraction f1, Fraction f2) {
	Fraction result;
	result.up = f1.up * f2.down + f2.up * f1.down;
	result.down = f1.down * f2.down;
	return reduction(result);
}

void show(Fraction result) {
	result = reduction(result);
	if (result.down == 1)
		printf("%d\n", result.up);
	else if (abs(result.up) > abs(result.down)) // 假分数
		printf("%d %d/%d\n", result.up / result.down, result.up % result.down, result.down);
	else
		printf("%d/%d\n", result.up, result.down);
}

int main(int argc, char const *argv[])
{
	int N;
	scanf("%d", &N);
	Fraction result = {0, 1};
	Fraction tmp;
	for (int i = 0; i < N; ++i) {
		scanf("%d/%d", &tmp.up, &tmp.down);
		result = add(result, tmp);
	}
	show(result);
	return 0;
}
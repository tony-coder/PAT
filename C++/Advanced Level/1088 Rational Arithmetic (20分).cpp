#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

struct Fraction {
	LL up, down;
};

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

Fraction add(Fraction f1, Fraction f2) {
	Fraction result;
	result.up = f1.up * f2.down + f2.up * f1.down;
	result.down = f1.down * f2.down;
	return reduction(result);
}

Fraction sub(Fraction f1, Fraction f2) {
	Fraction result;
	result.up = f1.up * f2.down - f2.up * f1.down;
	result.down = f1.down * f2.down;
	return reduction(result);
}

Fraction mul(Fraction f1, Fraction f2) {
	Fraction result;
	result.up = f1.up * f2.up;
	result.down = f1.down * f2.down;
	return reduction(result);
}

Fraction div(Fraction f1, Fraction f2) {
	Fraction result;
	result.up = f1.up * f2.down;
	result.down = f1.down * f2.up;
	return reduction(result);
}

void show(Fraction result) {
	result = reduction(result);
	if (result.up < 0)
		printf("(");
	if (result.down == 1)
		printf("%lld", result.up);
	else if (abs(result.up) > abs(result.down))
		printf("%lld %lld/%lld", result.up / result.down, abs(result.up) % result.down, result.down);
	else
		printf("%lld/%lld", result.up, result.down);
	if (result.up < 0)
		printf(")");
}

int main(int argc, char const *argv[])
{
	Fraction a, b;
	scanf("%lld/%lld %lld/%lld", &a.up, &a.down, &b.up, &b.down);
	// add
	show(a); printf(" + "); show(b); printf(" = "); show(add(a, b)); printf("\n");
	// sub
	show(a); printf(" - "); show(b); printf(" = "); show(sub(a, b)); printf("\n");
	// mul
	show(a); printf(" * "); show(b); printf(" = "); show(mul(a, b)); printf("\n");
	// div
	show(a); printf(" / "); show(b); printf(" = ");
	if (b.up == 0)
		printf("Inf");
	else
		show(div(a, b));
	printf("\n");
	return 0;
}
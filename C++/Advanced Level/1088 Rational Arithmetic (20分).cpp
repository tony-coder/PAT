#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

struct node {
	LL k, a, b; //k a/b
};

void simply(node& n) {
	n.a += n.k * n.b;
	n.k = 0;
	LL tmp = abs(__gcd(n.a, n.b));
	n.a /= tmp;
	n.b /= tmp;
	n.k += n.a / n.b;
	n.a = n.a % n.b;
}

void add(node n1, node n2, node& ans) {
	ans.k = n1.k + n2.k;
	LL t = __gcd(n1.b, n2.b);
	ans.b = n1.b * n2.b / t;
	ans.a = n1.a * (ans.b / n1.b) + n2.a * (ans.b / n2.b);
	simply(ans);
}

void sub(node n1, node n2, node& ans) {
	n2.k = -n2.k;
	n2.a = -n2.a;
	add(n1, n2, ans);
}

void mul(node n1, node n2, node& ans) {
	ans.a = (n1.a + n1.k * n1.b) * (n2.a + n2.k * n2.b);
	ans.b = n1.b * n2.b;
	simply(ans);
}

bool divi(node n1, node n2, node& ans) {
	n1.a += n1.b * n1.k;
	n2.a += n2.b * n2.k;
	ans.a = n1.a * n2.b;
	ans.b = n1.b * n2.a;
	if (ans.b == 0)
		return false;
	else if (ans.b < 0) {
		ans.b = -ans.b;
		ans.a = -ans.a;
	}
	simply(ans);
	return true;
}

void show(node& n) {
	if (n.k < 0) {
		if (n.a != 0)
			printf("(%lld %lld/%lld)", n.k, abs(n.a), n.b );
		else
			printf("(%lld)", n.k );
	} else if (n.k > 0) {
		if (n.a != 0) {
			printf("%lld %lld/%lld", n.k, n.a, n.b );
		}
		else
			printf("%lld", n.k );
	} else {
		if (n.a != 0) {
			if (n.a > 0)
				printf("%lld/%lld", n.a, n.b);
			else
				printf("(%lld/%lld)", n.a, n.b );
		}
		else
			printf("%lld", n.k);
	}
}

int main(int argc, char const *argv[])
{
	node n1 = {0, 0, 0}, n2 = {0, 0, 0};
	scanf("%lld/%lld %lld/%lld", &n1.a, &n1.b, &n2.a, &n2.b);
	simply(n1); simply(n2);
	// printf("%d %d/%d %d %d/%d\n", n1.k, n1.a, n1.b, n2.k, n2.a, n2.b );
	node ans = {0, 0, 0};
	add(n1, n2, ans);
	show(n1); printf(" + "); show(n2); printf(" = "); show(ans); printf("\n");
	ans = {0, 0, 0};
	sub(n1, n2, ans);
	show(n1); printf(" - "); show(n2); printf(" = "); show(ans); printf("\n");
	ans = {0, 0, 0};
	mul(n1, n2, ans);
	show(n1); printf(" * "); show(n2); printf(" = "); show(ans); printf("\n");
	ans = {0, 0, 0};
	if (divi(n1, n2, ans)) {
		show(n1); printf(" / "); show(n2); printf(" = "); show(ans); printf("\n");
	} else {
		show(n1); printf(" / "); show(n2); printf(" = Inf"); printf("\n");
	}
	return 0;
}
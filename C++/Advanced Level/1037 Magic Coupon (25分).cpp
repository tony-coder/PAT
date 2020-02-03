#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int N, M;
	scanf("%d", &N);
	vector<int> coupons(N);
	for (int i = 0; i < N; ++i)
		scanf("%d", &coupons[i]);
	scanf("%d", &M);
	vector<int> product(M);
	for (int i = 0; i < M; ++i)
		scanf("%d", &product[i]);
	sort(coupons.begin(), coupons.end(), [](int a, int b) {return a > b;});
	sort(product.begin(), product.end(), [](int a, int b) {return a > b;});
	int ans = 0;
	int i = 0, j = 0;
	while (i < N && j < M) {
		if (coupons[i] >= 0 && product[j] >= 0) {
			ans += coupons[i] * product[j];
			i++; j++;
		} else
			break;
	}
	while (coupons[i] >= 0 && i < N)
		i++;
	while (product[j] >= 0 && j < M)
		j++;
	int t1 = N - 1, t2 = M - 1;
	while (t1 >= i && t2 >= j) {
		if (coupons[t1] < 0 && product[t2] < 0) {
			ans += coupons[t1] * product[t2];
			t1--; t2--;
		} else
			break;
	}
	printf("%d\n", ans);

	return 0;
}
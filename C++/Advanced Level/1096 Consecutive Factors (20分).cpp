#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(int argc, char const *argv[])
{
	LL N;
	cin >> N;
	LL sqr = sqrt(1.0 * N);
	LL maxL = 0, start = 0;
	for (LL i = 2; i <= sqr; ++i) {
		LL tmp = 1, j = i;
		while (1) {
			tmp *= j;
			if (N % tmp)
				break;
			if (j - i + 1 > maxL) {
				maxL = j - i + 1;
				start = i;
			}
			j++;
		}
	}
	if (maxL == 0)
		cout << "1\n" << N << endl;
	else {
		cout << maxL << endl;
		LL i;
		for (i = start; i < start + maxL - 1; ++i)
			cout << i << "*";
		cout << i << endl;
	}

	return 0;
}
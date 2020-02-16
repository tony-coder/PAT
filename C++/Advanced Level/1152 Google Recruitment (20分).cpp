#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

bool isprime(LL n) {
	if (n == 1 || n == 0)
		return false;
	for (int i = 2; i * i <=  n; ++i) {
		if (n % i == 0)
			return false;
	}
	return true;
}

int main(int argc, char const *argv[])
{
	int L, K, i;
	cin >> L >> K;
	string num;
	cin >> num;
	for (i = 0; i < L - K + 1; ++i) {
		string s = num.substr(i, K);
		LL t = stoll(s);
		if (isprime(t)) {
			cout << s << endl;
			break;
		}
	}
	if (i == L - K + 1)
		cout << "404" << endl;

	return 0;
}
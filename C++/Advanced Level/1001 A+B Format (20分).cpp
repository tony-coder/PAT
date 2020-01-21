#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int a, b, sum;
	cin >> a >> b;
	sum = a + b;

	string ans = "";
	int count = 0;
	if (sum < 0) {
		sum = -sum;
		while (sum) {
			ans += '0' + sum % 10;
			if (count == 2 && sum >= 10)
			{
				count = -1;
				ans += ',';
			}
			count++;
			sum /= 10;
		}
		ans += '-';
	}
	else if (sum == 0) {
		ans = '0';
	}
	else {
		while (sum) {
			ans += '0' + sum % 10;
			if (count == 2 && sum >= 10)
			{
				count = -1;
				ans += ',';
			}
			count++;
			sum /= 10;
		}
	}
	for (int i = ans.size() - 1; i >= 0; i--)
	{
		cout << ans[i];
	}
	cout << endl;

	return 0;
}
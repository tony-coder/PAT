#include <bits/stdc++.h>
using namespace std;

/*
找规律题，计算每一位对应的1的个数，然后相加，每一位的1的计算情况分三种情况：
1.如果当前位数字为0，那么该位的1的个数由更高位的数字确定。比如2120，个位为1的个数为212 * 1 = 212（个位的单位为1）。
2.如果当前位数字为1，那么该位的1的个数不但由高位决定，还由低位数字决定。比如2120百位为1，那么百位数字1的个数为2 * 100 + 20 + 1 = 221个（百位的单位为100）。
3.如果当前位数字大于1，那么该位数字1的个数为（高位数+ 1） * 位数单位。比如2120十位为2，那么十位数字1的个数为（21 + 1） * 10 = 220个（十位的单位为10）
*/

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	int digit = 1, left, right, ans = 0;
	while (N / digit) {
		int now = N / digit % 10;
		left = N / (digit * 10);
		right = N % digit;
		if (now == 0)
			ans += left * digit;
		else if (now == 1)
			ans += left * digit + right + 1;
		else
			ans += (left + 1) * digit;
		digit *= 10;
	}
	cout << ans << endl;

	return 0;
}
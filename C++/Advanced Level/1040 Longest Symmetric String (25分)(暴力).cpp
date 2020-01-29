#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	string s;
	getline(cin, s);

	int ans = 1, len = s.size();
	for (int i = 0; i < len; ++i)
	{
		int left, right, tmp = 1;
		left = i - 1, right = i + 1;
		while (left >= 0 && right < len)
		{
			if (s[left--] == s[right++])
				tmp += 2;
			else
				break;
		}
		ans = max(ans, tmp);

		tmp = 0, left = i, right = i + 1;
		while (left >= 0 && right < len)
		{
			if (s[left--] == s[right++])
				tmp += 2;
			else
				break;
		}
		ans = max(ans, tmp);
	}
	printf("%d\n", ans);

	return 0;
}
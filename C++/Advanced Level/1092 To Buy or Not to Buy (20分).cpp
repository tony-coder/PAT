#include <bits/stdc++.h>
using namespace std;

int v[256];
int main(int argc, char const *argv[])
{
	string s1, s2;
	cin >> s1 >> s2;

	for (int i = 0; i < s1.size(); ++i)
		v[s1[i]]++;
	for (int i = 0; i < s2.size(); ++i)
		v[s2[i]]--;
	int cnt1 = 0, cnt2 = 0;
	for (int i = 0; i < 256; ++i)
	{
		if (v[i] > 0)
			cnt1 += v[i];
		else if (v[i] < 0)
			cnt2 += (-v[i]);
	}
	if (cnt2 > 0)
		printf("No %d\n", cnt2);
	else
		printf("Yes %d\n", cnt1);

	return 0;
}
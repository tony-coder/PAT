#include <bits/stdc++.h>
using namespace std;

string weeks[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
int main(int argc, char const *argv[])
{
	string s1, s2, s3, s4;
	cin >> s1 >> s2 >> s3 >> s4;
	string week;
	int len, i, hour, min;
	len = s1.size() < s2.size() ? s1.size() : s2.size();
	for (i = 0; i < len; ++i)
		if (s1[i] == s2[i] && 'A' <= s1[i] && s1[i] <= 'G')
			break;
	week = weeks[s1[i] - 'A'];
	i++;
	for (; i < len; ++i)
		if (s1[i] == s2[i] && (s1[i] >= '0' && s1[i] <= '9' || 'A' <= s1[i] && s1[i] <= 'N'))
			break;
	if (i == len)
		hour = 0;
	else if (s1[i] >= '0' && s1[i] <= '9')
		hour = s1[i] - '0';
	else
		hour = s1[i] - 'A' + 10;

	len = s3.size() < s4.size() ? s3.size() : s4.size();
	for (i = 0; i < len; ++i)
		if (s3[i] == s4[i] && isalpha(s3[i]))
			break;
	min = i;
	printf("%s %02d:%02d\n", week.c_str(), hour, min);

	return 0;
}
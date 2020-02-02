#include <bits/stdc++.h>
using namespace std;

bool cmp(char a, char b) {
	return a > b;
}

int main(int argc, char const *argv[])
{
	string s;
	cin >> s;

	while (true) {
		while (s.size() < 4) //补全
			s.push_back('0');
		int Max, Min;
		sort(s.begin(), s.end());
		Min = stoi(s);
		sort(s.begin(), s.end(), cmp);
		Max = stoi(s);
		printf("%04d - %04d = %04d\n", Max, Min, Max - Min );

		if (Max - Min == 6174 || Max - Min == 0)
			break;
		s = to_string(Max - Min);
	}

	return 0;
}
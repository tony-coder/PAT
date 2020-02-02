#include <bits/stdc++.h>
using namespace std;

bool cmp(char a, char b) {
	return a > b;
}

int main(int argc, char const *argv[])
{
	string s;
	stringstream ss;
	cin >> s;

	while (true) {
		while (s.size() < 4) //补全
			s.push_back('0');
		int Max, Min;
		sort(s.begin(), s.end());
		ss << s;
		ss >> Min;
		ss.clear();
		sort(s.begin(), s.end(), cmp);
		ss << s;
		ss >> Max;
		ss.clear();
		printf("%04d - %04d = %04d\n", Max, Min, Max - Min );

		if (Max - Min == 6174 || Max - Min == 0)
			break;
		ss << Max - Min;
		ss >> s;
		ss.clear();
	}

	return 0;
}
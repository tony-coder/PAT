#include <bits/stdc++.h>
using namespace std;

char change(int i)
{
	switch (i)
	{
	case 0:
		return '0';
	case 1:
		return '1';
	case 2:
		return '2';
	case 3:
		return '3';
	case 4:
		return '4';
	case 5:
		return '5';
	case 6:
		return '6';
	case 7:
		return '7';
	case 8:
		return '8';
	case 9:
		return '9';
	case 10:
		return 'A';
	case 11:
		return 'B';
	case 12:
		return 'C';
	}
}

string solve(int a)
{
	string s;
	while (a)
	{
		int tmp = a % 13;
		s += change(tmp);
		a /= 13;
	}
	if (s.size() == 1)
		s += '0';
	else if (s.size() == 0)
		s = "00";
	reverse(s.begin(), s.end());
	return s;
}

int main(int argc, char const *argv[])
{
	int R, G, B;
	cin >> R >> G >> B;
	string ans = solve(R) + solve(G) + solve(B);

	printf("#%s\n", ans.c_str());
	return 0;
}
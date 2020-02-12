#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	LL Z;
	while (N--) {
		cin >> Z;
		string z_s = to_string(Z);
		int len = z_s.length() / 2;
		string s1, s2;
		s1 = z_s.substr(0, len);
		s2 = z_s.substr(len);
		LL t1, t2;
		t1 = stoll(s1);
		t2 = stoll(s2);
		if (t1 == 0 || t2 == 0)
			cout << "No" << endl;
		else if (Z % (t1 * t2) == 0)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}

	return 0;
}
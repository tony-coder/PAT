#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	LL Z;
	stringstream ss;
	while (N--) {
		cin >> Z;
		string z_s;
		ss << Z;
		ss >> z_s;
		ss.clear();
		int len = z_s.length() / 2;
		string s1, s2;
		s1 = z_s.substr(0, len);
		s2 = z_s.substr(len);
		// cout << s1 << " " << s2 << endl;
		LL t1, t2;
		ss << s1;
		ss >> t1;
		ss.clear();
		ss << s2;
		ss >> t2;
		ss.clear();
		// t1 = stoi(s1);
		// t2 = stoi(s2);
		if (t1 == 0 || t2 == 0)
			cout << "No" << endl;
		else if (Z % (t1 * t2) == 0)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}

	return 0;
}
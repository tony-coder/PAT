#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	string s, num, ep;
	char ns, es;
	cin >> s;
	int e = s.find('E');
	num = s.substr(1, e - 1);
	ns = s[0];
	es = s[e + 1];
	ep = s.substr(e + 2);
	num.erase(1, 1); //去除小数点
	if (ns == '-')
		cout << ns;
	if (es == '-') {
		cout << "0.";
		for (int i = 0; i < stoi(ep) - 1; ++i)
			cout << "0";
		cout << num << endl;
	} else {
		if (stoi(ep) >= num.length() - 1) {
			cout << num;
			for (int i = 0; i < stoi(ep) - num.length() + 1; ++i)
				cout << "0";
			cout << endl;
		} else {
			num.insert(stoi(ep) + 1, ".");
			cout << num << endl;
		}
	}

	return 0;
}
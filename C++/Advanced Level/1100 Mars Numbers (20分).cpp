#include <bits/stdc++.h>
using namespace std;

string low[] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string high[] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	cin.get();
	while (N--) {
		string s;
		int num = 0;
		getline(cin, s);
		if (isdigit(s[0])) {
			num = stoi(s);
			if (num / 13 != 0)
				cout << high[num / 13];
			if (num / 13 != 0 && num % 13 == 0) {
				cout << endl;
				continue;
			} else if (num / 13 != 0 && num % 13 != 0)
				cout << " ";
			cout << low[num % 13] << endl;
		} else {
			stringstream ss;
			ss << s;
			while (ss >> s) {
				for (int i = 0; i < 13; ++i)
					if (high[i] == s)
						num += i * 13;
				for (int i = 0; i < 13; i++)
					if (low[i] == s)
						num += i;
			}
			cout << num << endl;
		}
	}
	return 0;
}
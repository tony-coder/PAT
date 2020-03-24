#include <bits/stdc++.h>
using namespace std;

string s[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
string s1[] = {"", "Shi", "Bai", "Qian", "Wan", "Shi", "Bai", "Qian", "Yi"};
int main(int argc, char const *argv[])
{
	string num;
	cin >> num;
	vector<string>ans;
	for (int i = num.size() - 1, k = 0; i >= 0; --i, k++) {
		if (num[i] == '0') {
			if (k == 4) { // 当"Wan"位上为0时，是否需要打印"Wan"，像亿就不需要打印
				int tmp = stoi(num.substr(0, i + 1));
				if (tmp % 10000)  // //如101000000,需要加,100000010不需要
					ans.push_back("Wan");
			}
			if (ans.size() == 0 || ans.back() == "ling" || ans.back() == "Wan")
				continue;
			ans.push_back("ling");
			continue;
		}
		if (num[i] == '-') {
			ans.push_back("Fu");
			break;
		}
		if (k)
			ans.push_back(s1[k]);
		ans.push_back(s[num[i] - '0']);
	}
	int i;
	for (i = ans.size() - 1; i >= 1; --i)
		cout << ans[i] << " ";
	if (i == 0)
		cout << ans[i] << endl;
	else
		cout << "ling" << endl;

	return 0;
}
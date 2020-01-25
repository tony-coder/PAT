#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	string s;
	cin >> s;
	int len = s.size();
	int n1, n2, space;
	n1 = (len + 2) / 3;
	n2 = (len + 2 - n1 * 2);
	space = n2 - 2;
	int i;
	for ( i = 0; i < n1 - 1; ++i)
	{
		cout << s[i];
		for (int j = 0; j < space; ++j)
			cout << " ";
		cout << s[len - 1 - i] << endl;
	}
	while (n2--)
	{
		cout << s[i];
		i++;
	}
	cout << endl;


	return 0;
}
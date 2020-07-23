#include <bits/stdc++.h>
using namespace std;

// 对应26个字母
char words[30][7][5];
// char s[20];
int main(int argc, char const *argv[])
{
	for (int i = 0; i < 26; ++i) {
		for (int j = 0; j < 7; ++j) {
			for (int z = 0; z < 5; ++z)
				scanf("%c", &words[i][j][z]);
			cin.get();
		}
	}
	// scanf("%s", s);
	string s;
	// cin >> s;
	getline(cin, s);
	int cnt = 0;
	bool flag = false;
	size_t i;
	for (i = 0; i < s.length(); ++i) {
		if ((s[i] < 'A' || s[i] > 'Z')) {
			if (!cnt)
				continue;
			string tmp = s.substr(i - cnt , cnt);
			// cout << tmp << endl;
			if (flag)
				printf("\n");
			else
				flag = true;
			for (int j = 0; j < 7; ++j) {
				size_t k;
				for (k = 0; k < tmp.size() - 1; ++k) {
					for (int z = 0; z < 5; ++z) {
						printf("%c", words[tmp[k] - 'A'][j][z] );
					}
					printf(" ");
				}
				for (int z = 0; z < 5; ++z) {
					printf("%c", words[tmp[k] - 'A'][j][z] );
				}
				printf("\n");
			}
			cnt = 0;
		} else
			cnt++;
		// cout <<s[i]<< " "<<i << " " << cnt << endl;
	}
	// cout << cnt << endl;
	if (cnt) {
		string tmp = s.substr(i - cnt , cnt);
		// cout << tmp << endl;
		if (flag)
			printf("\n");
		else
			flag = true;
		for (int j = 0; j < 7; ++j) {
			size_t k;
			for (k = 0; k < tmp.size() - 1; ++k) {
				for (int z = 0; z < 5; ++z) {
					printf("%c", words[tmp[k] - 'A'][j][z] );
				}
				printf(" ");
			}
			for (int z = 0; z < 5; ++z) {
				printf("%c", words[tmp[k] - 'A'][j][z] );
			}
			printf("\n");
		}
	}

	return 0;
}
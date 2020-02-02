#include <bits/stdc++.h>
using namespace std;

char s[6];
bool cmp(char a, char b) {
	return a > b;
}

int main(int argc, char const *argv[])
{
	scanf("%s", s);

	while (true) {
		while (strlen(s) < 4) //补全
			s[strlen(s)] = '0';
		s[4] = '\0';
		int Max, Min;
		sort(s, s + 4);
		// Min = atoi(s);
		sscanf(s, "%d", &Min);
		sort(s, s + 4, cmp);
		// Max = atoi(s);
		sscanf(s, "%d", &Max);

		printf("%04d - %04d = %04d\n", Max, Min, Max - Min );

		if (Max - Min == 6174 || Max - Min == 0)
			break;
		sprintf(s, "%d", Max - Min);
	}

	return 0;
}
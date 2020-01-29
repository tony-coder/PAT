#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000;

char s[maxn];
char s_new[maxn * 2];
int p[maxn * 2];

int init()
{
	int len = strlen(s);
	s_new[0] = '$';
	s_new[1] = '#';
	int j = 2;
	for (int i = 0; i < len; ++i)
	{
		s_new[j++] = s[i];
		s_new[j++] = '#';
	}
	return j;
}

int Manacher()
{
	int mx = 0, id = 0, ans = 0;
	int len = init();
	for (int i = 1; i < len; ++i)
	{
		if (i < mx)
			p[i] = min(p[2 * id - i], mx - i); //mx-i防止超越mx
		else
			p[i] = 1;
		while (s_new[i - p[i]] == s_new[i + p[i]])
			p[i]++;

		if (i + p[i] > mx)
		{
			id = i;
			mx = i + p[i];
		}

		ans = max(ans, p[i] - 1);
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	scanf("%[^\n]", s);

	int ans = Manacher();
	printf("%d\n", ans);

	return 0;
}
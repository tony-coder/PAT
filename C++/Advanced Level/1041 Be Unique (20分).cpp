#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;

int num[maxn];
int vis[maxn];
int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < N; ++i)
	{
		cin >> num[i];
		vis[num[i]]++;
	}
	int j;
	for ( j = 0; j < N; ++j)
	{
		if (vis[num[j]] == 1)
		{
			cout << num[j] << endl;
			break;
		}
	}

	if (j == N)
		cout << "None" << endl;


	return 0;
}
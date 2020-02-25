#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;

int v[maxn];
int vis[maxn];
int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> v[i];
	bool flag = true;
	for (int i = 1; i <= N; ++i) {
		for (int j = i + 1; j <= N; ++j) {
			fill(vis, vis + maxn, 1);
			vis[i] = vis[j] = -1; // 假设i,j为狼人
			vector<int> lies;
			for (int k = 1; k <= N; ++k) {
				if (v[k]*vis[abs(v[k])] < 0)
					lies.push_back(k);
			}
			if (lies.size() == 2 && (vis[lies[0]] + vis[lies[1]]) == 0) {
				printf("%d %d\n", i, j);
				flag = false;
				break;
			}
		}
		if (!flag)
			break;
	}
	if (flag)
		printf("No Solution\n");

	return 0;
}
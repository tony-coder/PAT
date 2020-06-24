#include <bits/stdc++.h>
using namespace std;

int g[1286][128][60];
bool vis[1286][128][60];
int direction[6][3] = {{1, 0, 0}, { -1, 0, 0}, { 0, 1, 0}, { 0, -1, 0}, {0, 0, 1}, {0, 0, -1}}; // 移动方向
int M, N, L, T;

typedef struct {
	int x, y, z;
} node;

int BFS(int x, int y, int z, int t) {
	queue<node> q;
	q.push({x, y, z});
	vis[x][y][z] = true;
	int cnt = 0;
	while (!q.empty()) {
		cnt++;
		node t = q.front();
		q.pop();
		for (int i = 0; i < 6; ++i) {
			int nx, ny, nz;
			nx = t.x + direction[i][0];
			ny = t.y + direction[i][1];
			nz = t.z + direction[i][2];
			if (nx >= 0 && nx < M && ny >= 0 && ny < N && nz >= 0 && nz < L && !vis[nx][ny][nz] && g[nx][ny][nz] == 1) {
				// cnt++;
				vis[nx][ny][nz] = true;
				// cout << nx << " " << ny << " " << nz << endl;
				q.push({nx, ny, nz});
			}
		}
	}
	return cnt >= t ? cnt : 0;
}

int main(int argc, char const *argv[])
{
	cin >> M >> N >> L >> T;
	for (int z = 0; z < L; ++z) {
		for (int i = 0; i < M; ++i) {
			for (int j = 0; j < N; ++j) {
				cin >> g[i][j][z];
			}
		}
	}
	int ans = 0;
	memset(vis, false, sizeof(vis));
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			for (int z = 0; z < L; ++z) {
				if (!vis[i][j][z] && g[i][j][z] == 1) {
					ans += BFS(i, j, z, T) ;
				}
			}
		}
	}
	cout << ans << endl;

	return 0;
}
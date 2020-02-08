#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 10;
typedef unsigned long long LL;

vector<int> v[maxn];
bool vis[maxn];

void init() {
    memset(vis, false, sizeof(vis));
}

void solve(int k) {
    vis[k] = true;
    for (size_t i = 0; i < v[k].size(); ++i) {
        if (vis[v[k][i]] == false)
            solve(v[k][i]);
    }
}


int main(int argc, char const *argv[])
{
    int N, M, K;
    cin >> N >> M >> K;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int city;
    for (int i = 0; i < K; ++i) {
        init();
        cin >> city;
        int ans = 0;
        vis[city] = true;
        for (int i = 1; i <= N; ++i) {
            if (vis[i] == false) {
                solve(i);
                ans++;
            }
        }
        cout << ans - 1 << endl;
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
typedef unsigned long long LL;

bool prime[maxn];
void init() {
    memset(prime, true, sizeof(prime));
    prime[0] = false; prime[1] = false;
    for (LL i = 2; i < maxn; ++i)
        if (prime[i])
            for (LL j = i * i; j < maxn; j += i)
                prime[j] = false;
}

int main(int argc, char const * argv[])
{
    init();

    int N, D;
    while ( cin >> N && N > 0) {
        cin >> D;
        string s = "";
        int tmp = N;
        while (N) {
            s += (N % D) + '0';
            N /= D;
        }

        int ans = 0, t = 1;
        for (int i = s.size() - 1; i >= 0; --i) {
            ans += (s[i] - '0') * t;
            t *= D;
        }
        // cout << ans << endl;
        if (prime[tmp] && prime[ans] == true)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}

// 73 10
// 23 2
// 23 10
// -2
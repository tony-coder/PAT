#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
typedef unsigned long long LL;

int main(int argc, char const *argv[])
{
    double W, T, L;
    double tmp = 0, ans = 1.;
    string s = "";
    for (int i = 0; i < 3; ++i)
    {
        cin >> W >> T >> L;
        tmp = max(W, max(T, L));
        if (tmp == W)
            s += "W ";
        else if (tmp == T)
            s += "T ";
        else
            s += "L ";
        ans *= tmp;
    }
    ans = (ans * 0.65 - 1) * 2;
    cout << s;
    printf("%.2f", ans);

    return 0;
}
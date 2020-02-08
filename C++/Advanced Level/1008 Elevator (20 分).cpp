#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;

int a[maxn];
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    int tot = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] > a[i - 1])
            tot += (a[i] - a[i - 1]) * 6;
        else if (a[i] <= a[i - 1])
            tot += (a[i - 1] - a[i]) * 4;

        tot += 5;
    }

    cout << tot << endl;

    return 0;
}
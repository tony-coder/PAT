#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 100000 + 10;
// 10
// -10 1 2 3 4 -5 -23 3 7 -21
int a[maxn];
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    LL ans = a[0], tmp = 0;
    int left = 0, t_left = 0, right = 0;
    for (int i = 0; i < n; i++)
    {
        tmp += a[i];

        if (tmp > ans)
        {
            left = t_left;
            right = i;
            ans = tmp;
        }

        if (tmp < 0)
        {
            tmp = 0;
            t_left = i + 1;
        }

    }
    if (ans < 0)
    {
        cout << 0 << " " << a[0] << " " << a[n - 1];
    }
    else
        cout << ans << " " << a[left] << " " << a[right];


    return 0;
}
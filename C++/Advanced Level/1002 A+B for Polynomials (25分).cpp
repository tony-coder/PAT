#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 10;

double a[maxn];
int main(int argc, char const *argv[])
{
    int m, n, x;
    double y;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        a[x] += y;
    }
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        a[x] += y;
    }
    int count = 0;
    for (int i = 0; i <= maxn; i++)
    {
        if (a[i] != 0)
            count++;
    }
    printf("%d", count);
    for (int i = maxn; i >= 0; i--)
    {
        if (a[i] == 0)
            continue;
        printf(" %d %.1f", i, a[i]);
    }


    return 0;
}

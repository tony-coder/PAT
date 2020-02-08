#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
typedef unsigned long long LL;

int change(char ch, int radix)
{
    if (ch >= '0' && ch <= '9')
    {
        if (ch - '0' >= radix)
            return -1;
        else
            return ch - '0';
    }
    else
    {
        if (10 + ch - 'a' >= radix)
            return -1;
        else
            return ch - 'a' + 10;
    }
}

LL toDecimal(string n, int radix)
{
    LL ans = 0LL;
    LL t = 1LL;
    for (int i = n.size() - 1; i >= 0; --i)
    {
        if (change(n[i], radix) == -1)
            return -1;
        ans += change(n[i], radix) * t;
        t *= radix;
    }
    return ans;
}

int binarySearch(LL n, string s, LL left, LL right)
{
    LL mid, tmp;

    while (left <= right)
    {
        mid = (left + right) / 2;
        tmp = toDecimal(s, mid);
        if (tmp > n)
            right = mid - 1;
        else if (tmp < n)
            left = mid + 1;
        else
            return mid;
    }

    return -1;
}

int main(int argc, char const *argv[])
{
    string N1, N2;
    int tag, radix;

    cin >> N1 >> N2 >> tag >> radix;

    LL tmp;
    string target;
    if (tag == 1)
    {
        tmp = toDecimal(N1, radix);
        target = N2;
    }
    else
    {
        tmp = toDecimal(N2, radix);
        target = N1;
    }

    int i;

    // cout << target << " " << tmp << endl;
    // int Max = 'z' - 'a' + 10 + 1;
    LL Max = 200;
    LL Min = 0;
    for (size_t i = 0; i < target.size(); ++i)
    {
        if (target[i] >= '0' && target[i] <= '9')
            Min = max(Min, (LL)(target[i] - '0' + 1));
        else
            Min = max(Min, (LL)(target[i] - 'a' + 10 + 1));
    }
    Max = max((LL)Min, tmp);

    // cout << Max << endl;
    // for (i = 2; i <= Max; ++i)
    // {
    //     if (toDecimal(target, i) == tmp)
    //         break;
    // }

    i = binarySearch(tmp, target, Min, Max);

    if (i == -1)
        cout << "Impossible" << endl;
    else
        cout << i << endl;

    return 0;
}
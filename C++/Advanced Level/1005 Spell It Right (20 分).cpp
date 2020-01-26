#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

string m[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

string change(LL a)
{
    string s = "";
    while (a)
    {
        s += (a % 10) + '0';
        a /= 10;
    }
    if (s != "")
        reverse(s.begin(), s.end());
    else
        s = '0';
    return s;

}

int main(int argc, char const *argv[])
{
    std::ios::sync_with_stdio(false);
    string s;
    cin >> s;
    LL ans = 0;
    for (int i = 0; i < s.size(); i++)
        ans += s[i] - '0';

    string ss = change(ans);
    // cout<<ss<<endl;
    int i;
    for (i = 0; i < ss.size() - 1; i++)
    {
        // printf("%s ",m[ss[i]-'0']);
        cout << m[ss[i] - '0'] + " ";
    }
    cout << m[ss[i] - '0'];


    return 0;
}
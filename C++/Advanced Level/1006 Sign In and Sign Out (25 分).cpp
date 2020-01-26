#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 100000;

// 3
// CS301111 15:30:28 17:00:10
// SC3021234 08:00:00 11:25:25
// CS301133 21:45:00 21:58:40
struct person
{
    string ID_number;
    string Sign_in_time;
    string Sign_out_time;
} P[maxn];

bool cmp(string t1, string t2)
{
    if (t1.substr(0, 2) < t2.substr(0, 2))
        return true;
    else if (t1.substr(0, 2) > t2.substr(0, 2))
        return false;
    else
    {
        if (t1.substr(3, 2) < t2.substr(3, 2))
            return true;
        else if (t1.substr(3, 2) > t2.substr(3, 2))
            return false;
        else
        {
            if (t1.substr(6, 2) < t2.substr(6, 2))
                return true;
            else if (t1.substr(6, 2) > t2.substr(6, 2))
                return false;
            else
                return false;
        }
    }
}
bool cmp1(person &p1, person &p2)
{
    return cmp(p1.Sign_in_time, p2.Sign_in_time);
}

bool cmp2(person &p1, person &p2)
{
    return cmp(p1.Sign_out_time, p2.Sign_out_time)^true;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    person p_min, p_max;
    for (int i = 0; i < n; i++)
    {
        cin >> P[i].ID_number >> P[i].Sign_in_time >> P[i].Sign_out_time;
    }

    sort(P, P + n, cmp1);
    cout << P[0].ID_number << " ";
    sort(P, P + n, cmp2);
    cout << P[0].ID_number;


    return 0;
}
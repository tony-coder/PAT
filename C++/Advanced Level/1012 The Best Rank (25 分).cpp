#include <bits/stdc++.h>
using namespace std;
const int maxn = 2000 + 10;
typedef unsigned long long LL;


struct Student
{
    string id;
    int C, M, E, A;

    Student(): id(""), C(0), M(0), E(0), A(0) {}
    Student(string _id, int _C, int _M, int _E) {
        id = _id;
        C = _C;
        M = _M;
        E = _E;
        A = (_C + _M + _E) / 3;
    }

    char findmax() {
        int tmp = max(C, max(M, max(E, A)));
        if (tmp == A)
            return 'A';
        else if (tmp == C)
            return 'C';
        else if (tmp == M)
            return 'M';
        else
            return 'E';
    }

} stu_A[maxn], stu_C[maxn], stu_M[maxn], stu_E[maxn];

std::map<string, Student> Map;

bool cmp1(Student & s1, Student & s2)
{
    return s1.A > s2.A;
}

bool cmp2(Student & s1, Student & s2)
{
    return s1.C > s2.C;
}

bool cmp3(Student & s1, Student & s2)
{
    return s1.M > s2.M;
}

bool cmp4(Student & s1, Student & s2)
{
    return s1.E > s2.E;
}

void init(int n)
{
    sort(stu_A, stu_A + n, cmp1);
    sort(stu_C, stu_C + n, cmp2);
    sort(stu_M, stu_M + n, cmp3);
    sort(stu_E, stu_E + n, cmp4);
}

int main(int argc, char const *argv[])
{
    int N, M;
    cin >> N >> M;
    string id;
    for (int i = 0; i < N; ++i)
    {
        int C, M, E;
        cin >> id >> C >> M >> E;
        stu_A[i] = Student(id, C, M, E);
        stu_C[i] = Student(id, C, M, E);
        stu_M[i] = Student(id, C, M, E);
        stu_E[i] = Student(id, C, M, E);

        Map.insert(make_pair(id, stu_A[i]));
    }
    init(N);

    // for (int i = 0; i < N; ++i)
    // {
    //     cout << stu_C[i].id << " ";
    // }
    // cout << endl;

    for (int i = 0; i < M; ++i)
    {
        cin >> id;

        if (Map.count(id) == 0)
            printf("N/A\n");
        else
        {
            int a, c, m, e;
            a = c = m = e = 0;
            int count = 0;
            for (int i = 0; i < N; ++i)
            {
                if (stu_A[i].id == id)
                    break;

                if (stu_A[i].A == stu_A[i + 1].A && i < N - 1)
                {
                    count++;
                    continue;
                }
                else if (count > 0)
                {
                    a += count + 1;
                    count = 0;
                }
                else
                    a++;

            }
            count = 0;
            for (int i = 0; i < N; ++i)
            {
                if (stu_C[i].id == id)
                    break;

                if (stu_C[i].C == stu_C[i + 1].C && i < N - 1)
                {
                    count++;
                    continue;
                }
                else if (count > 0)
                {
                    c += count + 1;
                    count = 0;
                }
                else
                    c++;

            }
            count = 0;
            for (int i = 0; i < N; ++i)
            {
                if (stu_M[i].id == id)
                    break;

                if (stu_M[i].M == stu_M[i + 1].M && i < N - 1)
                {
                    count++;
                    continue;
                }
                else if (count > 0)
                {
                    m += count + 1;
                    count = 0;

                }
                else
                    m++;
            }
            count = 0;
            for (int i = 0; i < N; ++i)
            {
                if (stu_E[i].id == id)
                    break;

                if (stu_E[i].E == stu_E[i + 1].E && i < N - 1)
                {
                    count++;
                    continue;
                }
                else if (count > 0)
                {

                    e += count + 1;
                    count = 0;
                }
                else
                    e++;
            }

            int t = min(a, min(c, min(m, e)));
            if (t == a)
                printf("%d A\n", a + 1 );
            else if (t == c)
                printf("%d C\n", c + 1 );
            else if (t == m)
                printf("%d M\n", m + 1);
            else
                printf("%d E\n", e + 1);
            // cout << t << endl;
        }
    }

    return 0;
}

// 5 6
// 310101 1 1 1
// 310102 98 98 98
// 310103 98 98 98
// 310104 98 98 98
// 310105 98 98 98
// 310101
// 310102
// 310103
// 310104
// 310105
// 999999
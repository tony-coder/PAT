#include <bits/stdc++.h>
using namespace std;
const int maxn = 20010;
//ip表示第几条边
//indeg表示入度
int head[maxn], ip, indeg[maxn];
int n, m, seq[maxn];//seg表示要干的事

vector<int> ans; //储存答案

struct note
{
    int v, next;
} edge[maxn];

void init()
{
    memset(head, -1, sizeof(head));
    memset(indeg, 0, sizeof(indeg));
    ip = 0;
}

void addedge(int u, int v)//增加边，u是初始点，v是终点
{
    edge[ip].v = v;  //ip相当于加入边的编号
    edge[ip].next = head[u];
    head[u] = ip++;
    indeg[v]++;
}

int toposort()//拓扑排序
{
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 0)
            q.push(i);
    }

    int k = 0;  //记数，记录当期已经输出的顶点数
    bool res = false;
    while (!q.empty())
    {
        if (q.size() != 1)
            res = true;  //不止一种拓扑序

        int u = q.front();
        q.pop();

        ans.push_back(u);

        k++;
        for (int i = head[u]; i != -1; i = edge[i].next)
        {
            int v = edge[i].v;
            if (--indeg[v] == 0)
            {
                //seq[v] = seq[u]+1;
                q.push(v);  //若入度为0，则入队
            }
        }
    }
    if (k < n)
        return -1; //没有输出全部顶点，有向图中有环
    if (res)
        return 0; //不止一种拓扑序
    return 1; //正常,唯一拓扑序
}

int main(int argc, char const *argv[])
{
    init();

    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        int a, b;
        cin >> a >> b;
        addedge(a, b);
    }
    cout << toposort() << endl;
    for (int i = 0; i < n; ++i)
        cout << ans[i] << " ";
    cout << endl;

    return 0;
}

/*
4 5
2 1
1 3
2 3
4 2
4 3

out:
4 2 1 3
*/
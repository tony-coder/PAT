#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3;

int v;
list<int> adj[maxn];  // 邻接表
queue<int>q;
int indegree[maxn];

void addEdge(int u, int v) {
	adj[u].push_back(v);
	indegree[v]++;
}

bool toposort() {
	// 将所有入度为0的结点加入队列
	for (int i = 0; i < v; ++i) {
		if (indegree[i] == 0)
			q.push(i);
	}
	int count = 0; // 记录当前已经输出的顶点数
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		printf("%d ", v);
		count++;
		// 将所有v指向的顶点的入度减1，并将入度为0的顶点入队
		auto itr = adj[v].begin();
		for (; itr != adj[v].end(); itr++) {
			if ((--indegree[*itr]) == 0)
				q.push(*itr);	// 若入度为0，则入队
		}
	}
	if (count < v)
		return false;
	else
		return true;
}

int main(int argc, char const *argv[])
{
	// cin >> v;
	v = 7;
	addEdge(0, 1);
	addEdge(0, 3);
	addEdge(0, 2);
	addEdge(1, 3);
	addEdge(1, 4);
	addEdge(4, 3);
	addEdge(4, 6);
	addEdge(6, 5);
	addEdge(2, 5);
	addEdge(3, 2);
	addEdge(3, 5);
	addEdge(3, 6);

	toposort();
	printf("\n");

	return 0;
}
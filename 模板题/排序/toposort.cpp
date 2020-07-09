#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class Graph {
public:
	Graph(int v = 0);
	~Graph();
	void addEdge(int v, int w);
	bool toposort();
private:
	int v;	//顶点个数
	list<int> *adj;	//邻接表
	//vector<list<int> > adj;
	queue<int> q;	//维护一个入度为0的顶点的集合
	int *indegree;	//记录每个顶点的入度
	//vector<int> indegree;
};

Graph::Graph(int v) {
	this->v = v;
	adj = new list<int>[v];

	indegree = new int[v];
	for (int i = 0; i < v; ++i)
		indegree[i] = 0;
}

Graph::~Graph() {
	delete[] adj;
	delete[] indegree;
}

void Graph::addEdge(int v, int w) {
	adj[v].push_back(w);
	++indegree[w];
}

bool Graph::toposort() {
	// 将所有入度为0的结点加入队列
	for (int i = 0; i < v; ++i) {
		if (indegree[i] == 0)
			q.push(i);
	}

	int count = 0;	//记数，记录当期已经输出的顶点数
	while (!q.empty()) {
		int v = q.front();
		q.pop();

		cout << v << " ";
		++count;
		//将所有v指向的顶点的入度减1，并将入度为0的顶点入队
		list<int>::iterator beg = adj[v].begin();
		for (; beg != adj[v].end(); ++beg)
			if ((--indegree[*beg]) == 0)
				q.push(*beg);	//若入度为0，则入队
	}
	if (count < v)
		return false;	//没有输出全部顶点，有向图中有环
	else
		return true;
}

int main(int argc, char const *argv[])
{
	/*Graph g(7);
	g.addEdge(1, 2);
	g.addEdge(1, 4);
	g.addEdge(1, 3);
	g.addEdge(2, 4);
	g.addEdge(2, 5);
	g.addEdge(5, 4);
	g.addEdge(5, 7);
	g.addEdge(7, 6);
	g.addEdge(3, 6);
	g.addEdge(4, 3);
	g.addEdge(4, 6);
	g.addEdge(4, 7);*/

	/*标记从0开始*/
	Graph g(7);
	g.addEdge(0, 1);
	g.addEdge(0, 3);
	g.addEdge(0, 2);
	g.addEdge(1, 3);
	g.addEdge(1, 4);
	g.addEdge(4, 3);
	g.addEdge(4, 6);
	g.addEdge(6, 5);
	g.addEdge(2, 5);
	g.addEdge(3, 2);
	g.addEdge(3, 5);
	g.addEdge(3, 6);

	g.toposort();
	cout << endl;

	return 0;
}
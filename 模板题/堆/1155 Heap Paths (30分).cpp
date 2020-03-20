#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 10;
int a[maxn], N;
vector<int> v;

void dfs(int root) {
	if (2 * root > N && 2 * root + 1 > N) {
		if (root > N)
			return;
		int i;
		for (i = 0; i < v.size() - 1; ++i)
			cout << v[i] << " ";
		cout << v[i] << endl;
	} else {
		v.push_back(a[root * 2 + 1]);
		dfs(root * 2 + 1);
		v.pop_back();
		v.push_back(a[root * 2]);
		dfs(root * 2);
		v.pop_back();
	}
}

int main(int argc, char const *argv[])
{
	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> a[i];
	v.push_back(a[1]);
	dfs(1);
	bool isMax = false, isMin = false;
	for (int i = 2; i <= N; ++i) {
		if (a[i / 2] > a[i])
			isMax = true;
		if (a[i / 2] < a[i])
			isMin = true;
	}
	if (!(isMin ^ isMax))
		cout << "Not Heap" << endl;
	else if (isMax)
		cout << "Max Heap" << endl;
	else if (isMin)
		cout << "Min Heap" << endl;

	return 0;
}
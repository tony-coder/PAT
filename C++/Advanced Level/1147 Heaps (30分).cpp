#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 10;
int a[maxn], M, N;
vector<int> post;

bool judge_maxheap(int N) {
	for (int i = 1; i <= (N % 2 == 0 ? N / 2 : (N - 1) / 2); ++i) {
		if (2 * i <= N && a[2 * i] > a[i])
			return false;
		if (2 * i + 1 <= N && a[2 * i + 1] > a[i])
			return false;
	}
	return true;
}

bool judge_minheap(int N) {
	for (int i = 1; i <= (N % 2 == 0 ? N / 2 : (N - 1) / 2); ++i) {
		if (2 * i <= N && a[2 * i] < a[i])
			return false;
		if (2 * i + 1 <= N && a[2 * i + 1] < a[i])
			return false;
	}
	return true;
}

void postorder(int root) {
	if (root > N)
		return;
	postorder(2 * root);
	postorder(2 * root + 1);
	post.push_back(a[root]);
}

int main(int argc, char const *argv[])
{
	cin >> M >> N;
	while (M--) {
		int i;
		for (i = 1; i <= N; ++i)
			cin >> a[i];
		if (judge_maxheap(N))
			cout << "Max Heap" << endl;
		else if (judge_minheap(N))
			cout << "Min Heap" << endl;
		else
			cout << "Not Heap" << endl;
		post.clear();
		postorder(1);
		for (i = 0; i < post.size() - 1; i++)
			cout << post[i] << " ";
		cout << post[i] << endl;
	}

	return 0;
}
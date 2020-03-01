#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;

int Left[maxn], Right[maxn];
bool vis[maxn];
vector<int> inorder, levelorder;

void in_order(int root) {
	if (root == -1)
		return;
	in_order(Right[root]);
	inorder.push_back(root);
	in_order(Left[root]);
}

void level_order(int root) {
	queue<int> q;
	q.push(root);

	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		levelorder.push_back(tmp);

		if (Right[tmp] != -1)
			q.push(Right[tmp]);
		if (Left[tmp] != -1)
			q.push(Left[tmp]);
	}
}

int main(int argc, char const *argv[])
{
	int N, root;
	cin >> N;
	memset(vis, false, sizeof(vis));
	for (int i = 0; i < N; ++i) {
		char l, r;
		cin >> l >> r;
		if (l != '-') {
			Left[i] = l - '0';
			vis[l - '0'] = true;
		}
		else
			Left[i] = -1;
		if (r != '-') {
			Right[i] = r - '0';
			vis[r - '0'] = true;
		}
		else
			Right[i] = -1;
	}
	for (int i = 0; i < N; ++i) {
		if (!vis[i]) {
			root = i;
			break;
		}
	}
	level_order(root);
	in_order(root);
	int i;
	for (i = 0; i < levelorder.size() - 1; ++i)
		cout << levelorder[i] << " ";
	cout << levelorder[i] << endl;

	for (i = 0; i < inorder.size() - 1; ++i)
		cout << inorder[i] << " ";
	cout << inorder[i] << endl;

	return 0;
}
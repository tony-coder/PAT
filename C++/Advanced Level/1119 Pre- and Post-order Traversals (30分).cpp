#include <bits/stdc++.h>
using namespace std;
const int maxn = 30 + 10;

int pre[maxn], post[maxn];
vector<int> in;
bool flag;
void in_order(int preLeft, int preRight, int postLeft, int postRight) {
	if (preLeft == preRight) {
		in.push_back(pre[preLeft]);
		return;
	}
	if (pre[preLeft] == post[postRight]) {
		int i = preLeft + 1;
		while (i <= preRight && pre[i] != post[postRight - 1])
			i++;
		if (i - preLeft > 1) //父节点有两个子节点，结构唯一
			in_order(preLeft + 1, i - 1, postLeft, postLeft + (i - preLeft - 1) - 1); //左子树
		else if (i - preLeft == 1) //父节点有一个子节点，则可左可右，结构不唯一
			flag = false;
		in.push_back(pre[preLeft]);  //根节点
		in_order(i, preRight, postLeft + (i - preLeft - 1), postRight - 1);  //右子树
	}
}

int main(int argc, char const *argv[])
{
	int N, i;
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> pre[i];
	for (int i = 0; i < N; ++i)
		cin >> post[i];
	flag = true;
	in_order(0, N - 1, 0, N - 1);
	if (flag)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	for (i = 0; i < N - 1; ++i)
		cout << in[i] << " ";
	cout << in[i] << endl;

	return 0;
}
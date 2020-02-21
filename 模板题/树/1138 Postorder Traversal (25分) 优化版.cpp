#include <bits/stdc++.h>
using namespace std;
const int maxn = 50000 + 10;

int pre[maxn], in[maxn];
bool flag = false;

void postOrder(int preLeft, int inLeft, int inRight) {
	if (inLeft > inRight || flag == true)
		return;
	int i = inLeft;
	while (in[i] != pre[preLeft])
		i++;
	postOrder(preLeft + 1, inLeft, i - 1);
	postOrder(preLeft + i - inLeft + 1, i + 1, inRight);
	if (flag == false) {
		printf("%d\n", in[i]);
		flag = true;
	}
}

int main(int argc, char const *argv[])
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
		cin >> pre[i];
	for (int i = 0; i < N; ++i)
		cin >> in[i];
	postOrder(0, 0, N - 1);

	return 0;
}
#include <bits/stdc++.h>
using namespace std;

inline int leftchild(int i) {
	return 2 * i + 1;
}

void percDown(vector<int>& a, int i, int n) {
	int child, tmp;
	for (tmp = a[i]; leftchild(i) < n; i = child) {
		child = leftchild(i);
		if (child + 1 < n && a[child] < a[child + 1])
			child++;
		if (tmp < a[child])
			a[i] = a[child];
		else
			break;
	}
	a[i] = tmp;
}

int main(int argc, char const *argv[])
{
	int N;
	scanf("%d", &N);
	vector<int> a(N), b(N);
	for (int i = 0; i < N; ++i)
		scanf("%d", &a[i]);
	for (int i = 0; i < N; ++i)
		scanf("%d", &b[i]);
	int i, j;
	for (i = 0; i < N - 1; ++i) {
		if (b[i] > b[i + 1])
			break;
	}
	for (j = i + 1; j < N; ++j) {
		if (a[j] != b[j])
			break;
	}
	if (j == N) {
		printf("Insertion Sort\n");
		sort(b.begin(), b.begin() + i + 2);
	} else {
		printf("Heap Sort\n");
		for (i = N - 1; i > 0; --i) {
			if (b[i] < b[i - 1])
				break;
		}
		swap(b[0], b[i]);
		percDown(b, 0, i);
	}
	for (i = 0; i < b.size() - 1; ++i)
		printf("%d ", b[i]);
	printf("%d\n", b[i]);

	return 0;
}
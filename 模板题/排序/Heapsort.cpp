#include <iostream>
#include <vector>
#include <algorithm>
#define LeftChild(i)(2*(i)+1)
using namespace std;

//下滤
void PercDown(int A[], int i, int N)
{
	int Child;
	int Tmp;

	for (Tmp = A[i]; LeftChild(i) < N; i = Child)
	{
		Child = LeftChild(i);
		if (Child != N - 1 && A[Child + 1] > A[Child])
			Child++;
		if (Tmp < A[Child])
			A[i] = A[Child];
		else
			break;
	}
	A[i] = Tmp;
}

void Heapsort(int A[], int N)
{
	int i;
	for (i = N / 2; i >= 0; i--)
		PercDown(A, i, N);
	for (int i = N - 1; i > 0; --i)
	{
		swap(A[0], A[i]);
		PercDown(A, 0, i);
	}
}

inline int leftchild(int i)
{
	return 2 * i + 1;
}

template<typename Comparable>
void percDown(vector<Comparable>& a, int i, int n)
{
	int child;
	Comparable tmp;

	for (tmp = std::move(a[i]); leftchild(i) < n; i = child)
	{
		child = leftchild(i);
		if (child + 1 < n && a[child] < a[child + 1])
			child++;
		if (tmp < a[child])
			a[i] = std::move(a[child]);
		else
			break;
	}
	a[i] = std::move(tmp);
}

template<typename Comparable>
void heapsort(vector<Comparable>& a)
{
	for (int i = a.size() / 2 - 1; i >= 0; i--)
		percDown(a, i, a.size());
	for (int j = a.size() - 1; j >= 0; --j)
	{
		swap(a[0], a[j]);
		percDown(a, 0, j);
	}
}

int main(int argc, char const *argv[])
{
	int a[10] = {3, 6, 8, 2, 5, 1, 0, 4, 7, 9};
	vector<int> t(a, a + 10);

	Heapsort(a, 10);

	for (int i = 0; i < 10; ++i)
		cout << a[i] << " ";
	cout << endl;

	heapsort(t);
	for (size_t i = 0; i < t.size(); ++i)
		cout << t[i] << " ";
	cout << endl;

	return 0;
}
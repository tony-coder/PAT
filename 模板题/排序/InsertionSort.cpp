#include <iostream>
#include <vector>
using namespace std;
//通过std::move，可以避免不必要的拷贝操作。
template<typename Comparable>
void insertionSort(vector<Comparable> &a)
{
	for (size_t p = 1; p < a.size(); ++p) {
		int j;
		Comparable tmp = std::move(a[p]);
		for (j = p; j > 0 && a[j - 1] > tmp; --j)
			a[j] = std::move(a[j - 1]);
		a[j] = std::move(tmp);
	}
}

int main(int argc, char const *argv[])
{
	std::vector<int> t;

	for (int i = 10; i >= 0; --i)
		t.push_back(i);

	insertionSort<int>(t);

	for (int i = 0; i <= 10; ++i)
		cout << t[i] << " ";
	cout << endl;

	return 0;
}
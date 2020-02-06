#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 + 10;

vector<int> v;
vector<int> original;
bool issame(vector<int> a, vector<int> b) {
	for (int i = 0; i < a.size(); ++i) {
		if (a[i] != b[i])
			return false;
	}
	return true;
}

//针对这道题存在问题
//例
// 3 1 4 5 6 0 9
// 1 3 4 5 6 0 9
// Insertion Sort
// 0 1 3 4 5 6 9
// 这里因为无法判断到底，输出的为1 3 4 5 6 0 9
bool insertSort(vector<int>& a) {
	bool flag = false;
	for (int i = 1; i < a.size(); ++i) {
		if (i != 1 && issame(a, v))  //注意i!=1 否则能构造样例 1 3 2 | 1 3 2 由于第一次就匹配，需要再运行一轮
			flag = true;
		int tmp = a[i], j;
		for (j = i; j > 0 && tmp < a[j - 1]; --j)
			a[j] = a[j - 1];
		a[j] = tmp;
		if (flag)
			break;
	}
	return flag;
}

//同理merge也存在问题
bool mergesort(vector<int>& a) {
	int len = a.size();
	bool flag = false;
	for (int step = 2; step <= len * 2; step *= 2) {
		if (step != 2 && issame(a, v))
			flag = true;
		for (int i = 0; i < len; i += step)
			sort(a.begin() + i, a.begin() + min(i + step, len));
		if (flag)
			break;
	}
	return flag;
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int N, i;
	cin >> N;
	v.resize(N);
	original.resize(N);
	for (int i = 0; i < N; ++i)
		cin >> original[i];
	for (int i = 0; i < N; ++i)
		cin >> v[i];
	vector<int>tmp = original;
	if (insertSort(tmp)) {
		cout << "Insertion Sort\n";
		for (i = 0; i < tmp.size() - 1; ++i)
			cout << tmp[i] << " ";
		cout << tmp[i] << endl;
	} else {
		tmp = original;
		mergesort(tmp);
		cout << "Merge Sort\n";
		for (i = 0; i < tmp.size() - 1; ++i)
			cout << tmp[i] << " ";
		cout << tmp[i] << endl;
	}

	return 0;
}
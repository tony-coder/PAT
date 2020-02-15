#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	vector<int>v(N);
	for (int i = 0; i < N; ++i)
		cin >> v[i];
	sort(v.begin(), v.end(), greater<int>());
	int e = 0;
	while (e < N && v[e] > e + 1)
		e++;
	printf("%d\n", e);

	return 0;
}
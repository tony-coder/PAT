#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6;

struct node {
	int Address, Data, Next;
} List[maxn];

int main(int argc, char const *argv[])
{
	int l1, l2, N;
	scanf("%d%d%d", &l1, &l2, &N);
	for (int i = 0; i < N; ++i) {
		int address, data, next;
		scanf("%d%d%d", &address, &data, &next);
		List[address].Address = address;
		List[address].Data = data;
		List[address].Next = next;
	}
	vector<node>v1, v2, v;
	for (int i = l1; i != -1; i = List[i].Next) {
		v1.push_back(List[i]);
	}
	for (int i = l2; i != -1; i = List[i].Next) {
		v2.push_back(List[i]);
	}
	vector<node>tmp;
	if (v1.size() < v2.size()) {
		tmp = v1;
		v1 = v2;
		v2 = tmp;
	}
	reverse(v2.begin(), v2.end());
	// for (size_t i = 0; i < v1.size(); ++i)
	// {
	// 	cout << v1[i].Data << " ";
	// }
	// cout << endl;
	size_t i = 0, j = 0, k = 2, cnt = 0;
	while (i < v1.size()) {
		if (cnt == k && j < v2.size()) {
			v.push_back(v2[j]);
			j++;
			cnt = 0;
		} else {
			v.push_back(v1[i]);
			i++;
			cnt++;
		}
	}
	while (j < v2.size())
		v.push_back(v2[j++]);

	for (i = 0; i < v.size() - 1; ++i) {
		printf("%05d %d %05d\n", v[i].Address, v[i].Data, v[i + 1].Address );
	}
	printf("%05d %d %d\n", v[i].Address, v[i].Data, -1);

	return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;

int N, L, H;
struct node
{
	int ID_Number, Virtue_Grade, Talent_Grade;
	int role;
} v[maxn];

bool cmp(node& a, node& b) {
	if (a.role == b.role) {
		if ((a.Virtue_Grade + a.Talent_Grade) == (b.Virtue_Grade + b.Talent_Grade)) {
			if (a.Virtue_Grade == b.Virtue_Grade)
				return a.ID_Number < b.ID_Number;
			else
				return a.Virtue_Grade > b.Virtue_Grade;
		}
		return (a.Virtue_Grade + a.Talent_Grade) > (b.Virtue_Grade + b.Talent_Grade);
	} else
		return a.role < b.role;
}

int main(int argc, char const *argv[])
{
	int cnt = 0;
	scanf("%d%d%d", &N, &L, &H);
	for (int i = 0; i < N; ++i) {
		scanf("%d%d%d", &v[i].ID_Number, &v[i].Virtue_Grade, &v[i].Talent_Grade);
		if (v[i].Virtue_Grade < L || v[i].Talent_Grade < L) {
			v[i].role = -1;
			cnt++;
		}
		else if (v[i].Virtue_Grade >= H && v[i].Talent_Grade >= H)
			v[i].role = 1;
		else if (v[i].Virtue_Grade >= H && v[i].Talent_Grade < H)
			v[i].role = 2;
		else if (v[i].Virtue_Grade < H && v[i].Talent_Grade < H && v[i].Virtue_Grade >= v[i].Talent_Grade)
			v[i].role = 3;
		else if (v[i].Virtue_Grade >= L && v[i].Talent_Grade >= L)
			v[i].role = 4;
	}
	sort(v, v + N, cmp);
	printf("%d\n", N - cnt);
	for (int i = 0; i < N; ++i) {
		if (v[i].role == -1)
			continue;
		printf("%08d %d %d\n", v[i].ID_Number, v[i].Virtue_Grade, v[i].Talent_Grade);
	}

	return 0;
}
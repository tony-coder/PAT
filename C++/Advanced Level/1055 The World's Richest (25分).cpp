#include <bits/stdc++.h>
using namespace std;

struct node
{
	string name;
	int age, worth;
};

bool cmp(node& n1, node& n2)
{
	if (n1.worth == n2.worth)
	{
		if (n1.age == n2.age)
			return n1.name < n2.name;
		else
			return n1.age < n2.age;
	}
	else
		return n1.worth > n2.worth;
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int N, K;
	cin >> N >> K;
	string name;
	int age, worth;
	vector<node> v(N);
	for (int i = 0; i < N; ++i) {
		cin >> name >> age >> worth;
		v[i] = {name, age, worth};
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 1; i <= K; ++i) {
		int M, Amax, Amin;
		cin >> M >> Amin >> Amax;
		printf("Case #%d:\n", i );
		int j;
		bool flag = false;
		for ( j = 0; j < N && M > 0; ++j) {
			if (v[j].age >= Amin && v[j].age <= Amax) {
				flag = true;
				printf("%s %d %d\n", v[j].name.c_str(), v[j].age, v[j].worth );
				M--;
			}
		}
		if (!flag)
			printf("None\n");
	}

	return 0;
}
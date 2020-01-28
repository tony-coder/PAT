#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;

struct node
{
	int id;
	string name;
	int grades;
};

node stu[maxn];

bool cmp1(node& n1, node& n2)
{
	return n1.id < n2.id;
}

bool cmp2(node& n1, node& n2)
{
	return n1.name == n2.name ? n1.id < n2.id : n1.name < n2.name;
}

bool cmp3(node& n1, node& n2)
{
	return n1.grades == n2.grades ? n1.id < n2.id : n1.grades < n2.grades;
}

int main(int argc, char const *argv[])
{
	int N, C;
	cin >> N >> C;
	// vector<node> stu(N);
	for (int i = 0; i < N; ++i)
		cin >> stu[i].id >> stu[i].name >> stu[i].grades;
	if (C == 1)
		sort(stu, stu + N, cmp1);
	else if (C == 2)
		sort(stu, stu + N, cmp2);
	else if (C == 3)
		sort(stu, stu + N, cmp3);

	for (int i = 0; i < N; ++i)
	{
		printf("%06d %s %d\n", stu[i].id, stu[i].name.c_str(), stu[i].grades );
		// cout << stu[i].id << " " << stu[i].name << " " << stu[i].grades << endl;
	}

	return 0;
}
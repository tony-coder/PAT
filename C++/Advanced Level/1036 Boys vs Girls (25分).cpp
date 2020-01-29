#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
struct node {
	string name, id;
	int grade;
} male, female;

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	string name, id;
	char gender;
	int grade;
	int max_f = -1, min_m = INF;
	for (int i = 0; i < N; ++i) {
		cin >> name >> gender >> id >> grade;
		if (gender == 'M' && grade < min_m) {
			male = {name, id, grade};
			min_m = grade;
		} else if (gender == 'F' && grade > max_f) {
			female = {name, id, grade};
			max_f = grade;
		}
	}
	if (max_f != -1)
		printf("%s %s\n", female.name.c_str(), female.id.c_str());
	else
		printf("Absent\n");
	if (min_m != INF)
		printf("%s %s\n", male.name.c_str(), male.id.c_str());
	else
		printf("Absent\n");
	if (min_m == INF || max_f == -1)
		printf("NA\n");
	else
		printf("%d\n", female.grade - male.grade);
	return 0;
}
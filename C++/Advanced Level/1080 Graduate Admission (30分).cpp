#include <bits/stdc++.h>
using namespace std;

struct stu {
	int id;
	int GE, GI, tot_score;
	vector<int> preferred_school;
} student[40000 + 10];

struct sch {
	int capacity;
	// 注意：不能直接用vector数组中的最后一个比较，不然会有两个点过不了。。。
	int last_ge, last_tot;  // 记录最后一个学生的成绩
	vector<int> admitted;
} school[100 + 10];

int main(int argc, char const *argv[])
{
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i < M; ++i) {
		scanf("%d", &school[i].capacity);
	}
	for (int i = 0; i < N; ++i) {
		student[i].id = i;
		scanf("%d %d", &student[i].GE, &student[i].GI);
		student[i].tot_score = student[i].GE + student[i].GI;
		for (int j = 0; j < K; ++j) {
			int id;
			scanf("%d", &id);
			student[i].preferred_school.push_back(id);
		}
	}
	sort(student, student + N, [](stu & n1, stu & n2) {return n1.tot_score == n2.tot_score ? n1.GE > n2.GE : n1.tot_score > n2.tot_score;});
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < K; ++j) {
			if (school[student[i].preferred_school[j]].capacity > 0) {
				school[student[i].preferred_school[j]].admitted.push_back(student[i].id);
				school[student[i].preferred_school[j]].capacity--;
				if (school[student[i].preferred_school[j]].capacity == 0) {
					school[student[i].preferred_school[j]].last_tot = student[i].tot_score;
					school[student[i].preferred_school[j]].last_ge = student[i].GE;
				}
				break;
			} else if (school[student[i].preferred_school[j]].capacity == 0) {
				if (student[i].tot_score == school[student[i].preferred_school[j]].last_tot && student[i].GE == school[student[i].preferred_school[j]].last_ge) {
					school[student[i].preferred_school[j]].admitted.push_back(student[i].id);
					break;
				}
			}
		}
	}
	for (int i = 0; i < M; ++i) {
		if (school[i].admitted.size() == 0) {
			printf("\n");
			continue;
		}
		sort(school[i].admitted.begin(), school[i].admitted.end());
		int j = 0;
		for (j = 0; j < school[i].admitted.size() - 1; ++j)
			printf("%d ", school[i].admitted[j]);
		printf("%d\n", school[i].admitted[j]);
	}

	return 0;
}
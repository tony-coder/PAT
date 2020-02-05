#include <bits/stdc++.h>
using namespace std;

int N, K, M;
struct node
{
	int id, tot_score, tot_solve, perfect_solved;
	int s[6];
	node(): id(0), tot_score(0), tot_solve(0), perfect_solved(0) {
		// memset(s, -2, sizeof(s)); 注意不能这样初始化，因为memset按字节对内存块进行初始化,所以他无法对int数组初始化除了0和-1以外的其他数
		fill(s, s + 6, -2); //-2代表未提交 -1代表未通过编译
	}
};

bool cmp(node& a, node& b) {
	if (a.tot_score == b.tot_score) {
		if (a.perfect_solved == b.perfect_solved) {
			return a.id < b.id;
		} else
			return a.perfect_solved > b.perfect_solved;
	}
	else
		return a.tot_score > b.tot_score;
}

int main(int argc, char const *argv[])
{
	scanf("%d%d%d", &N, &K, &M);
	vector<int> full_mark(K + 1);
	map<int, node> mp;
	for (int i = 1; i <= K; ++i)
		scanf("%d", &full_mark[i]);
	for (int i = 0; i < M; ++i) {
		int user_id, problem_id, partial_score;
		scanf("%d%d%d", &user_id, &problem_id, &partial_score);
		if (mp.count(user_id)) {
			if (partial_score > mp[user_id].s[problem_id])
				mp[user_id].s[problem_id] = partial_score;
		} else {
			mp[user_id].id = user_id;
			mp[user_id].s[problem_id] = partial_score;
		}
	}
	vector<node> ans;
	for (auto t : mp) {
		// printf("%05d\n", t.first);
		for (int i = 1; i <= K; ++i) {
			if (t.second.s[i] >= 0) {
				t.second.tot_solve++;
				t.second.tot_score += t.second.s[i];
			}
			if (t.second.s[i] == full_mark[i])
				t.second.perfect_solved++;
		}
		if (t.second.tot_solve > 0)
			ans.push_back(t.second);
	}
	sort(ans.begin(), ans.end(), cmp);
	int rank = 1;
	printf("%d %05d %d", rank, ans[0].id, ans[0].tot_score);
	for (int j = 1; j <= K; ++j) {
		if (ans[0].s[j] == -2)
			printf(" -");
		else if (ans[0].s[j] == -1)
			printf(" 0");
		else
			printf(" %d", ans[0].s[j] );
	}
	printf("\n");
	for (int i = 1; i < ans.size(); ++i) {
		if (ans[i].tot_score != ans[i - 1].tot_score)
			rank = i + 1;
		printf("%d %05d %d", rank, ans[i].id, ans[i].tot_score);
		for (int j = 1; j <= K; ++j) {
			if (ans[i].s[j] == -2)
				printf(" -");
			else if (ans[i].s[j] == -1)
				printf(" 0");
			else
				printf(" %d", ans[i].s[j] );
		}
		printf("\n");
	}

	return 0;
}
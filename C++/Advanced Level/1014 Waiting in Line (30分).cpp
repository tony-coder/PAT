#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 10;

struct node {
	int id, transaction_time, start_time, end_time;
} customers[maxn];

int main(int argc, char const *argv[])
{
	int N, M, K, Q;
	scanf("%d %d %d %d", &N, &M, &K, &Q);
	for (int i = 1; i <= K; ++i) {
		customers[i].id = i;
		int time;
		scanf("%d", &time);
		customers[i].transaction_time = time * 60;
	}
	vector<queue<int> >windows(N);
	int current = 60 * 60 * 8;  // 当前时间
	// 初始化队列
	int i, id;
	for (i = 1; i <= K && i <= N * M; ++i)
		windows[(i - 1) % N].push(customers[i].id);
	// printf("%d\n", i);
	for (int j = 0; j < N; ++j) {
		id = windows[j].front();
		customers[id].start_time = current;
		customers[id].end_time = current + customers[id].transaction_time;
	}
	bool flag;
	do {
		// printf("%d\n", current);
		flag = true;
		vector<int> deal;
		int Min = 0x3f3f3f3f;
		for (int j = 0; j < N; ++j) {
			if (!windows[j].empty()) {
				flag = false;
				id = windows[j].front();
				// printf("%d\n",id);
				if (customers[id].end_time - current < Min) {
					deal.clear();
					deal.push_back(j);
					Min = customers[id].end_time - current;
				} else if (customers[id].end_time - current == Min)
					deal.push_back(j);
			}
		}
		for (int j = 0; j < deal.size(); ++j) {
			id = windows[deal[j]].front();
			// printf("%d %d\n", id, customers[id].end_time);

			current = customers[id].end_time;
			windows[deal[j]].pop();
			// 更新下一用户信息
			if (!windows[deal[j]].empty()) {
				id = windows[deal[j]].front();
				customers[id].start_time = current;
				customers[id].end_time = current + customers[id].transaction_time;
			}
			if (i <= K) {
				customers[i].start_time = current;
				customers[i].end_time = current + customers[i].transaction_time;
				windows[deal[j]].push(customers[i++].id);
			}
		}
	} while (!flag);
	for (int i = 0; i < Q; ++i) {
		scanf("%d", &id);
		int hh, mm, time;
		time = customers[id].end_time;
		if (customers[id].start_time >= 3600 * 17)
			printf("Sorry\n");
		else {
			hh = time / 3600;
			mm = (time - hh * 3600) / 60;
			printf("%02d:%02d\n", hh, mm );
		}
	}

	return 0;
}
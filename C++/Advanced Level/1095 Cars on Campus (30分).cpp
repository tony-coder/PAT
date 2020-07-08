#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;
struct car {
	string plate_number;
	int time;
	bool status;
} record[maxn];

int main(int argc, char const *argv[])
{
	int N, K, hh, mm, ss, time;
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; ++i) {
		char plate_number[10], status[5];
		scanf("%s %d:%d:%d %s", plate_number,  &hh, &mm, &ss, status);
		record[i].plate_number = plate_number;
		record[i].time = hh * 60 * 60 + mm * 60 + ss;
		record[i].status = strcmp(status, "in") == 0 ? true : false;
	}
	// 选出符合要求的记录
	sort(record, record + N, [](struct car c1, struct car c2) {return c1.plate_number == c2.plate_number ? c1.time < c2.time : c1.plate_number < c2.plate_number;});
	int Max_time = 0, pos = 0;
	map<string, int> park_time;
	for (int i = 1; i < N; ++i) {
		if (record[i].plate_number == record[i - 1].plate_number) {
			if (record[i - 1].status && !record[i].status) {
				park_time[record[i].plate_number] += (record[i].time - record[i - 1].time);
				Max_time = max(park_time[record[i].plate_number], Max_time);
				record[pos++] = record[i - 1];
				record[pos++] = record[i];
			}
		}
	}
	sort(record, record + pos, [](struct car c1, struct car c2) {return c1.time < c2.time;});
	int cnt = 0, j = 0;
	map<string, int> mp;
	for (int i = 0; i < K; ++i) {
		scanf("%d:%d:%d", &hh, &mm, &ss);
		time = hh * 60 * 60 + mm * 60 + ss;
		for (j ; j < pos && record[j].time <= time; ++j) {
			if (record[j].status)
				cnt++;
			else
				cnt--;
		}
		printf("%d\n", cnt);
	}
	for (auto t : park_time)
		if (t.second == Max_time)
			printf("%s ", t.first.c_str() );
	hh = Max_time / 3600;
	mm = (Max_time - hh * 3600) / 60;
	ss = Max_time - hh * 3600 - mm * 60;
	printf("%02d:%02d:%02d\n", hh, mm, ss );
	return 0;
}
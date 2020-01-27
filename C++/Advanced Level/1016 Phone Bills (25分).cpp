#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
int toll[25] = {0};
struct node
{
	string name;
	int mon, day, hou, min, time, state;
};

bool cmp(node &a, node &b)
{
	return a.name != b.name ? a.name < b.name : a.time < b.time;
}
//每个通话记录的相对开销
//求当前日期与每月1号的相对差值，然后两个日期的相对差值相减就是绝对差值
double relative_cost(node &call)
{
	double total = toll[call.hou] * call.min + call.day * 60 * toll[24];
	for (int i = 0; i < call.hou; ++i)
		total += toll[i] * 60;
	return total / 100.; //
}

int main(int argc, char const *argv[])
{
	for (int i = 0; i < 24; ++i)
	{
		scanf("%d", &toll[i]);
		toll[24] += toll[i];
	}
	int n;
	scanf("%d", &n);
	vector<node>record(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> record[i].name;
		scanf("%d:%d:%d:%d", &record[i].mon, &record[i].day, &record[i].hou, &record[i].min);
		string temp;
		cin >> temp;
		record[i].state = temp == "on-line" ? 1 : 0;
		//把时间转换成分钟制
		record[i].time = record[i].day * 24 * 60 + record[i].hou * 60 + record[i].min;
	}
	sort(record.begin(), record.end(), cmp);

	map<string, vector<node> >mp; //存名字与记录向量的对照关系
	for (int i = 1; i < n; ++i)
	{
		if (record[i].name == record[i - 1].name && record[i - 1].state == 1 && record[i].state == 0)
		{
			mp[record[i - 1].name].push_back(record[i - 1]);
			mp[record[i].name].push_back(record[i]);
		}
	}
	map<string, vector<node> >::iterator iter;
	for (iter = mp.begin(); iter != mp.end(); iter++)
	{
		vector<node>tmp = iter->second;
		cout << iter->first;
		printf(" %02d\n", tmp[0].mon);
		double total = 0;
		for (int i = 0; i < tmp.size(); i += 2)
		{
			double t = relative_cost(tmp[i + 1]) - relative_cost(tmp[i]);
			printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", tmp[i].day, tmp[i].hou, tmp[i].min, tmp[i + 1].day, tmp[i + 1].hou, tmp[i + 1].min, tmp[i + 1].time - tmp[i].time, t );
			total += t;
		}
		printf("Total amount: $%.2f\n", total);
	}

	return 0;
}
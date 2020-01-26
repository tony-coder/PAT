#include <bits/stdc++.h>
using namespace std;

typedef struct user
{
	string name;
	string date_on;
	string date_off;

	user(): name(""), date_on(""), date_off("") {}
} user;

struct data
{
	string name;
	string date;
	string status;
	data(string _name, string _date, string _status)
	{
		name = _name;
		date = _date;
		status = _status;
	}
};

int price[30];
int pre[30];
map<string, vector<user> > vis;
vector<data> record;

bool cmp(data &a, data &b)
{
	return a.name < b.name || (a.name == b.name && a.date < b.date);
}

int change(string s)
{
	int ans = 0, k = 1;
	for (int i = s.size() - 1; i >= 0; --i, k *= 10)
		ans += (s[i] - '0') * k;
	return ans;
}

double get_cost(user &u)
{
	int day_on, hour_on, min_on, day_off, hour_off, min_off;
	day_on = change(u.date_on.substr(3, 2));
	hour_on = change(u.date_on.substr(6, 2));
	min_on = change(u.date_on.substr(9, 2));

	day_off = change(u.date_off.substr(3, 2));
	hour_off = change(u.date_off.substr(6, 2));
	min_off = change(u.date_off.substr(9, 2));

	double cost = 0;
	if (day_on == day_off)
	{
		if (hour_on == hour_off)
			cost = price[hour_on + 1] * (min_off - min_on + 1) / 100.;
		else
			cost = (price[hour_on + 1] * (60 - min_on) + price[hour_off + 1] * min_off + 60.*(pre[hour_off] - pre[hour_on + 1]) * (hour_off - hour_on - 1)) / 100.;
	}
	else
	{
		cost = price[hour_on + 1] * (60 - min_on) + price[hour_off + 1] * min_off;
		cost += ((pre[24] - pre[hour_on + 1]) + (pre[hour_off] - pre[0])) * 60.;
		cost += ((day_off - day_on - 1) * (pre[24] - pre[0])) * 60;
		cost /= 100.;
	}
	return cost;
}

int get_time(user &u)
{
	int day_on, hour_on, min_on, day_off, hour_off, min_off;
	day_on = change(u.date_on.substr(3, 2));
	hour_on = change(u.date_on.substr(6, 2));
	min_on = change(u.date_on.substr(9, 2));

	day_off = change(u.date_off.substr(3, 2));
	hour_off = change(u.date_off.substr(6, 2));
	min_off = change(u.date_off.substr(9, 2));

	double cost = 0;
	if (day_on == day_off)
	{
		if (hour_on == hour_off)
			cost = (min_off - min_on + 1);
		else
			cost =  (60 - min_on) +  min_off + 60.*(hour_off - hour_on - 1);
	}
	else
	{
		cost = (60 - min_on) + min_off;
		cost += ((24 - hour_on - 1) + (hour_off)) * 60.;
		cost += (day_off - day_on - 1) * 60 * 24;
	}
	return cost;
}

int main(int argc, char const *argv[])
{
	memset(pre, 0, sizeof(pre));
	for (int i = 1; i <= 24; ++i)
	{
		cin >> price[i];
		pre[i] = pre[i - 1] + price[i];
	}

	int N;
	cin >> N;
	string name, date, status;
	for (int i = 0; i < N; ++i)
	{
		cin >> name >> date >> status;
		record.push_back(data(name, date, status));
	}
	sort(record.begin(), record.end(), cmp);

	user tmp;
	for (int i = 0; i < record.size(); ++i)
	{
		if (tmp.name == record[i].name)
		{
			if (record[i].status == "on-line" && tmp.date_off == "")
			{
				tmp.date_on = record[i].date;
			}
			else if (record[i].status == "on-line" && tmp.date_off != "")
			{
				tmp.date_on = record[i].date;
				tmp.date_off = "";
			}
			else if (record[i].status == "off-line" && tmp.date_on != "")
			{
				tmp.date_off = record[i].date;
				vis[tmp.name].push_back(tmp);
				tmp.name = "";
				tmp.date_on = "";
				tmp.date_off = "";
			}
			else if (record[i].status == "off-line" && tmp.date_on == "")
			{
				tmp.date_off = record[i].date;
			}
		}
		else
		{
			tmp.name = record[i].name;
			if (record[i].status == "on-line")
				tmp.date_on = record[i].date;
			else
				tmp.date_off = record[i].date;
			continue;
		}

	}
	map<string, vector<user> >::iterator iter = vis.begin();
	for (; iter != vis.end(); iter++)
	{
		cout << iter->first << " " << (iter->second)[0].date_on.substr(0, 2) << endl;
		double tot = 0.;
		for (int i = 0; i < (iter->second).size(); ++i)
		{
			// cout <<  (iter->second)[i].date_on << " " <<  (iter->second)[i].date_off << endl;
			double cost = get_cost((iter->second)[i]);
			printf("%s %s %d $%.2f\n", (iter->second)[i].date_on.substr(3, 8).c_str(), (iter->second)[i].date_off.substr(3, 8).c_str(), get_time((iter->second)[i]), cost);
			tot += cost;
		}
		printf("Total amount: $%.2f\n", tot );
	}

	return 0;
}

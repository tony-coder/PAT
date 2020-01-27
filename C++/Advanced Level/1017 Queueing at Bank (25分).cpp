#include <bits/stdc++.h>
using namespace std;
const int MAXN = 0x3f3f3f3f;

struct node
{
	// int hou,min,sec;
	int arrive, process, wait;
	node(): arrive(0), process(0), wait(0) {}
	node(int _arrive, int _process, int _wait): arrive(_arrive), process(_process), wait(_wait) {}
};

bool cmp(node &n1, node &n2)
{
	return n1.arrive < n2.arrive;
}

int main(int argc, char const *argv[])
{
	int N, K;
	cin >> N >> K;
	vector<node> cust;
	vector<int> line(K, 8 * 3600);
	for (int i = 0; i < N; ++i)
	{
		int hou, min, sec, process = 0, arrive = 0, wait = 0;
		scanf("%d:%d:%d %d", &hou, &min, &sec, &process);
		if (process > 60)
			process = 60;
		process *= 60;
		arrive = hou * 3600 + min * 60 + sec;

		if (arrive <= 17 * 3600)
			cust.push_back(node(arrive, process, wait));
	}
	sort(cust.begin(), cust.end(), cmp);
	double tot = 0., avg;
	int left = 0, right = 0;
	for (; right < cust.size(); ++right)
	{
		int min = MAXN, index = 0;
		for (int i = 0; i < K; ++i)
		{
			if (line[i] < min)
			{
				min = line[i];
				index = i;
			}
		}
		if (min < cust[right].arrive)
			line[index] = cust[right].arrive + cust[right].process;
		else
		{
			cust[right].wait += ( min - cust[right].arrive);
			cust[right].arrive = min;
			line[index] = cust[right].arrive + cust[right].process;
		}

	}
	for (int i = 0; i < right; ++i)
		tot += cust[i].wait;

	if (cust.size() == 0)
		avg = 0.;
	else
		avg = tot / right;
	avg /= 60.;
	printf("%.1f\n", avg);

	return 0;
}
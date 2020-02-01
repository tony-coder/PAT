//有一个测试点超时
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;

struct node
{
	int Address;
	int Key, Next, Prev;
} List[maxn];

int N, head;

void Swap(node& n1, node& n2) {
	node tmp = {n2.Address, n2.Key, n2.Next, n2.Prev};
	if (n1.Next == n2.Address) //相邻
	{
		List[n2.Address].Next = n1.Address;
		List[n2.Address].Prev = n1.Prev;
		if (n1.Prev == 0)
			head = n2.Address;
		else
			List[n1.Prev].Next = n2.Address;
		List[n1.Prev].Next = n2.Address;

		List[n1.Address].Next = tmp.Next;
		List[n1.Address].Prev = n2.Address;

		if (tmp.Prev == 0)
			head = n1.Address;
	}
	else
	{
		List[n2.Address].Next = n1.Next;
		List[n2.Address].Prev = n1.Prev;

		if (n1.Prev == 0)
			head = n2.Address;
		else
			List[n1.Prev].Next = n2.Address;

		List[n1.Prev].Next = n2.Address;

		List[n1.Address].Next = tmp.Next;
		List[n1.Address].Prev = tmp.Prev;

		if (tmp.Prev == 0)
			head = n1.Address;
		else
			List[tmp.Prev].Next = n1.Address;
	}

	List[List[n2.Address].Next].Prev = n2.Address;
	List[List[n1.Address].Next].Prev = n1.Address;
}

int sort() {
	int cnt = 0;
	for (int i = head; i != -1; i = List[i].Next) {
		cnt++;
		for (int j = List[i].Next; j != -1; j = List[j].Next) {
			if (List[i].Key > List[j].Key) {
				Swap(List[i], List[j]);
				swap(i, j);
			}
		}
	}
	return cnt;
}

int main(int argc, char const *argv[])
{
	scanf("%d%d", &N, &head);
	for (int i = 0; i < N; ++i)
	{
		int address, key, next;
		scanf("%d%d%d", &address, &key, &next);
		List[address].Address = address;
		List[address].Key = key;
		List[address].Next = next;
		List[next].Prev = address;
	}
	int cnt = sort();
	if (cnt == 0) {
		printf("0 -1\n");
		return 0;
	}
	printf("%d %5d\n", cnt, head);
	for (int i = head; i != -1; i = List[i].Next)
	{
		if (List[i].Next == -1) {
			printf("%05d %d -1\n", List[i].Address, List[i].Key);
			break;
		}
		else
			printf("%05d %d %05d\n", List[i].Address, List[i].Key, List[i].Next);
	}


	return 0;
}
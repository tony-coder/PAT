#include <bits/stdc++.h>
using namespace std;

struct node
{
	int Galleon, Sickle, Knut;
} A, B;

node add(node& a, node& b)
{
	int Galleon, Sickle, Knut;
	int carry;
	Knut = (a.Knut + b.Knut) % 29;
	carry = (a.Knut + b.Knut) / 29;
	Sickle = (a.Sickle + b.Sickle + carry) % 17;
	carry = (a.Sickle + b.Sickle + carry) / 17;
	Galleon = a.Galleon + b.Galleon + carry;
	node ans = {Galleon, Sickle, Knut};
	return ans;
}

int main(int argc, char const *argv[])
{
	scanf("%d.%d.%d %d.%d.%d", &A.Galleon, &A.Sickle, &A.Knut, &B.Galleon, &B.Sickle, &B.Knut);
	node ans = add(A, B);
	printf("%d.%d.%d\n", ans.Galleon, ans.Sickle, ans.Knut);
	return 0;
}
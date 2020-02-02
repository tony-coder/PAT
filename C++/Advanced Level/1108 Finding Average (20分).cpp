#include <bits/stdc++.h>
using namespace std;

char input[100];
char tmp[100];
int main(int argc, char const *argv[])
{
	int N;
	scanf("%d", &N);
	double tot = 0.;
	int cnt = 0;
	for (int i = 0; i < N; ++i) {
		scanf("%s", input);
		double t;
		sscanf(input, "%lf", &t);
		sprintf(tmp, "%.2f", t);
		bool flag = false;
		for (int i = 0; i < strlen(input); ++i)
			if (input[i] != tmp[i]) {
				flag = true;
				break;
			}
		if (flag)
			printf("ERROR: %s is not a legal number\n", input );
		else {
			if (t < -1000 || t > 1000)
				printf("ERROR: %s is not a legal number\n", input );
			else {
				cnt++;
				tot += t;
			}
		}
	}
	if (cnt == 0)
		printf("The average of 0 numbers is Undefined\n" );
	else if (cnt == 1)
		printf("The average of 1 number is %.2f\n", cnt, tot / cnt );
	else
		printf("The average of %d numbers is %.2f\n", cnt, tot / cnt );
	return 0;
}
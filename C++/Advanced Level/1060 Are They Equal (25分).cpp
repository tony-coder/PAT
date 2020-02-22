#include <bits/stdc++.h>
using namespace std;

struct node {
	string value;
	int pos;
};

void change(node& A, int N) {
	int i = 0, pos = A.value.find(".");
	if (pos == -1) {
		// 要考虑不规范输入的情况，去除前导零
		while (A.value[i] == '0')
			i++;
		A.value = A.value.substr(i);
		A.pos = A.value.length();
	}
	else if (pos == 1 && A.value[0] == '0') {
		A.value.erase(pos, 1);
		while (A.value[i] == '0') {
			i++;
			A.pos--;
		}
		A.pos++;
		A.value = A.value.substr(i);
	}
	else {
		// 要考虑不规范输入的情况，去除前导零
		while (A.value[i] == '0')
			i++;
		A.value = A.value.substr(i);
		A.pos = pos - i;
		A.value.erase(pos - i, 1);
	}

	if (A.value.length() >= N) {
		A.value = A.value.substr(0, N);
	} else {
		for (i = A.value.length(); i < N; i++)
			A.value += "0";
	}
	if (stod(A.value) == 0.)
		A.pos = 0;
}

int main(int argc, char const *argv[])
{
	int N;
	node A, B;
	cin >> N >> A.value >> B.value;
	A.pos = B.pos = 0;
	bool flag = false;
	change(A, N);
	change(B, N);
	if (A.value == B.value && A.pos == B.pos)
		flag = true;

	if (flag) {
		printf("YES ");
		printf("0.%s*10^%d\n", A.value.c_str(), A.pos);
	} else {
		printf("NO ");
		printf("0.%s*10^%d 0.%s*10^%d\n", A.value.c_str(), A.pos, B.value.c_str(), B.pos);
	}

	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	// (12+4-13)+6*2
	// 124+13-62*+
	// string express[100] = {"12", "4", "+", "13", "-", "62", "*", "+"};
	string express = "12 4 + 13 - 6 2 * +";
	int cnt = express.length(), A, B;
	stack<int>s;
	for (int i = 0; i < cnt; ++i) {
		if (express[i] >= '0' && express[i] <= '9') {
			string tmp = "";
			while (express[i] >= '0' && express[i] <= '9') {
				tmp += express[i];
				i++;
			}
			s.push(stoi(tmp));
		} else if (express[i] != ' ') {
			if (!s.empty()) {
				B = s.top();
				s.pop();
			}
			if (!s.empty()) {
				A = s.top();
				s.pop();
			}
			switch (express[i]) {
			case '+':
				s.push(A + B);
				break;
			case '-':
				s.push(A - B);
				break;
			case '*':
				s.push(A * B);
				break;
			case '/':
				s.push(A / B);
				break;
			default:
				break;
			}
		}
	}
	cout << s.top() << endl;
	return 0;
}
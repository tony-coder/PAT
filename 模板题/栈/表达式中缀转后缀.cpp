#include <bits/stdc++.h>
using namespace std;

stack<char> s1;		// 运算符栈
stack<char> s2; 	// 中间结果栈

// 获取优先级
int getPriority(char ch) {
	int level = 0;

	switch (ch) {
	case '(':
		level = 1;
		break;
	case '+':
	case '-':
		level = 2;
		break;
	case '*':
	case '/':
		level = 3;
		break;
	default:
		break;
	}
	return level;
}

int main(int argc, char const *argv[])
{
	// char express[100] = "(12+4-13)+6*2";
	char express[100];
	scanf("%s", express);

	int len = strlen(express);
	for (int i = 0; i < len; ++i) {
		// 是数字，直接进结果栈
		if (express[i] >= '0' && express[i] <= '9')
			s2.push(express[i]);
		// 是运算符
		else if (express[i] == '+' || express[i] == '-' ||
		         express[i] == '*' || express[i] == '/') {
			while (true) {
				// s1为空栈，或者栈顶为空
				if (s1.empty() || s1.top() == '(') {
					s1.push(express[i]);
					break;
				} else if (getPriority(express[i]) > getPriority(s1.top())) {
					// 当前运算符优先级大于s1栈顶运算符优先级
					s1.push(express[i]);
					break;
				} else {
					char c = s1.top();
					s1.pop();
					s2.push(c);
				}
			}
		} else {
			// 括号
			if (express[i] == '(')
				s1.push(express[i]);
			else {
				while (s1.top() != '(') {
					char c = s1.top();
					s1.pop();
					s2.push(c);
				}
				s1.pop();  // 去掉剩下的'('
			}
		}
	}
	while (!s1.empty()) {
		char c = s1.top();
		s2.push(c);
		s1.pop();
	}
	// 注意，此时直接输出栈的话是逆序的
	string ans;
	while (!s2.empty()) {
		ans += s2.top();
		s2.pop();
	}
	reverse(ans.begin(), ans.end());
	cout << ans << endl;

	return 0;
}

// (12+4-13)+6*2
// 124+13-62*+
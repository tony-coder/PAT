#include <bits/stdc++.h>
using namespace std;

// 二分维护中间值

int mid;  // 维护的中值
vector<int> v;  // vector模拟栈
multiset<int> s1, s2; // s1储存小于等于mid的值，s2储存大于s2的值

// 维护s1.size()==s2.size() || s1.size()==s2.size()+1
void adjust() {
	multiset<int>::iterator it;
	if (s1.size() < s2.size()) {
		it = s2.begin();
		s1.insert(*it);
		s2.erase(it);
	} else if (s1.size() > s2.size() + 1) {
		it = s1.end();
		it--;
		s2.insert(*it);
		s1.erase(it);
	}
	if (!s1.empty()) {
		it = s1.end();
		it--;
		mid = *it;
	}
}

void Push(int val) {
	v.push_back(val);
	if (s1.empty())
		s1.insert(val);
	else if (val <= mid)
		s1.insert(val);
	else
		s2.insert(val);
	adjust();
}

void Pop() {
	if (v.size() == 0) {
		printf("Invalid\n");
		return;
	}
	int tmp = v[v.size() - 1];
	printf("%d\n", tmp);
	v.pop_back();
	if (tmp <= mid)
		s1.erase(s1.find(tmp));
	else
		s2.erase(s2.find(tmp));
	adjust();
}

void PeekMedian() {
	if (v.size() == 0) {
		printf("Invalid\n");
		return;
	}
	printf("%d\n", mid);
}

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		string op;
		cin >> op;
		int val;
		if (op == "Push") {
			cin >> val;
			Push(val);
		} else if (op == "Pop") {
			Pop();
		} else if (op == "PeekMedian") {
			PeekMedian();
		}
	}
	return 0;
}
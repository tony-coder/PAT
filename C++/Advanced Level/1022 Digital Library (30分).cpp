#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	map<string, set<int> > title_mp;
	map<string, set<int> > author_mp;
	map<string, set<int> > keyword_mp;
	map<string, set<int> > publisher_mp;
	map<int, set<int> > year_mp;
	for (int i = 0; i < N; ++i) {
		int id;
		string title, author, keywords, publisher;
		int year;
		cin >> id;
		cin.get();
		getline(cin, title);
		title_mp[title].insert(id);
		getline(cin, author);
		author_mp[author].insert(id);
		getline(cin, keywords);
		stringstream ss;
		ss << keywords;
		string keyword;
		while (ss >> keyword)
			keyword_mp[keyword].insert(id);
		getline(cin, publisher);
		publisher_mp[publisher].insert(id);
		cin >> year;
		year_mp[year].insert(id);
	}
	int M;
	cin >> M;
	cin.get();
	for (int i = 0; i < M; ++i) {
		string query, target;
		getline(cin, query);
		cout << query << endl;
		target = query.substr(3);
		if (query[0] == '1') {
			if (title_mp[target].size() == 0) {
				printf("Not Found\n");
				continue;
			}
			for (auto t : title_mp[target])
				printf("%07d\n", t);
		} else if (query[0] == '2') {
			if (author_mp[target].size() == 0) {
				printf("Not Found\n");
				continue;
			}
			for (auto t : author_mp[target])
				printf("%07d\n", t);
		} else if (query[0] == '3') {
			if (keyword_mp[target].size() == 0) {
				printf("Not Found\n");
				continue;
			}
			for (auto t : keyword_mp[target])
				printf("%07d\n", t);
		} else if (query[0] == '4') {
			if (publisher_mp[target].size() == 0) {
				printf("Not Found\n");
				continue;
			}
			for (auto t : publisher_mp[target])
				printf("%07d\n", t);
		} else if (query[0] == '5') {
			if (year_mp[stoi(target)].size() == 0) {
				printf("Not Found\n");
				continue;
			}
			for (auto t : year_mp[stoi(target)])
				printf("%07d\n", t);
		}
	}

	return 0;
}
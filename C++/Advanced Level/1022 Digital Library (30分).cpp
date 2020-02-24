#include <bits/stdc++.h>
using namespace std;

void show(map<string, set<int> >&mp, string target) {
	if (mp[target].size() == 0) {
		printf("Not Found\n");
		return;
	}
	for (auto t : mp[target])
		printf("%07d\n", t);
}

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	map<string, set<int> > title_mp, author_mp, keyword_mp, publisher_mp, year_mp;
	for (int i = 0; i < N; ++i) {
		int id;
		string title, author, keywords, publisher, year;
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
		if (query[0] == '1')
			show(title_mp, target);
		else if (query[0] == '2')
			show(author_mp, target);
		else if (query[0] == '3')
			show(keyword_mp, target);
		else if (query[0] == '4')
			show(publisher_mp, target);
		else if (query[0] == '5')
			show(year_mp, target);
	}

	return 0;
}
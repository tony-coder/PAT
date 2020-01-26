#include <bits/stdc++.h>
using namespace std;

struct node
{
	string name;
	string password;
	bool status;
	node(string _name, string _password, bool _status = false): name(_name), password(_password), status(_status) {}
};

vector<node> accounts;

node solve(string name, string password)
{
	node account(name, password);
	for (int i = 0; i < account.password.size(); ++i)
	{
		if (password[i] == '1')
		{
			account.password[i] = '@';
			account.status = true;
		}
		else if (password[i] == '0')
		{
			account.password[i] = '%';
			account.status = true;
		}
		else if (password[i] == 'l')
		{
			account.password[i] = 'L';
			account.status = true;
		}
		else if (password[i] == 'O')
		{
			account.password[i] = 'o';
			account.status = true;
		}
	}
	return account;
}

int main(int argc, char const *argv[])
{
	int N, count = 0;
	string name, password;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> name >> password;
		accounts.push_back(solve(name, password));
		if (accounts[i].status == true)
			count++;
	}

	if (count > 0)
	{
		cout << count << endl;
		for (int j = 0; j < N ; ++j)
		{
			if (accounts[j].status == true)
				cout << accounts[j].name << " " << accounts[j].password << endl;
		}
	}
	else if (N == 1)
		printf("There is %d account and no account is modified\n", N);
	else
		printf("There are %d accounts and no account is modified\n", N);

	return 0;
}
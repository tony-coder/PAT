#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
struct node
{
	// char name[10];
	// char id[10];
	string name, id;
	char gender;
	int grade;
	node(): name(""), id(""), gender(0), grade(0) {}
	node(string _name, char _gender, string _id, int _grade): name(_name), gender(_gender), id(_id), grade(_grade) {}
	void operator=(node & n)
	{
		name = n.name;
		id = n.id;
		gender = n.gender;
		grade = n.grade;
	}
};

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	// vector<node> stu(N);
	node male("", 'M', "", INF);
	node female("", 'F', "", 0);
	for (int i = 0; i < N; ++i)
	{
		node tmp;
		// scanf("%s %c %s %d",stu[i].name,&stu[i].gender,stu[i].id,&stu[i].grade);
		cin >> tmp.name >> tmp.gender >> tmp.id >> tmp.grade;
		if (tmp.gender == 'M' && tmp.grade < male.grade)
			male = tmp;
		else if (tmp.gender == 'F' && tmp.grade > female.grade)
			female = tmp;
	}
	bool flag = false;

	if (female.id != "")
		printf("%s %s\n", female.name.c_str(), female.id.c_str());
	else
	{
		flag = true;
		printf("Absent\n");
	}

	if (male.id != "")
		printf("%s %s\n", male.name.c_str(), male.id.c_str());
	else
	{
		flag = true;
		printf("Absent\n");
	}

	if (flag)
		printf("NA\n");
	else
		printf("%d\n", female.grade - male.grade);

	return 0;
}
#include <bits/stdc++.h>
using namespace std;
struct Student
{
	string code;
	int test;
	int exam;
	bool operator ==(const int & i)
	{
		return this->test == i;
	}
};

vector<Student> s;

void print_exam(int in)
{
	vector<Student>::iterator it;
	it = find(s.begin(), s.end(), in);
	if(it != s.end())
	{
		cout << it->code << " " << it->exam << endl;
	}
}

int main()
{
	int n, m;
	cin >> n;
	s.resize(n);
	for(int i = 0; i < n; i++)
	{
		cin >> s[i].code;
		cin >> s[i].test;
		cin >> s[i].exam;
	}
	cin >> m;
	for(int i = 0; i < m; i++)
	{
		int in;
		cin >> in;
		print_exam(in);
	}
	return 0;
}

//在struct中使用find函数的方法
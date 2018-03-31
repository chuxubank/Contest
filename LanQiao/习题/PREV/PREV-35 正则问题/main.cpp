#include <bits/stdc++.h>
using namespace std;
int i = 0, ans = 0;
string input;

int fun()
{
	int num = 0, maxnum = 0;
	while(i < input.length())
	{
		if(input[i] == 'x')
		{
			i++;
			num++;
		}
		else if(input[i] == '(')
		{
			i++;
			num += fun();
		}
		else if(input[i] == '|')
		{
			i++;
			maxnum = max(num, maxnum);
			num = 0;
		}
		else
		{
			i++;
			break;  //直接在此处return若长度正好则访问不到
		}
	}
	maxnum = max(num, maxnum);
	return maxnum;
}

int main()
{
	cin >> input;
	ans = fun();
	cout << ans;
	return 0;
}
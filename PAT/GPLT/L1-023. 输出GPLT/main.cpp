#include <bits/stdc++.h>
using namespace std;

int main()
{
	int gplt[4];
	memset(gplt, 0, sizeof(gplt));
	string input;
	cin >> input;
	for(char c:input)
	{
		if(c == 'g' || c == 'G')
			gplt[0]++;
		if(c == 'p' || c == 'P')
			gplt[1]++;
		if(c == 'l' || c == 'L')
			gplt[2]++;
		if(c == 't' || c == 'T')
			gplt[3]++;
	}
	int sum = 0;
	for(int i = 0; i < 4; i++)
		sum += gplt[i];
	for(int i = 0; i < sum; i++)
	{
		if(gplt[0])
		{
			cout << "G";
			gplt[0]--;
		}
		if(gplt[1])
		{
			cout << "P";
			gplt[1]--;
		}
		if(gplt[2])
		{
			cout << "L";
			gplt[2]--;
		}
		if(gplt[3])
		{
			cout << "T";
			gplt[3]--;
		}
	}
	return 0;
}
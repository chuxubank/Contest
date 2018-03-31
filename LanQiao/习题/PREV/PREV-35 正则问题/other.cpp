#include <bits/stdc++.h>
using namespace std;

int Fun()
{
	char data;
	int x = 0, y = 0;
	while(1)
	{
		data = getchar();
		if(data == 'x')
			x++;
		else if(data == '|')
		{
			y = max(x, y);
			x = 0;
		}
		else if(data == '(')
			x += Fun();
		else
		{
			y = max(x, y);
			return y;
		}
	}
}

int main()
{
	int ans = Fun();
	cout << ans << endl;
}

//相当骚的做法，利用getchar()可以在else中return
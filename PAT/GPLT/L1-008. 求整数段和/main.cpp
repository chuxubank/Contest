#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	int count = 0;
	int sum = 0;
	for(int i = a; i <= b; i++)
	{
		sum += i;
		count++;
		cout << setw(5) << i;   //设置域宽
		if(count % 5 == 0)
		{
			cout << endl;
		}
		else if(i == b)
		{
			cout << endl;
		}
	}
	cout << "Sum = " << sum << endl;
	return 0;
}
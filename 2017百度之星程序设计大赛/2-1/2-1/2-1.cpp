#include <iostream>
#include<algorithm>
using namespace std;
long long t, p;
int main()
{
	cin >> t;
	while (t--)
	{
		long long count = 0;
		cin >> p;
		for (int x = 1; x < sqrt(p - 1); x++)
		{
			if ((p - 1) % x == 0)
				count++;
		}
		count *= 2;
		if(sqrt(p-1)==(int)sqrt(p-1))
			count++;
		cout << count << endl;
	}
	return 0;
}
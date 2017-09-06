#include <iostream>
using namespace std;
int n, m, k;
int s[50001];
int t[101];
bool equalaccortime(int a, int i, int length)
{
	int ilength;
	int counts = 0, countt = 0;
	if (i + length > n)
		return false;
	else
		ilength = i + length;
	for (; i<ilength; i++)
	{
		if (s[i] == a)
		{
			counts++;
		}
	}
	for (int j = 0; j<k; j++)
	{
		if (t[j] == a)
		{
			countt++;
		}
	}
	if (counts == countt)
		return true;
	else
		return false;
}
int main()
{
	cin >> n;
	for (int i = 0; i<n; i++)
	{
		cin >> s[i];
	}
	cin >> m;
	while (m--)
	{
		int count = 0;
		int degree=0;
		cin >> k;
		for (int i = 0; i<k; i++)
		{
			cin >> t[i];
		}
		for (int i = 0; i<n; i++)
		{
			count = 0;
			for (int j = 0; j<k; j++)
			{
				if (equalaccortime(t[j], i, k))
					count++;
			}
			if (count == k)
				degree++;
		}
		cout << degree << endl;
	}
	return 0;
}

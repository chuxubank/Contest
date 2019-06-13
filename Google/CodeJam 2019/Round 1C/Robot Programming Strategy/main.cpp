#include <bits/stdc++.h>
using namespace std;

string getWinFrom(string str)
{
	if (str.length() == 2)
	{
		if (str.find("R") == string::npos)
		{
			return "P";
		}
		else if (str.find("S") == string::npos)
		{
			return "R";
		}
		else if (str.find("P") == string::npos)
		{
			return "S";
		}
	}
	else if (str.length() == 1)
	{
		if (str.find("R") != string::npos)
		{
			return "S";
		}
		else if (str.find("S") != string::npos)
		{
			return "P";
		}
		else if (str.find("P") != string::npos)
		{
			return "R";
		}
	}
	return "";
}

int main()
{
	int t;
	cin >> t;
	for (int c = 1; c <= t; c++)
	{
		int a;
		cin >> a;
		string input[a];
		unsigned long maxlength = 0;
		for (int i = 0; i < a; i++)
		{
			cin >> input[i];
			maxlength = max(input[i].length(), maxlength);
		}
		string ans = "";
		bool isPossible = true;
		for (int i = 0; i < maxlength; i++)
		{
			string list = "RSP";
			for (int j = 0; j < a; j++)
			{
				int index = i % input[j].length();
				list.erase(remove(list.begin(), list.end(), input[j].at(index)), list.end());
				if (list.length() == 0)
				{
					isPossible = false;
					break;
				}
			}
			if (!isPossible)
				break;
			ans.append(getWinFrom(list));
			if (list.length() == 2 && i == maxlength)
			{
				isPossible = true;
				ans.append(getWinFrom(list));
				break;
			}
		}
		printf("Case #%d: %s\n", c, isPossible ? ans.c_str() : "IMPOSSIBLE");
	}
	return 0;
}
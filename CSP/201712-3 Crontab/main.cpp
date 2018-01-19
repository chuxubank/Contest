#include <bits/stdc++.h>
using namespace std;
struct ctline
{
	set<int> datetime[5];
	string command;
} c[10005];

int get_dayofweek(int year, int month, int day)
{
}

void insertintos(string a, int type, int i)
{
	int min, max;
	switch (type)
	{
		case 0:
			min = 0;
			max = 59;
			break;

		case 1:
			min = 0;
			max = 23;
			break;

		case 2:
			min = 1;
			max = 31;
			break;

		case 3:
			min = 1;
			max = 12;
			break;

		case 4:
			min = 0;
			max = 6;
			break;
	}

	//have *
	if (a.find('*') != string::npos)
	{
		for (int j = min; j <= max; j++)
			c[i].datetime[type].insert(j);
	}
	//have ,
	else if (a.find(',') != string::npos)
	{
		while (a.find(',') != string::npos)
		{
			string temp = a.substr(0, a.find(','));
			//have , and -
			if (temp.find("-") != string::npos)
			{
				temp[temp.find("-")] = ' ';
				stringstream ss(temp);
				int start, end;
				ss >> start >> end;
				for (int j = start; j <= end; j++)
					c[i].datetime[type].insert(j);
			}
			else
			{
				stringstream ss(temp);
				int tempint;
				ss >> tempint;
				c[i].datetime[type].insert(tempint);
			}
			a.erase(0, a.find(',') + 1);
		}
		cout << "a=" << a << endl;
	}
	//only have -
	if (a.find('-') != string::npos)
	{
		string temp = a;
		temp[temp.find("-")] = ' ';
		stringstream ss(temp);
		int start, end;
		ss >> start >> end;
		for (int j = start; j <= end; j++)
			c[i].datetime[type].insert(j);
	}
	stringstream ss(a);
	int tempint;
	ss >> tempint;
	c[i].datetime[type].insert(tempint);
}

void makeline(string m, string h, string dom, string month, string dow, string com, int i)
{
	insertintos(m, 0, i);
	insertintos(h, 1, i);
	insertintos(dom, 2, i);
	insertintos(month, 3, i);
	insertintos(dow, 4, i);
	c[i].command = com;
}

int main()
{
	int n;
	string s, t;
	cin >> n >> s >> t;
	for (int i = 1; i <= n; i++)
	{
		string m, h, dom, month, dow, com;
		cin >> m >> h >> dom >> month >> dow >> com;
		cout << com << endl;
		makeline(m, h, dom, month, dow, com, i);
	}
//	for(set<int>::iterator it=c[1].datetime[0].begin();it!=c[1].datetime[0].end();++it)
//		cout<<*it<<endl;
	int year[3], month[3], day[3], hour[3], minute[3];
	//start
	s.insert(4, " ");
	s.insert(7, " ");
	s.insert(10, " ");
	s.insert(13, " ");
	stringstream ss1(s);
	ss1 >> year[0] >> month[0] >> day[0] >> hour[0] >> minute[0];
	//now
	year[1] = year[0];
	month[1] = month[0];
	day[1] = day[0];
	hour[1] = hour[0];
	minute[1] = minute[0];
	//end
	t.insert(4, " ");
	t.insert(7, " ");
	t.insert(10, " ");
	t.insert(13, " ");
	stringstream ss2(t);
	ss2 >> year[2] >> month[2] >> day[2] >> hour[2] >> minute[2];
	while (year[1] != year[2] || month[1] != month[2] || day[1] != day[2] || hour[1] != hour[2] || minute[1] != minute[2])
	{
		for (int i = 1; i < n; i++)
		{
			if (c[i].datetime[0].find(minute[1]) != c[i].datetime[0].end()
			    && c[i].datetime[1].find(hour[1]) != c[i].datetime[1].end()
			    && c[i].datetime[2].find(day[1]) != c[i].datetime[2].end()
			    && c[i].datetime[3].find(month[1]) != c[i].datetime[3].end())
			{
				printf("%04d%02d%02d%02d%02d %s\n", year[1], month[1], day[1], hour[1], minute[1], c[i].command.c_str());
				break;
			}
		}
		minute[1]++;
		if (minute[1] == 60)
		{
			minute[1] = 0;
			hour[1]++;
		}
		if (hour[1] == 24)
		{
			hour[1] = 0;
			day[1]++;
		}
		if (day[1] == 32)
		{
			day[1] = 1;
			month[1]++;
		}
		if (month[1] == 13)
		{
			month[1] = 1;
			year[1]++;
		}
	}
	return 0;
}

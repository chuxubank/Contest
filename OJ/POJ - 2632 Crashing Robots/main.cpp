#include <iostream>
#include <sstream>
#include <vector>
#include <map>
using namespace std;
struct Robot
{
	int num;
	int x;
	int y;
	char dire;
};

int t, n, m, a, b, num, times;
char func;
vector <Robot> r;
map<char, int> dirtoint;
map<int, char> inttodir;

int forward()
{
	switch (r[num].dire)
	{
		case 'N':
			r[num].y++;
			break;

		case 'E':
			r[num].x++;
			break;

		case 'S':
			r[num].y--;
			break;

		case 'W':
			r[num].x--;
			break;
	}
	if (r[num].x<1 || r[num].x>a || r[num].y<1 || r[num].y>b)
		return -1;
	for (int i = 1; i <= n; i++)
	{
		if (r[i].x == r[num].x && r[i].y == r[num].y && r[i].num != num)
			return r[i].num;
	}
	return 0;
}

void turn_left()
{
	int now = dirtoint[r[num].dire];
	now -= 1;
	if (now == -1)
		now = 3;
	r[num].dire = inttodir[now];
}

void turn_right()
{
	int now = dirtoint[r[num].dire];
	now += 1;
	r[num].dire = inttodir[now % 4];
}

int main()
{
	dirtoint['N'] = 0;
	dirtoint['E'] = 1;
	dirtoint['S'] = 2;
	dirtoint['W'] = 3;
	inttodir[0] = 'N';
	inttodir[1] = 'E';
	inttodir[2] = 'S';
	inttodir[3] = 'W';
	cin >> t;
	while (t--)
	{
		cin >> a >> b;
		cin >> n >> m;
		Robot tempr;
		r.resize(n + 1);
		for (int i = 1; i <= n; i++)
		{
			tempr.num = i;
			cin >> tempr.x;
			cin >> tempr.y;
			cin >> tempr.dire;
			r[i] = tempr;
		}
		int flag = 0;
		stringstream ss;
		getchar();
		for (int i = 0; i < m; i++)
		{
			string line;
			getline(cin, line);
			ss << line << endl;
		}
		while (ss >> num >> func >> times)
		{
			while (times--)
			{
				switch (func)
				{
					case 'F':
						flag = forward();
						break;

					case 'L':
						turn_left();
						break;

					case 'R':
						turn_right();
						break;
				}
				if (flag != 0)
					break;
			}
			if (flag != 0)
				break;
		}
		switch (flag)
		{
			case 0:
				cout << "OK" << endl;
				break;

			case -1:
				cout << "Robot " << num << " crashes into the wall" << endl;
				break;

			default:
				cout << "Robot " << num << " crashes into robot " << flag << endl;
				break;
		}
		r.clear();
	}
}

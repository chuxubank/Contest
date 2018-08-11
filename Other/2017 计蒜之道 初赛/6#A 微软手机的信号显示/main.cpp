#include <stdio.h>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <map>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	if(n < 20)
	{
		printf("+-----+\n");
		printf("|    E|\n");
		printf("|     |\n");
		printf("|     |\n");
		printf("|     |\n");
		printf("|     |\n");
		printf("+-----+\n");
		return 0;
	}
	else if(n >= 20 && n < 40)
	{
		printf("+-----+\n");
		printf("|-   E|\n");
		printf("|     |\n");
		printf("|     |\n");
		printf("|     |\n");
		printf("|     |\n");
		printf("+-----+\n");
		return 0;
	}
	else if(n >= 40 && n < 60)
	{
		printf("+-----+\n");
		printf("|-   E|\n");
		printf("|--   |\n");
		printf("|     |\n");
		printf("|     |\n");
		printf("|     |\n");
		printf("+-----+\n");
		return 0;
	}
	else if(n >= 60 && n < 80)
	{
		printf("+-----+\n");
		printf("|-  3G|\n");
		printf("|--   |\n");
		printf("|---  |\n");
		printf("|     |\n");
		printf("|     |\n");
		printf("+-----+\n");
		return 0;
	}
	else if(n >= 80 && n < 90)
	{
		printf("+-----+\n");
		printf("|-  3G|\n");
		printf("|--   |\n");
		printf("|---  |\n");
		printf("|---- |\n");
		printf("|     |\n");
		printf("+-----+\n");
		return 0;
	}
	else if(n >= 90 && n < 100)
	{
		printf("+-----+\n");
		printf("|-  4G|\n");
		printf("|--   |\n");
		printf("|---  |\n");
		printf("|---- |\n");
		printf("|     |\n");
		printf("+-----+\n");
		return 0;
	}
	else if(n == 100)
	{
		printf("+-----+\n");
		printf("|-  4G|\n");
		printf("|--   |\n");
		printf("|---  |\n");
		printf("|---- |\n");
		printf("|-----|\n");
		printf("+-----+\n");
		return 0;
	}
	return 0;
}

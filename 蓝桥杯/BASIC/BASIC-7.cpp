#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main()
{
	int i;
	char num[3];
	for(i=1;i<=999;i++)
	{
		itoa(i,num,10);
		if(pow(num[0]-'0',3)+pow(num[1]-'0',3)+pow(num[2]-'0',3)==i)
			printf("%d\n",i);
	}
	return 0;
}

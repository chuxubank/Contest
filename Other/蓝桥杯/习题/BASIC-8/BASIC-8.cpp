#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i,j;
	char a[4];
	for(i=1000;i<=9999;i++)
	{
		itoa(i,a,10);
		if(a[0]==a[3]&&a[1]==a[2])
			printf("%d\n",i);
			
	}
	return 0;
}

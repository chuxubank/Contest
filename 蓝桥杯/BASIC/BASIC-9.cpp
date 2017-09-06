#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int i,j,n,sum;
	char a[6],b[6];
	scanf("%d",&n);
	for(i=10000;i<=999999;i++)
	{
		sum=0;
		itoa(i,a,10);
		strcpy(b,a);
		for(j=0;j<=strlen(a)-1;j++)
		{
			b[strlen(a)-1-j]=a[j];
			sum+=a[j]-'0';
		} 
		if(strcmp(a,b)==0&&sum==n)
			printf("%d\n",i);
	}
	return 0;
}

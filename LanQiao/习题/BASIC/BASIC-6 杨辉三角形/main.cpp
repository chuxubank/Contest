#include <stdio.h>
int main()
{
	static int a[35][35],i,j,n;
	scanf("%d",&n);
	a[1][1]=1;
	for(i=2;i<=n;i++)
	{
		for(j=1;j<=i;j++)
		{
			a[i][j]=a[i-1][j-1]+a[i-1][j];
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=i;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n"); 
	}
	return 0;
}

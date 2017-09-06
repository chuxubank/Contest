#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void matmul(int a[30][30],int b[30][30],int n)
{
	int i,j,i1;
	int c[30][30];
	memset(c,0,sizeof(c));  
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			for(i1=0;i1<n;i1++)
			{
				c[i][j]+=a[i][i1]*b[i1][j];
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			a[i][j]=c[i][j];
		}
	}
}
int main()
{
	int i,j,n,m;
	int a[30][30],b[30][30];
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			b[i][j]=a[i][j];
		}
	}
	if(m==0)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(i==j)
					printf("1 ");
				else
					printf("0 ");
			}
			printf("\n");
		}
	}
	else
	{
		for(i=1;i<m;i++)
		{
			matmul(a,b,n);
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				printf("%d ",a[i][j]);
			}
			printf("\n");
		}
	}	
	return 0;
}

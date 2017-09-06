#include <stdio.h>
#include <math.h>
void wqueen(int k);
void bqueen(int k);
int a[9][9],count=0,n;
int w[9],b[9];
int main()
{
	int i,j;
	int q;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	wqueen(0);
	printf("%d",count);
	return 0;
}
void wqueen(int k)
{
	int i,j;
	for(i=0;i<k-1;i++)
	{
		if(w[i]==w[k-1]||abs(k-1-i)==abs(w[k-1]-w[i]))
			return;
	}
	if(k==n)
	{
		bqueen(0);
		return;
	}
	for(j=0;j<n;j++)
	{
		if(a[k][j])
		{
			w[k]=j;
			wqueen(k+1);
		}
	}
}
void bqueen(int k)
{
	int i,j;
	for(i=0;i<k-1;i++)
	{
		if(b[i]==b[k-1]||abs(k-1-i)==abs(b[k-1]-b[i]))
			return;
	}
	if(k==n)
	{
		count++;
		return;
	}
	for(j=0;j<n;j++)
	{
		if(a[k][j]&&j!=w[k])
		{
			b[k]=j;
			bqueen(k+1);
		}
	}
} 

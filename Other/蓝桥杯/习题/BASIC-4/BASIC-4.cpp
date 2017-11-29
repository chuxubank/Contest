#include <stdio.h>
int main()
{
	int i,j,sum,a[10001],n,max,min;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	sum=max=min=a[1];
	for(i=2;i<=n;i++)
	{
		if(a[i]<min)
			min=a[i];
		if(a[i]>max)
			max=a[i];
		sum+=a[i];
	}
	printf("%d\n%d\n%d",max,min,sum);
	return 0;
} 

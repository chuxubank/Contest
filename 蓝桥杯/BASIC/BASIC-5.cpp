#include <stdio.h>
int main()
{
	int i,n,x,a[1001],flag=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	scanf("%d",&x);
	for(i=1;i<=n;i++)
	{
		if(a[i]==x)
		{
			printf("%d",i);
			flag=1;
			break;
		}
	}
	if(flag==0)
		printf("-1");
	return 0;
}

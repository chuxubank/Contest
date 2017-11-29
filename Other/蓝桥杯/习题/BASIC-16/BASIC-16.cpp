#include <stdio.h>
int is_prime(int a)
{
	int i;
	for(i=2;i<=a/2;i++)
	{
		if(a%i==0)
			break;
	}
	if(i>a/2)
		return 1;
	else
		return 0;
}
int main()
{
	int i,j,first,last,t,prime[10001];
	scanf("%d %d",&first,&last);
	for(i=2,j=0;i<=last;i++)
	{
		if(is_prime(i)==1)
		{
			prime[j]=i;
			j++;
		}
	}
	for(i=first;i<=last;i++)
	{
		if(is_prime(i)==1)
			printf("%d=%d\n",i,i);
		else
		{
			t=i;
			j=0;
			printf("%d=",i);
			while(t!=1)
			{
				if(t%prime[j]==0)
				{
					printf("%d",prime[j]);
					t/=prime[j];
					j=0;
					if(t!=1)
						printf("*");
				}
				else
					j++;
			}
			printf("\n");
		}
	}
	return 0;
}

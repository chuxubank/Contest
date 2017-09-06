#include <stdio.h>
#include <math.h>
#include <string.h>
int main()
{
	char alphabet[27];
	int i,j,n,m;
	scanf("%d",&n);
	scanf("%d",&m);
	strcpy(alphabet,"ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			printf("%c",alphabet[abs(i-j)]);
		}
		printf("\n");
	}
	return 0;
} 

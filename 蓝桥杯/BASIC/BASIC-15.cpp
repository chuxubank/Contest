#include<stdio.h>
#include<string.h>
int scmp(char* a,char* b)
{
	int i,flag=0;
	for(i=0;i<strlen(a);i++)
	{
		if(a[i]==b[i]||a[i]==b[i]+32||a[i]==b[i]-32)
			i=i;
		else
		{
			flag=1;
		}
	}
	return flag;
}
int main()
{
	int i,al,bl;
	char a[11],b[11];
	scanf("%s %s",a,b);
	al=strlen(a);
	bl=strlen(b);
	if(al!=bl)
	{
		printf("1"); 
	}
	if(strcmp(a,b)==0)
	{
		printf("2");
	}
	else if(al==bl&&scmp(a,b)==0) 
	{
		printf("3");	
	}
	else if(al==bl&&scmp(a,b)==1)
	{
		printf("4");	
	}
	return 0;
}

#include <stdio.h>
#include <string.h>
int main()
{
	int length,i,j,count=0,begin=1;
	char input[11];
	char output [9999][5];
	char number[11][5]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu","shi"};
	char wei[4][5]={"","shi","bai","qian"};
	char wei2[3][5]={"","wan","yi"};
	scanf("%s",input);
	length=strlen(input);
	for(i=length-1,j=1;i>=0;i--,j++)
	{
//		if(length!=2&&(input[i-1]-'0')!=1)
		{
			strcpy(output[j],number[input[i]-'0']);
		}
		if((length-i)%4==0 && i!=0)
		{
			count++;
			strcpy(output[j+1],wei2[count]);
			j++;
		}
		else if(input[i-1]-'0'!=0 && i!=0)
		{
			strcpy(output[j+1],wei[(length-i)%4]);
			j++;
		}
		if(strcmp(output[j],number[0])==0&&(input[i-1]-'0')==0)
		{
			j--;
			continue;
		}
	}
	for(i=1;i<j;i++)
	{
		if(strcmp(output[i],number[0])==0)
			begin++;
		else
			break;
	}
	if(strcmp(output[j-1],number[1])==0&&strcmp(output[j-2],wei[1])==0)
	{
		j--;
	}
	for(i=j-1;i>=begin;i--)
	{
		printf("%s ",output[i]);
	}
	return 0;
}

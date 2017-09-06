#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
char* hextobin(char a)
{
	char binout[5];
	switch(a)
	{
		case '0':
			strcpy(binout,"0000");
			break;
		case '1':
			strcpy(binout,"0001");
			break;
		case '2':
			strcpy(binout,"0010");
			break;
		case '3':
			strcpy(binout,"0011");
			break;
		case '4':
			strcpy(binout,"0100");
			break;
		case '5':
			strcpy(binout,"0101");
			break;
		case '6':
			strcpy(binout,"0110");
			break;		
		case '7':
			strcpy(binout,"0111");
			break;
		case '8':
			strcpy(binout,"1000");
			break;		
		case '9':
			strcpy(binout,"1001");
			break;		
		case 'A':
			strcpy(binout,"1010");
			break;
		case 'B':
			strcpy(binout,"1011");
			break;
		case 'C':
			strcpy(binout,"1100");
			break;		
		case 'D':
			strcpy(binout,"1101");
			break;
		case 'E':
			strcpy(binout,"1110");
			break;
		case 'F':
			strcpy(binout,"1111");
			break;
	}
	return binout;
}
int main()
{
	char hex[100001],bin[400004],oct[133336];
	char *p_oct=oct;
	int n,i,j,k,length,oct_len,t=0,count;
	char temp[100001],ct[2];
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		t=0;
		memset(bin,0,400004);
		scanf("%s",temp);
		length=strlen(temp);
		for(j=0;j<length;j++)
		{
			strcat(bin,hextobin(temp[j]));
		}
		length=strlen(bin);
		oct_len=length/3;
		if(length%3 != 0)
			oct_len++;
		k=oct_len-1;
		count=0;
		for(j=length-1;j>=0;j--)
		{
			t+=(bin[j]-'0')*pow(2,count);
			count++;
			if(j==0 && count!=3)
			{
				if(t!=0)
				{
					itoa(t,ct,8);
					oct[0]=ct[0];
				}
				else
				{
					oct[0]='0';
				}
			}
			if(count == 3)
			{
				itoa(t,ct,8);
				oct[k]=ct[0];
				t=0;
				count=0;
				k--;
			}
			
		}
		oct[oct_len]='\0';
		p_oct=oct;
		j=0;
		while(p_oct[j]=='0')
		{
			p_oct++;
			j++;
		}
		printf("%s\n",p_oct);
	}
	return 0;
}

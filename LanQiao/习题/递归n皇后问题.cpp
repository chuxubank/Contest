#include<stdio.h>
#include<string.h>
#include<math.h>
#define MAXSIZE 100
int x[MAXSIZE];//x[k]����ĵ�k���ʺ���x[k]�У�k��0��ʼ����Ҳ��0��ʼ
int count =0;
int n =8;
void queen(int k);
int main(void) 
{
    queen(0);
    printf("%d\n",count);
    return 0;
}
void queen(int k)
{
    for(int i =0; i < k -1; i++)//�ж��Ƿ������һ���ݹ������
    {
        int judge = x[i]- x[k -1];
        if(judge ==0|| fabs(k -1- i)== fabs(judge))
            return;
    }
    if(k == n)//�����ݹ������  
    {
        count++;
        return;
    }
    for(int j =0; j < n; j++)
    {
        x[k]= j;
        queen(k +1);
    }  
}  

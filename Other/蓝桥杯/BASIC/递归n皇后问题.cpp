#include<stdio.h>
#include<string.h>
#include<math.h>
#define MAXSIZE 100
int x[MAXSIZE];//x[k]代表的第k个皇后在x[k]列，k从0开始，列也从0开始
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
    for(int i =0; i < k -1; i++)//判断是否进入下一个递归的条件
    {
        int judge = x[i]- x[k -1];
        if(judge ==0|| fabs(k -1- i)== fabs(judge))
            return;
    }
    if(k == n)//跳出递归的条件  
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

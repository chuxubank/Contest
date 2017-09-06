#include<stdio.h>
#include<string.h>
#include<math.h>
#define MAXSIZE 100
int x[MAXSIZE];//x[k]代表的第k个皇后在x[k]列，k从0开始，列也从0开始
int place(int k);//判断是否满足条件的函数
void queeen(int n);
int main(void)
{
    queeen(4);
    return 0;
}
void queeen(int n)   
{ 
    memset(x,-1,n);//先初始化x数组，前n个数为 -1
    int k =0;//k代表的是皇后的序号（我这里是从0开始的），也代表的是数组的第几行
    while(k >=0)
    {
        x[k]++;
        while(x[k]< n && place(k)==1)  //此列不能放则向下找 
            x[k]++;  
        if(x[k]< n && k == n -1)  //最后一行 找到一个解 
        {  
            for(int i =0; i < n; i++)  // 输出所有皇后位置 
                printf("%d\n",x[i]+1);  
            return;  
        }  
        if(x[k]< n && k < n-1)  //不是最后一行则往下继续搜索； 
            k = k +1;  
        else  //所有列均不能放则往前一行，重新找上一行的列 
            x[k--]=-1;//回溯到上一个皇后  位置置为-1  
	}
    printf("无解\n");
}  
int place(int k)  
{  
    for(int i =0; i < k; i++)  
    {  
        if(x[i]== x[k]|| fabs(i - k)== fabs(x[i]- x[k]))//要注意的是这里利用了斜率的绝对值是否为1来确定是否在一个斜线上。
            return 1;  
    }  
    return 0;  
}

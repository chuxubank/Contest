#include<stdio.h>
#include<string.h>
#include<math.h>
#define MAXSIZE 100
int x[MAXSIZE];//x[k]����ĵ�k���ʺ���x[k]�У�k��0��ʼ����Ҳ��0��ʼ
int place(int k);//�ж��Ƿ����������ĺ���
void queeen(int n);
int main(void)
{
    queeen(4);
    return 0;
}
void queeen(int n)   
{ 
    memset(x,-1,n);//�ȳ�ʼ��x���飬ǰn����Ϊ -1
    int k =0;//k������ǻʺ����ţ��������Ǵ�0��ʼ�ģ���Ҳ�����������ĵڼ���
    while(k >=0)
    {
        x[k]++;
        while(x[k]< n && place(k)==1)  //���в��ܷ��������� 
            x[k]++;  
        if(x[k]< n && k == n -1)  //���һ�� �ҵ�һ���� 
        {  
            for(int i =0; i < n; i++)  // ������лʺ�λ�� 
                printf("%d\n",x[i]+1);  
            return;  
        }  
        if(x[k]< n && k < n-1)  //�������һ�������¼��������� 
            k = k +1;  
        else  //�����о����ܷ�����ǰһ�У���������һ�е��� 
            x[k--]=-1;//���ݵ���һ���ʺ�  λ����Ϊ-1  
	}
    printf("�޽�\n");
}  
int place(int k)  
{  
    for(int i =0; i < k; i++)  
    {  
        if(x[i]== x[k]|| fabs(i - k)== fabs(x[i]- x[k]))//Ҫע���������������б�ʵľ���ֵ�Ƿ�Ϊ1��ȷ���Ƿ���һ��б���ϡ�
            return 1;  
    }  
    return 0;  
}

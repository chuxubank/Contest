#include<stdio.h>  
#include<stdlib.h>  
int main()  
{  
    int i,j,l,n,k,sum=0,flag=1,only=1;  
    char a[8001];  
    scanf("%d",&n); 
    scanf("%s",a);
    j=n-1; 
    for(i=0;i<j;i++)    
    {  
        for(k=j;k>=i;k--)  
        {  
            if(k==i)
            {  
                if(n%2==0||only==0)
                {  
                    flag=0;  
                    break;  
                }  
                only=0;
                sum+=n/2-i;  
                break;  
            }  
            if(a[k]==a[i])  
            {  
                for(l=k;l<j;l++)  
                {  
                    a[l]=a[l+1];  
                }  
                a[j]=a[i];  
                sum+=j-k;  
                j--;
                break; 
            }  
        }  
        if(flag==0)  
           break;  
    } 
    if(flag==0)  
      printf("Impossible");  
    else  
      printf("%d",sum);  
    return 0;  
}  

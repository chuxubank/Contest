#include <iostream>

using namespace std;

int a[205][205];
int n,m;

int findlove(int l)
{
    int i,j;
    int flag;
    for(int i=1;i<=n-l+1;i++)
    {
        for(int j=1;j<=m-l+1;j++)
        {
            flag=1;
            for(int x=i;x<=i+l-1;x++)
            {
                for(int y=j;y<=j+l-1;y++)
                {
                    if(a[x][y]!=a[i][j])
                    {
                        flag=0;
                        break;
                    }
                }
            }
            if(flag==1)
            	return 1;
        }
    }
    return flag;
}

int main()
{

    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }
    int s=1,t=min(n,m);
    int mid=(s+t)>>1;
    while(s<=t)
    {
        if(findlove(mid)==1)
            s=mid+1;
        else
            t=mid-1;
        mid=(s+t)/2;
    }
    printf("%d\n",(s-1)*(s-1));
    return 0;
}

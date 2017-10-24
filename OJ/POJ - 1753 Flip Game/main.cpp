#include <iostream>
#include <climits>
using namespace std;
int a[6][6];
int minn=INT_MAX;
int judge()
{
    if(a[1][1]==-1)
    {
        for(int i=1;i<=4;i++)
            for(int j=1;j<=4;j++)
                if(a[i][j]!=-1)
                    return 0;
    }
    else
    {
        for(int i=1;i<=4;i++)
            for(int j=1;j<=4;j++)
                if(a[i][j]!=1)
                    return 0;
    }
    return 1;
}

void flip(int x,int y)
{
    a[x][y]=-a[x][y];
    a[x-1][y]=-a[x-1][y];
    a[x][y-1]=-a[x][y-1];
    a[x+1][y]=-a[x+1][y];
    a[x][y+1]=-a[x][y+1];
//    for(int i=1;i<=4;i++)
//    {
//        for(int j=1;j<=4;j++)
//            cout<<a[i][j];
//        cout<<endl;
//    }
}

void dfs(int cur,int step)
{
    if(cur==17)
    {
        if(judge() && minn>step)
            minn=step;
        return;
    }
    flip(cur/4+1,cur%4+1);
    dfs(cur+1,step+1);
    flip(cur/4+1,cur%4+1);
    dfs(cur+1,step);
}
int main()
{
    char b[6][6];
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=4;j++)
        {
            cin>>b[i][j];
            if(b[i][j]=='b')
                a[i][j]=1;
            if(b[i][j]=='w')
                a[i][j]=-1;
        }
        getchar();
    }
    dfs(0,0);
    cout<<minn<<endl;
}

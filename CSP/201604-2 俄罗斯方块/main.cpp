#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e9+7;
int a[20][15],in[5][5];
int row=1,col;
bool judge()
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(in[i][j]==1 &&(i+row-1<0 || i+row-1>14 || j+col-1<0 || j+col-1>14) ||in[i][j]==1 && a[i+row-1][j+col-1]==1)
                return false;
        }
    }
    return true;
}

int main()
{
	for(int i=0;i<15;i++)
    {
        for(int j=0;j<10;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            cin>>in[i][j];
        }
    }
    cin>>col;
    while(judge())
        row++;
    row--;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(in[i][j]==1)
                a[i+row-1][j+col-1]=in[i][j];
        }
    }
    for(int i=0;i<15;i++)
    {
        for(int j=0;j<10;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

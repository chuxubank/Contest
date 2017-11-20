#include <iostream>

using namespace std;

int sum(int i,int j)
{
    return (i+j)*(j-i+1)/2;
}

int main()
{
    int a,s;
    cin>>a;
    for(int i=1;i<=a/2;i++)
    {
        for(int j=i;j<=a;j++)
        {
            s=sum(i,j);
            if(s==a)
                cout<<i<<" "<<j<<endl;
            if(s>a)
                break;
        }
    }
    return 0;
}

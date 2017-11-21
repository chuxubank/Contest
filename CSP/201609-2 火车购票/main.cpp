#include <iostream>

using namespace std;
int a[105];
bool sit[105]={false};

int findfirst(int in)
{
    return (in-1)/5;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        int j=1;
        while(sit[j]==true)
            j++;
//        cout<<findfirst(j+a[i]-1)<<" "<<findfirst(j)<<endl;
        while(findfirst(j+a[i]-1)!=findfirst(j) || sit[j]==true ||sit[j+a[i]-1]==true)
        {
            j++;
//            cout<<findfirst(j+a[i]-1)<<" "<<findfirst(j)<<endl;
        }
//        cout<<j<<endl;
        if(j==101)
            j=1;
        for(int k=0;k<a[i];k++)
        {
            while(sit[j]==true)
                j++;
            sit[j]=true;
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}

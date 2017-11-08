#include <iostream>

using namespace std;

int sum(int* a,int be,int en)
{
    int sum=0;
    for(int i=be;i<=en;i++)
        sum+=a[i];
    return sum;
}

int main()
{
    int s,d;
    while(cin>>s>>d)
    {
        int a[13];
        for(int i=1;i<=12;i++)
            a[i]=s;
        d=-d;
        for(int i=1;i<=8;i++)
        {
            int j=i+4;
            while(sum(a,i,i+4)>=0)
            {
                a[j--]=d;
            }
        }

        int summ=sum(a,1,12);
        if(summ>=0)
            cout<<summ<<endl;
        else
            cout<<"Deficit"<<endl;
    }
    return 0;
}

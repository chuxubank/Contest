#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e9+7;

int main()
{
    string input;
    int n,count=0;
    cin>>input;
    n=input.length();
    int q1,a2,q3;
    for(q1=0;q1<n-2;q1++)
    {
        for(a2=q1+1;a2<n-1;a2++)
        {
            for(q3=a2+1;q3<n;q3++)
            {
                if(input[q1]=='Q'&&input[a2]=='A'&&input[q3]=='Q')
                    count++;
            }
        }
    }
    cout<<count<<endl;
    return 0;
}

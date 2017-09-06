#include <iostream>
#include <cstdio>
using namespace std;

const int maxn=1e9+7;

int main()
{
    int t;
    cin>>t;
    getchar();
    while(t--)
    {
        char a;
        int score=0,otimes=0;
        while((a=getchar())!='\n')
        {
            if(a=='O')
            {
                otimes++;
                score+=otimes;
            }
            else if(a=='X')
            {
                otimes=0;
            }
        }
        cout<<score<<endl;
    }
    return 0;
}

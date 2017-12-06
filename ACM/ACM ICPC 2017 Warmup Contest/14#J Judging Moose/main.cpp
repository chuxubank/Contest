#include <iostream>
using namespace std;
int main()
{
    int l,r;
    while(cin>>l>>r)
    {
        if(l + r == 0)
        {
            puts("Not a moose");
        }
        else if(l == r)
        {
            printf("Even %d\n", l + r);
        }
        else
        {
            printf("Odd %d\n", max(l, r) * 2);
        }
    }
    return 0;
}
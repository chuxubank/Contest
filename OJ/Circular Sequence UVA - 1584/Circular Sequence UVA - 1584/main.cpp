//
//  main.cpp
//  Circular Sequence UVA - 1584
//
//  Created by 褚旭 on 2017/8/23.
//  Copyright © 2017年 Misaka. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;
const int maxn=105;


int myless(const char* s,int p,int q)
{
    int n = (int)strlen(s);
    for(int i=0;i<n;i++)
    {
        if(s[(p+i)%n]!=s[(q+i)%n])
            return s[(p+i)%n]<s[(q+i)%n];
    }
    return 0;
}

int main()
{
    int t;
    char s[maxn];
    cin>>t;
    while(t--)
    {
        cin>>s;
        int ans=0;
        int n=(int)strlen(s);
        for(int i=1;i<n;i++)
        {
            if(myless(s,i,ans))
                ans=i;
        }
        for(int i=0;i<n;i++)
            cout<<s[(i+ans)%n];
        cout<<endl;
    }
    return 0;
}

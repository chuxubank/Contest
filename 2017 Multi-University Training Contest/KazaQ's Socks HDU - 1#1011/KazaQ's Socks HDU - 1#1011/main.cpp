//
//  main.cpp
//  KazaQ's Socks HDU - 1#1011
//
//  Created by 褚旭 on 2017/8/23.
//  Copyright © 2017年 Misaka. All rights reserved.
//

#include <iostream>

using namespace std;

int main()
{
    int t=0;
    long long n,k,ans,qu,re;
    while(cin>>n>>k)
    {
        if(k<=n)
            ans=k;
        else
        {
            k-=n;
            qu=k/(n-1);
            re=k%(n-1);
            if(re==0)
            {
                if(qu&1)//商为奇数
                    ans=n-1;
                else
                    ans=n;
            }
            else
                ans=re;
        }
        cout<<"Case #"<<++t<<": "<<ans<<endl;
    }
    return 0;
}

//
//  main.cpp
//  Add More Zero HDU - 1#1001
//
//  Created by 褚旭 on 2017/8/23.
//  Copyright © 2017年 Misaka. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;
int solve(int m)
{
    int ret = (int)floor(m*log10(2));
    return ret;
}
int main()
{
    int m,t=1;
    while(cin>>m)
    {
        cout<<"Case #"<<t<<": "<<solve(m)<<endl;
        t++;
    }
    return 0;
}

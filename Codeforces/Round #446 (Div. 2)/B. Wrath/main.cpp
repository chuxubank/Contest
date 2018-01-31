//
//  main.cpp
//  Round 446 - B. Wrath
//
//  Created by Misaka on 2017/11/17.
//  Copyright © 2017年 Misaka. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int n,i,x;
vector <int> v;
int main()
{
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        while(!v.empty() and i-v.back()<=x)
            v.pop_back();
        v.push_back(i);
    }
    printf("%d\n",(int)v.size());
    return 0;
}

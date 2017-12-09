//
//  main.cpp
//  Round 446 - A. Greed
//
//  Created by Misaka on 2017/11/17.
//  Copyright © 2017年 Misaka. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn=1e5+7;
int v[maxn],c[maxn];
int main() {
    ios::sync_with_stdio(false);
    int n;
    long long sum=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>v[i];
        sum+=v[i];
    }
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    sort(c,c+n);
    if(sum>c[n-1]+c[n-2])
        cout<<"NO"<<endl;
    else
        cout<<"YES"<<endl;
    return 0;
}

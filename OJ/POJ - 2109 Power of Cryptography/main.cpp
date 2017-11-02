//
//  main.cpp
//  POJ - 2109 Power of Cryptography
//
//  Created by Misaka on 2017/11/2.
//  Copyright © 2017年 Misaka. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    double n,p;
    while(cin>>n>>p)
        cout<<pow(p,1.0/n)<<endl;
    return 0;
}

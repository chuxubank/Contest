//
//  main.cpp
//  Balala Power! HDU - 1#1002
//
//  Created by 褚旭 on 2017/8/23.
//  Copyright © 2017年 Misaka. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <vector>
#include<math.h>
#include <algorithm>
#include<iostream>
#define INF 0x3f3f3f3f
using namespace std;
const long long mod = 1e9+7;
const int MAXSIZE = 100001;
string s[MAXSIZE];
long long var[MAXSIZE];
long long k[MAXSIZE];

struct node
{
    int op,id;
    int var[MAXSIZE];
    bool operator < (const node &a)const
    {
        for(int i=MAXSIZE-1;i>=0;i--)
        {
            if(var[i] != a.var[i])
                return var[i] > a.var[i];
        }
        return 0;
    }
}p[30];

int main()
{
    int n,cns=1;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<26;i++)
        {
            p[i].id = i;
            p[i].op = 0;
            for(int j=0;j<MAXSIZE;j++)
                p[i].var[j]=0;
        }
        
        for(int i=0;i<n;i++)
        {
            cin>>s[i];
            int len = (int)s[i].size();
            if(len > 1)
                p[s[i][0]-'a'].op = 1;
            for(int j=0;j<len;j++)
            {
                int id = s[i][len-j-1] - 'a';
                p[id].var[j]++;
            }
        }
        
        for(int i=0;i<26;i++)
        {
            for(int j=0;j<MAXSIZE;j++)
            {
                p[i].var[j+1] += p[i].var[j]/26;
                p[i].var[j] = p[i].var[j]%26;
            }
        }
        
        sort(p,p+26);
        
        int v = 25;
        for(int i=0;i<26;i++)
            var[p[i].id] = v--;
        
        int pos = 25;
        while(pos && p[pos].op)
        {
            swap(var[p[pos].id],var[p[pos-1].id]);
            pos--;
        }
        
        long long ans = 0,num;
        
        for(int i=0;i<n;i++)
        {
            int len = (int)s[i].size();
            num=0;
            for(int j=0;j<len;j++)
            {
                num = (num*26 + var[s[i][j]-'a'])%mod;
            }
            ans = (ans+num)%mod;
        }
        printf("Case #%d: %lld\n",cns++,ans);
    }
    return 0;
}

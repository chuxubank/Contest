//
//  main.cpp
//  Numbers HDU - 9#1008
//
//  Created by 褚旭 on 2017/8/22.
//  Copyright © 2017年 Misaka. All rights reserved.
//

//#include <cstdio>
//#include <cstring>
//int input[125255],compare[125255],a[125255],C2[125255];
//int main()
//{
//    C2[2]=1;
//    for(int i=3;i<125255;i++)
//        C2[i]=C2[i-1]+i-1;
//    int m;
//    while(scanf("%d",&m)==1)
//    {
//        memset(compare,0,sizeof(compare));
//        memset(a, 0, sizeof(a));
//        int alength=0;
//        for(int i=1;i<=m;i++)
//            scanf("%d",&input[i]);


//        int l=3,flag=0;
//        for(int j=1;j<alength;j++)
//        {
//            for(int k=j+1;k<=alength;k++)
//            {
//                if(l<=m)
//                {
//                    if(input[l+1]==input[l])
//                    {
//                        if(a[j]+a[k]==input[l])
//                        {
//                            l++;
//                            alength++;
//                        }
//                    }
//                    else
//                    {
//                        j=1;
//                    }
//                }
//            }
//        }

//        int i=1,j=1,k=1;
//        for(;i<=m;i++)
//        {
//            for(;j<alength;j++)
//            {
//                for(;k<=alength;k++)
//                {
//                    if(input[i]!=input[i-1])
//                    {
//                        j=1;
//                    }
//                    if(a[j]+a[k]==input[i])
//                    {
//                        continue;
//                    }
//                    if(input[j]+input[k]>input[i])
//                    {
//                        a[++alength]=input[i];
//                        if(C2[alength]+alength==m)
//                            break;
//                    }
//
//                }
//            }
//        }
//        for(int i=1;i<=alength;i++)
//        {
//            printf("%d",a[i]);
//        }
//    }
//
//    return 0;
//}

//#include <iostream>
//#include <algorithm>
//using namespace std;
//int output[99999999],alen,len;
//int main()
//{
//    for(int i=2;i<=100;i++)
//    {
//        scanf("%d",&alen);
//        len=alen;
//        for(int j=1;j<=alen;j++)
//        {
//            scanf("%d",&output[j]);
//        }
//        for(int i1=1;i1<=alen;i1++)
//        {
//            for(int i2=i1+1;i2<=alen;i2++)
//            {
//                output[++len]=output[i1]+output[i2];
//            }
//        }
//        sort(output+1,output+len);
//        for(int i=1;i<=len;i++)
//            cout<<output[i]<<' ';
//        cout<<endl;
//    }
//}

#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAX=100;

int A[MAX];
int B[MAX];
bool vis[MAX];

int main(void)
{
    int m;
    while(~scanf("%d",&m))
    {
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=m;i++)
            scanf("%d",&A[i]);
        int n=(-1+sqrt(1+8*m))/2.0;
        vis[1]=true;
        B[1]=A[1];
        int cnt=1;
        for(int j=2;j<=m;j++)
        {
            if(vis[j]==true)
                continue;
            int idx=(int)(lower_bound(A+1,A+m+1,A[1]+A[j])-A);
            //很多值相同的情况
            int idx2=(int)(upper_bound(A+1,A+m+1,A[1]+A[j])-A);
            int num=idx2-idx;
            for(int k=0;k<num;k++)
            {
                if(A[k+idx]==A[1]+A[j] && vis[k+idx]==false)
                {
                    vis[j]=true;
                    vis[k+idx]=true;
                    B[++cnt]=A[j];
                    if(cnt==n)
                        break;
                    for(int k=2;k<cnt-1;k++)
                    {
                        int idx=(int)(lower_bound(A+1,A+m+1,B[k]+B[cnt-1])-A);
                        int idx2=(int)(upper_bound(A+1,A+m+1,B[k]+B[cnt-1])-A);
                        int num=idx2-idx;
                        for(int k=0;k<num;k++)
                        {
                            if(A[k+idx]==B[k]+B[cnt-1] && vis[k+idx]==false)
                            {
                                vis[k+idx]=true;
                                break;
                            }
                        }
                    }
                    break;
                }
            }
        }
        for(int i=1;i<=n;i++)
            printf("%d%c",B[i],i==n?'\n':' ');
    }
    return 0;
}

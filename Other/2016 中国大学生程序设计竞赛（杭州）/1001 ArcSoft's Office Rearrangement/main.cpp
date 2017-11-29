//
// main.cpp
// HDU - 5933 ArcSoft's Office Rearrangement
//
// Created by chuxu on 2017/10/14 下午 3:00:13.
// Copyright 2017年 Misaka. All rights reserved.
//
#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1e5 + 7;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(false); //数据输入大的时候取消同步加快速度
    int t, c = 0, n, k;
    ll a[maxn], ans, avg, cur, sum;
    cin >> t;
    while (t--)
    {
        ans = 0;
        cur = 0;
        sum = 0;
        cin >> n >> k;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }
        cout << "Case #" << ++c;
        if (sum % k != 0)
        {
            cout << ": -1" << endl;
            continue;
        }
        avg = sum / k;
        for (int i = 0; i < n; i++)
        {
            cur += a[i];
            while (cur > avg)
            {
                ans++;
                cur -= avg;
            }
            if (cur == avg)
                cur = 0;
            else
                ans++;
        }
        cout << ": " << ans << endl;
    }
    return 0;
}

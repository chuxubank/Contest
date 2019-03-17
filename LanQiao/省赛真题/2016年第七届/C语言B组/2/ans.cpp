#include <bits/stdc++.h>
using namespace std;

int main()
{
    for (int i = 1; i < 100; i++)
    {
        if ((236 - i * (i - 1) / 2) % i == 0)
            cout << (236 - i * (i - 1) / 2) / i << endl;
    }
    return 0;
}

// 26
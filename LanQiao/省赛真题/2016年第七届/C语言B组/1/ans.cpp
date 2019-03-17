#include <bits/stdc++.h>
using namespace std;

int main()
{
    int adder = 1;
    int count = 0, sum = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        count += adder;
        sum += count;
        adder++;
    }
    cout << sum << endl;
    return 0;
}

// 171700
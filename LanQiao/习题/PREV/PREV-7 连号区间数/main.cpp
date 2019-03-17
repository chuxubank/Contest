#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int data[n];
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> data[i];
    }
    for (int i = 0; i < n; i++)
    {
        int min = data[i];
        int max = data[i];
        for (int j = i; j < n; j++)
        {
            if (data[j] < min)
                min = data[j];
            if (data[j] > max)
                max = data[j];
            if (i == j)
                count++;
            else
            {
                if (max - min == j - i)
                    count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}

// 连号判断
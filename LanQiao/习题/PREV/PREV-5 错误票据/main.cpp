#include <bits/stdc++.h>
using namespace std;
const int maxn = 10000;

int main()
{
    int n, data[maxn], index = 0;
    cin >> n;
    getchar();
    for (int i = 0; i < n; i++)
    {
        string s;
        getline(cin, s);
        stringstream ss(s);
        while (ss >> data[index])
            index++;
    }
    sort(data, data + index);
    int a, b;
    for (int i = 1; i < index; i++)
    {
        if (data[i] == data[i - 1] + 2)
        {
            a = data[i] - 1;
        }
        if (data[i] == data[i - 1])
            b = data[i];
    }
    printf("%d %d\n", a, b);
    return 0;
}
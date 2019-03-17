#include <bits/stdc++.h>
using namespace std;

int main()
{
    string source, target;
    cin >> source >> target;
    vector<int> diff;
    int sum = 0;
    for (int i = 0; i < source.length(); i++)
    {
        if (source[i] != target[i])
            diff.push_back(i);
    }
    for (int i = 0; i < diff.size(); i += 2)
    {
        sum += diff[i + 1] - diff[i];
    }
    cout << sum << endl;
    return 0;
}

// 找规律
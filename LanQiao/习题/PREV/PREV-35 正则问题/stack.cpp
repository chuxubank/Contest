#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<char> s;
    string input;
    cin >> input;
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == ')')
        {
            int num = 0, maxnum = 0;
            while (s.top() != '(')
            {
                if (s.top() == '|')
                {
                    maxnum = max(num, maxnum);
                    num = 0;
                }
                else
                    num++;
                s.pop();
            }
            s.pop();
            maxnum = max(num, maxnum);
            for (int j = 0; j < maxnum; j++)
                s.push('x');
        }
        else
            s.push(input[i]);
    }
    int num = 0, maxnum = 0;
    while (!s.empty())
    {
        if (s.top() == '|')
        {
            maxnum = max(num, maxnum);
            num = 0;
        }
        else
            num++;
        s.pop();
    }
    maxnum = max(num, maxnum);
    cout << maxnum;
    return 0;
}

// 75分 不知道最后两个用例是啥...
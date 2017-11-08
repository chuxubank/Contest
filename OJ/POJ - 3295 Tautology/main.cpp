#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack<int> a;
string input;
int p,q,r,s,t;

void cal()
{
    int len=input.length();
    int w,x;
    for(int i=len-1;i>=0;i--)
    {
        switch(input[i])
        {
            case 'p':
                a.push(p);
                break;
            case 'q':
                a.push(q);
                break;
            case 'r':
                a.push(r);
                break;
            case 's':
                a.push(s);
                break;
            case 't':
                a.push(t);
                break;
            case 'K':
                w=a.top();
                a.pop();
                x=a.top();
                a.pop();
                a.push(w && x);
                break;
            case 'A':
                w=a.top();
                a.pop();
                x=a.top();
                a.pop();
                a.push(w || x);
                break;
            case 'N':
                w=a.top();
                a.pop();
                a.push(!w);
                break;
            case 'C':
                w=a.top();
                a.pop();
                x=a.top();
                a.pop();
                a.push(!w || x);
                break;
            case 'E':
                w=a.top();
                a.pop();
                x=a.top();
                a.pop();
                a.push(w==x);
                break;
        }

    }
}

bool judge()
{
    for(p=0;p<2;p++)
        for(q=0;q<2;q++)
            for(r=0;r<2;r++)
                for(s=0;s<2;s++)
                    for(t=0;t<2;t++)
                    {
                        cal();
                        if(a.top()==0)
                            return 0;
                    }
    return 1;
}

int main()
{
    while(cin>>input && input!="0")
    {
        if(judge())
            cout<<"tautology"<<endl;
        else
            cout<<"not"<<endl;
    }
    return 0;
}

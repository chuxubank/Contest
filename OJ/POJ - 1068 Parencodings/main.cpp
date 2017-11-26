#include <iostream>
#include <string>
using namespace std;

const int maxn = 1e9+7;

int main()
{
    string p;
	int t,n,a[25]={0};
	cin>>t;
	while(t--)
    {
        string s;
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<a[i]-a[i-1];j++)
                s.push_back('(');
            s.push_back(')');
        }
        int j,pair,ans;
        for(int i=0;i<s.length();i++)
        {
            ans=0;
            pair=1;
            if(s[i]==')')
            {
                j=i-1;
                while(pair && j>=0)
                {
                    if(s[j]=='(')
                    {
                        pair--;
                        ans++;
                    }
                    else
                        pair++;
                    j--;
                }
                cout<<ans<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}

#include<iostream>  
#include<cstdio>  
#include<cstring>  
#include<algorithm>  
#include<map>  
using namespace std;  
char s[300];  
map<char,int> o,a;  
map<char,string> m;  
int main()  
{  
    cin>>s;  
    int i,j,n;  
    for(i=0;s[i]!=0;++i)  
        if(s[i]==':') o[s[i-1]]++;  
        else o[s[i]]++;  
    cin>>n;  
    getchar();  
    for(i=1;i<=n;++i)  
    {  
        a.clear();  
        m.clear();  
        gets(s);  
        printf("Case %d:",i);  
        for(j=1;s[j]!=' '&&s[j]!=0;++j);  
        if(s[j]==0) {puts("");continue;}  
        while(s[j]!=0)  
        {  
            if(s[++j]!='-') break;  
            if(o[s[++j]]==0) break;  
            if(o[s[j]]==1)  
            {  
                if(s[j+1]==' '||s[j+1]==0) a[s[j++]]=1;  
                else break;  
            }  
            else if(s[j+1]==' '&&s[j+2]!=0)  
            {  
                a[s[j]]=2;  
                string tmp="";  
                int tm=j;  
                for(j=j+2;s[j]!=0&&s[j]!=' ';++j) tmp+=s[j];  
                m[s[tm]]=tmp;  
            }  
            else break;  
        }  
        map<char,int>::iterator it;  
        for(it=a.begin();it!=a.end();++it)  
        {  
            cout<<" -"<<it->first;  
            if(it->second==2) cout<<' '<<m[it->first];  
        }  
        puts("");  
    }  
    return 0;  
}  
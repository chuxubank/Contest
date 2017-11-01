#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn=1007;
struct Island
{
    int x,y;
} island[maxn];
struct Segment
{
    double x1,x2;
} segment[maxn];

bool comp(struct Segment s1,struct Segment s2)
{
    if(s1.x2==s2.x2)
        return s1.x1<s2.x1;
    else
        return s1.x2<s2.x2;
}

int main()
{
    ios::sync_with_stdio(false);
    int n=-1,d=-1,ca=0;
    while(n!=0 && d!=0)
    {
        cin>>n>>d;
        for(int i=0; i<n; i++)
        {
            cin>>island[i].x;
            cin>>island[i].y;
        }
        int flag=1,cnt=0;
        for(int i=0;i<n;i++)
        {
            if(island[i].y>d)
                flag=0;
        }
        if(flag==0)
            cnt=-1;
        else
        {
            for(int i=0; i<n; i++)
            {
                segment[i].x1=island[i].x-sqrt(d*d-island[i].y*island[i].y+0.0);
                segment[i].x2=island[i].x+sqrt(d*d-island[i].y*island[i].y+0.0);
            }
            sort(segment,segment+n,comp);

            double cur_x2=-1e9-7;
            for(int i=0; i<n; i++)
            {
                if(segment[i].x1>cur_x2)
                {
                    cur_x2=segment[i].x2;
                    cnt++;
                }
            }
        }
        if(n!=0 && d!=0)
            cout<<"Case "<<++ca<<": "<<cnt<<endl;
    }
    return 0;
}

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

const int MAX = 1e6 + 7;
const int mod = 1e9 + 7;

void getNext(char* p);
long long KMP(char* s, char* p);
int KMPnext[MAX];

char p1[MAX];
char p2[MAX];

int main(void)
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		long long ans = 0;
		scanf("%s%s", p1, p2);
		getNext(p2);
		int len = (int)strlen(p2);
		for (int i = 0; i<len; i++)
			ans = (ans + ((len - i)*KMP(p1, &p2[i]))%mod) % mod;
		printf("%lld\n", ans);
	}
	return 0;
}

void getNext(char* p)
{
	int len = (int)strlen(p);
	KMPnext[0] = -1;
	int k = -1;
	int j = 0;
	while (j<len)
	{
		if (k == -1 || p[j] == p[k])
		{
			k++;
			j++;
			KMPnext[j] = k;
		}
		else
			k = KMPnext[k];
	}
}

long long KMP(char* s, char* t)
{
	int i = 0, j = 0;
	long long ans = 0;
	int lens = (int)strlen(s);
	int lent = (int)strlen(t);
	while (i<lens)
	{
		if (s[i] == t[j])
		{
			++i, ++j;
			if (j == lent)
				++ans;
		}
		else if (KMPnext[j] == -1)
			++i;
		else
			j = KMPnext[j];
	}
	return ans;
}


#include<iostream>
using namespace std;
int res[10000];
int solve(long long L,int l,int r)
{
    int result;
    int i;
            for(i = l; i <= r; i ++)
            {
                int t = -1,j,num = L ;
                r = 1;
                do
                {

                    res[++ t] = num % i;
                }
                while((num /= i) != 0);

                for(j = 0; j < (t + 1) / 2; j ++)
                {
                    if(res[j] != res[t - j])
                    {
                        r = 0;
                        break;
                    }
                }

                if(r)
                    break;
            }
            if(r)
                result = i;
            else
                result = 1;

    return result;
}

int main()
{
   int T,kase=0;
   cin>>T;
   long long L,R;
   int l,r;
   while(T--)
   {
       cin>>L>>R>>l>>r;
       int re=0;
       for(long long i=L;i<L-R+1;i++)
       {
           re+=solve(i,l,r);
       }
       cout<<"Case #"<<++kase<<": "<<re<<endl;
   }
}
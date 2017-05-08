#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

ll mod= 1000000007;

//cout<<fixed<<setprecision(6)<<ans<<"\n";

#define frmlty     int test_case;cin>>test_case;while(test_case--)

#define vi        vector<int>
#define vs        vector<string>
#define vll       vector<ll>
#define pii       pair<int,int>

#define msi       map<string,int>
#define msit      map<string,int>::iterator
#define pb        push_back
#define mp        make_pair

#define loop(i,a,b)      for(int i=a;i<b;i++)
#define rloop(i,a,b)     for(int i=b-1;i>=a;i--)

#define gcd(a,b)  __gcd(a,b)
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))

#define le(x) scanf("%d",&x);
#define le2(x,y) scanf("%d%d",&x,&y);
#define lell(x) scanf("%lld",&x);
#define le2ll(x,y) scanf("%lld%lld",&x,&y);

#define F first
#define S second

int hta[26];
int htb[26];

int main()
{
    int dc,ic,rc,n1,n2;

    string s1,s2;
    frmlty
    {
        memset(hta,0,sizeof hta);
        memset(htb,0,sizeof htb);
        cin>>s1>>s2;
        le2(dc,ic);
        le(rc);
        n1=s1.length();
        n2=s2.length();

        loop(i,0,n1)
        hta[s1[i]-'a']++;
        loop(i,0,n2)
        htb[s2[i]-'a']++;

        int ans=0;
        int tn=0;
        if(n1<n2)
        {
            ans=ans+ic*(n2-n1);
            loop(i,0,26)
            {
                if (hta[i]>htb[i])//jo bhi first string me extra hai that need to replace
                    tn=tn+hta[i]-htb[i];
            }
            ans=ans+tn*((dc+ic) < rc ? (dc+ic) :rc );
        }
        else if(n1>=n2)
        {

            ans=ans+dc*(n1-n2);
            loop(i,0,26)
            {
                if(htb[i]>hta[i])//jo bhi first string me kami hai we need to fill it
                    tn=tn+htb[i]-hta[i];
            }
            ans=ans+tn*((dc+ic )< rc ? (dc+ic) :rc );
        }
        printf("%d\n",ans);
    }
    return 0;
}



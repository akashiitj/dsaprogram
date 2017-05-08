#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

ll mod= 1000000007;

#define fast      ios_base::sync_with_stdio(false);
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
#define lell(x) scanf(" %I64d",&x);
#define le2ll(x,y) scanf(" %I64d%I64d",&x,&y);

#define F first;
#define S second;

//cout<<fixed<<setprecision(6)<<ans<<"\n";

int mark[100001];

int main()
{
    int n,d;
    le2(n,d);
    string s1,s2;
    int sr=n-d;
    cin>>s1>>s2;

    int same=0;
    loop(i,0,n)
    {
        if(s1[i]==s2[i])
            same++;

    }
    int dif=n-same;

    if((same+(dif/2))<sr)
    {
        cout<<"-1";
        return 0;
    }
    string ans;
    //ans.resize(n);
    loop(i,0,n)
    {
        if(s1[i]==s2[i]&&sr>0)
        {
            mark[i]=1;
            ans=ans+s1[i];
            sr--;
        }
    }
    int flag=0;

    loop(i,0,n)
    {
        if(s1[i]!=s2[i]&&sr>0)
        {
            if(sr>0&&flag==0)
            {
                flag++;
                ans=ans+s1[i];
            }
            else if(sr>0&&flag==1)
            {
                flag++;
                ans=ans+s2[i];
                sr--;
            }
        }
        }
        else if(sr<=0&&mark[i]==0)
        {

            if(s1[i]!='a'&&s2[i]!='a')
                ans=ans+'a';
            else if(s1[i]!='b'&&s2[i]!='b')
                ans=ans+'b';
            else if(s1[i]!='c'&&s2[i]!='c')
                ans=ans+'c';
        }
    }


    cout<<ans<<"\n";

    return 0;
}




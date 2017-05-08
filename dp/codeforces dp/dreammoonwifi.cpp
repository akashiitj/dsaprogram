
#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

ll mod= 1000000007;


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


#define F first
#define S second

int main()
{
    string s1,s;
    cin>>s1>>s;
    int n=s.length();
    int dp[21][2]= {};
    dp[10][0]=1;
    int cur=1,pre=0;
    int rp=10;
    loop(i,0,n)
    {   if(s1[i]=='+')rp++;
        else rp--;
        if(s[i]=='+'||s[i]=='-')
        {
            loop(j,0,21)
            {
                if(dp[j][pre]!=0)
                {
                    if(s[i]=='+')
                        dp[j+1][cur]+=dp[j][pre];
                    else
                        dp[j-1][cur]+=dp[j][pre];
                }

            }
        }
        else
            loop(j,0,21)
        {
            if(dp[j][pre]!=0)
            {

                dp[j+1][cur]+=dp[j][pre];

                dp[j-1][cur]+=dp[j][pre];
            }

        }
        swap(pre,cur);
        loop(i,0,21)
        dp[i][cur]=0;

    }

    double hv=0.0;
    loop(i,0,21)
    hv=hv+dp[i][pre];
    cout<<fixed<<setprecision(12);
    cout<<(double)dp[rp][pre]/hv<<"\n";

    return 0;
}


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

#define loop(i,a,b)      for(ll i=a;i<b;i++)
#define rloop(i,a,b)     for(int i=b-1;i>=a;i--)

#define gcd(a,b)  __gcd(a,b)
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))

#define le(x) scanf("%d",&x);
#define le2(x,y) scanf("%d%d",&x,&y);
#define lell(x) scanf("%lld",&x);
#define le2ll(x,y) scanf("%lld%lld",&x,&y);


int main()
{
    string s;
    int sum,n;
    int a[10],ans=0;
    frmlty
    {
        sum=0;
//        loop(i,0,10)
//        a[i]=0;
        cin>>s;
        n=s.length();
        loop(i,0,n)
        {
            sum=sum+s[i]-'0';
            // a[s[i]-'0']++;
        }
        //  cout<<sum<<endl;
        ans=0;
        if(n==1)
        {
            while(true)
            {

                if((((sum-ans)%9)==0)||(((sum+ans)%9)==0))
                    break;
                ans++;
            }
            cout<<ans<<"\n";
        }
        else {
            if(sum>=9)
            {
                while(true)
                {
                    if((((sum-ans)%9)==0)||(((sum+ans)%9)==0))
                        break;
                    ans++;
                }
                cout<<ans<<"\n";
            }
            else {
                ans=9-sum;
                cout<<ans<<"\n";
            }
        }
    }
    return 0;
}

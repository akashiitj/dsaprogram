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
#define ifend 10
#define precoun 11
using namespace std;
int trie[120001][12];
 int cnt=1;
int insert_trie(string s)
{

    int cur=0;
    int k=0;
    while(trie[cur][s[k]-'0']!=0)
    {
        cur = trie[cur][s[k]-'0'];
        trie[cur][precoun]+=1;
        k++;
        if(trie[cur][ifend]!=0)return 0;
        if(k>=s.size())break;
    }
    if(k==s.size())
    {
        trie[cur][ifend]+=1;
        return 0;

    }
    else
    {
        while(k<s.size())
        {
            trie[cur][s[k]-'0']=cnt;
            cur = cnt;
            trie[cur][precoun]+=1;
            k++;
            cnt++;
        }
        trie[cur][ifend]+=1;
    }
    return 1;
}

int main()
{
    string s,s1;
    int n,x;
    frmlty
    {
        cnt=1;
        le(n);
        x=1;
        memset(trie,0,sizeof(trie));
        loop(i,0,n)
        {


            cin>>s;
            if(x==1)
            {
               // cin>>s1;
                x=insert_trie(s);

            }
        }
        if(x==1)
            printf("YES\n");
        else
            printf("NO\n");




    }
    return 0;
    }

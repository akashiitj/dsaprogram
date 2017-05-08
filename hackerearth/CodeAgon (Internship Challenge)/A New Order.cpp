#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

ll mod= 1000000007;
string ans;

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

vi g[26];
int indegree[26];
int indegreec[26];
int vis[26];
void ts()
{
    char c;
    while(true)
    {
        int flag=0;
        loop(i,0,26)
        {
            if(indegree[i]==0&&vis[i]==1)//indgree means it is of highest priority in present
            {
                flag=1;
                vis[i]=0;
                c='a'+i;
                ans=ans+c;
                loop(j,0,g[i].size())
                {
                    indegreec[g[i][j]]--;
                }
            }
        }
        sort(ans.begin(),ans.end());
        cout<<ans<<"\n";
        ans="";
        loop(i,0,26)
        indegree[i]=indegreec[i];

        if(flag==0)
            return;
    }
}

int main()
{
    int n;
    le(n);
    string s[n];
    loop(i,0,n)
    {
        cin>>s[i];
        loop(k1,0,s[i].size())
        vis[s[i][k1]-'a']=-1;
    }
    loop(i,0,n)
    {
        loop(j,i+1,n)
        {
            int k=0;
            while(k<miN(s[i].length(),s[j].length())&&s[i][k]==s[j][k])
                k++;
            if(k<miN(s[i].length(),s[j].length()))
            {
                int flag=0;
                loop(k1,0,g[s[i][k]-'a'].size())//checking if edge already exist
                if(g[s[i][k]-'a'][k1]==s[j][k]-'a')flag=1;

                if(flag==0)
                {
                    indegree[s[j][k]-'a']++;
                    g[s[i][k]-'a'].pb(s[j][k]-'a');//making edge towards low priority character in dictionary
                    vis[s[i][k]-'a']=1;// they are used
                    vis[s[j][k]-'a']=1;
                }
            }
        }
    }
    ans="";
    loop(i,0,26)
    if(vis[i]==-1)
        ans=ans+(char)(i+'a');//nice condition read q carefully for this
    loop(i,0,26)
    indegreec[i]=indegree[i];
    ts();
    return 0;
}



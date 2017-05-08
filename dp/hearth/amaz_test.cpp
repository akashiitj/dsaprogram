
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
#define lell(x) scanf("%lld",&x);
#define le2ll(x,y) scanf("%lld%lld",&x,&y);

#define F first
#define S second

int dp[101][100001];
int n,x,hv;
int a[101];

void f(int sum)
{
    loop(i,1,sum+1)
    dp[0][i]=0;

    loop(i,0,n+1)
    dp[i][0]=1;

    loop(i,1,n+1)
    {
        loop(j,1,sum+1)
        {
            dp[i][j]=dp[i-1][j];
            if(a[i]<=j)dp[i][j]=dp[i][j]|dp[i-1][j-a[i]];
         //   cout<<dp[i][j]<<" ";
        }

       // cout<<"\n";
    }

}


int main()
{   int ts;
    frmlty
    {

        le2(n,x);

        ts=0;
        loop(i,0,n)
        {
            le(a[i+1]);
            ts=ts+a[i+1];
        }

        if((ts/2)>x)
        {
            printf("NO\n");
            continue;
        }
        else{
            f(x);
            int flag=0;
            loop(i,ts/2,x+1)//you have x time total
            {
                if(dp[n][i]==1)
                 {
                    flag=1;
                    printf("YES\n");
                    break;
                 }
            }
            if(flag==0)printf("NO\n");

        }
    }
    return 0;
}

/*
int main()
{
    int a,b;
    frmlty
    {
        int n,x,hv;
        le2(n,x);
        priority_queue<int > pq;
        //pq.clear();
        loop(i,0,n)
        {
            le(hv);
            pq.push(hv);
        }
        pq.push(0);
        int maxtime=0,v1,v2;
        while(pq.top()!=0)
        {
            v1=pq.top();
            pq.pop();

            v2=pq.top();
            pq.pop();
            if(v2==0)
            {
                maxtime+=v1;
                break;
            }
            maxtime=maxtime+v2;
            pq.push(v1-v2);
        }
        if(maxtime<=x)
                printf("YES\n");
            else   printf("NO\n");

    }
    return 0;
}
*/

#include<cstdio>
#include<iomanip>
#include<iostream>
#include<vector>
#include<cfloat>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

int m,p,a,n,pr[16],ar[16];
//vector< pair< int,int > > v[16];
int discount[17][17];
double dp[1<<16];

int readint()
{
    int n=0;
    char c=getchar_unlocked();
    while(c<'0' || c>'9')
        c=getchar_unlocked();
    while(c>='0' && c<='9')
    {
        n=(n<<3) + (n<<1) + c-'0';
        c=getchar_unlocked();
    }
    return n;
}

double mini(double a,double b)
{
    return ((a)<(b) ? (a):(b));
}

double countbits(ll n)
{
    double cnt=0.0;
    for(int i=0; i<m; i++)
        if(n&(1<<i))
            cnt+=ar[i+1];
    return cnt;
}


double solve(ll s)
{
    if(dp[s]!=-1)
        return dp[s];
    if(s==0)
        return (dp[s]=0.0);
    dp[s]=DBL_MAX;
    for(int i=1; i<=m; i++)
    {
        if(!(s&(1<<(i-1))))
            continue;
        double disc=1;
        for(int j=1; j<=m; j++)
        {
            if(i!=j && s&(1<<(j-1)))
            {
                disc*=(1.0-0.01*discount[j][i]);
            }
        }
        double cnt=countbits(s);
        dp[s]=mini(dp[s],(solve(s^(1<<(i-1)))*(cnt-ar[i])+(pr[i]*disc))/cnt);
    }
    //cout<<s<<" "<<dp[s]<<endl;
    return dp[s];
}


int main()
{
    while(true)
    {
        scanf("%d",&m);
        //m=readint();
        if(m==0)
            break;
        //for(int i=0;i<=m;i++)
        //  v[i].clear();
        for(int i=1; i<=m; i++)
            for(int j=1; j<=m; j++)
                discount[i][j]=0;
        for(int i=1; i<=m; i++)
        {
            scanf("%d%d%d",&pr[i],&ar[i],&n);
            //pr[i]=readint();
            //ar[i]=readint();
            //n=readint();
            for(int j=0; j<n; j++)
            {
                int x,y;
                scanf("%d%d",&x,&y);
                //x=readint();
                //y=readint();
                //v[i].pb(mp(x,y));
                discount[i][x]=y;
            }
        }
        for(int i=0; i<=(1<<m); i++)
            dp[i]=-1;
        double ans=solve((1<<m)-1);
        for(int i=1; i<=(1<<m)-1; i++)
            ans=mini(ans,solve(i));

        printf("%.4lf\n",ans);

        /* dp[0]=0.0;
         double fans=100000000.0;
         for(int s=1;s<(1<<m);s++)
         {   double ans=DBL_MAX;
             dp[s]=DBL_MAX;
             for(int i=1;i<=m;i++)
             {
                 if(s&(1<<(i-1)))
                 {
                     double disc=1;
                     for(int j=1;j<=m;j++)
                     {
                         if(i!=j && s&(1<<(j-1)))
                             disc*=(1.0-0.01*discount[j][i]);
                     }
                     ll cnt=countbits(s);
                     ans=mini(ans,(dp[s^(1<<(i-1))]*(cnt-ar[i])+(pr[i]*disc))/cnt);
                 }
             }
             dp[s]=ans;
             fans=mini(fans,dp[s]);
         }

         printf("%.4lf\n",fans);*/
    }
    return 0;
}

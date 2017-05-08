#include<bits/stdc++.h>
using namespace std;

#define loop(i,a,b)      for(int i=a;i<b;i++)

int a[51]={ 0,70, 55, 13, 2, 99, 2, 80, 80, 80, 80, 100, 19, 7, 5, 5, 5, 1000, 32, 32 };
int dp[51];
int bc[51];

int f(int i)
{
    if(dp[i]!=-1)return dp[i];
    if(i==1)
    {
        bc[1]=0;
        dp[1]=1;
        return 1;
    }

    int ans=1;
    bc[i]=0;

    loop(x,1,i)
    {
        if(bc[x]==0)
        {
            if(a[i]!=a[x])
            {
                int tv=f(x)+1;
                if(tv>ans)
                {
                    ans=tv;
                    bc[i]=a[i]-a[x];
                }
            }
        }

        if(((a[i]-a[x])*bc[x])<0)
        {
            int tv=f(x)+1;
            if(tv>ans)
            {
                ans=tv;
                bc[i]=a[i]-a[x];
            }
        }
    }
    dp[i]=ans;
    return ans;
}

int f1(int i)//this looks smarter than previous one
{
    if(dp[i]!=-1)return dp[i];
    if(a[i]==0)return 0;
    dp[i]=1;
    loop(j,1,i)
    {
        if(a[j]*a[i]<0)dp[i]=max(dp[i],f(j)+1);
        else f(j);
    }
    return dp[i];
}

main()
{
    int n;
    cin>>n;
    loop(i,1,n+1)
    {

        //cin>>a[i];
        dp[i]=-1;
    }
    int ans=1;
    int ansi=1;
    f1(n);
    loop(i,1,n+1)
    {
        ans=max(ans,dp[i]);
    }
    cout<<ans<<endl;

}

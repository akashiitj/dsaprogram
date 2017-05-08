#include<bits/stdc++.h>
using namespace std;

#define loop(i,a,b) for(int i = a; i < b; i++)

int dp[1000][1000]= {};
int dpoo[1000][1000];
int dpno[100][100]= {};
int adp[1000];

int c[1000];

int inf=1000000;

int countways(int s,int n)//number of ways to obtain sum s using coin upto n
{
    if(dpno[s][n]!=-1)return dpno[s][n];
    if(s==0)return 1;
    if(s<0)return 0;
    if(n<=0)return 0;
    dpno[s][n]=countways(s,n-1)+countways(s-c[n],n);
    return dpno[s][n];
}

int countbp(int s,int n)
{
    loop(i,0,n+1)
    dpno[0][i]=1;

    loop(i,1,s+1)
    dpno[i][0]=0;

    loop(i,1,s+1)
    {
        loop(j,1,n+1)
        {
            dpno[i][j]=dpno[i][j-1];
            if(c[j]<=i)dpno[i][j]=dpno[i][j]+dpno[i-c[j]][j];
//            cout<<dpno[i][j]<<" ";
        }
        //cout<<"\n";
    }
    cout<<dpno[s][n]<<"\n";

}

int foo(int s,int n)//minimum number of  coin upto n  needed to make sum s such that a coin can be used only once
{
    if(n==0)return inf;
    if(s==0)return 0;
    if(dpoo[s][n]!=-1)return dpoo[s][n];
    int ans1=foo(s,n-1);
    int ans2=inf;
    if(s-c[n]>=0)ans2=foo(s-c[n],n-1)+1;
    dpoo[s][n]=min(ans1,ans2);
    return dpoo[s][n];

}



int f(int s,int n)//minimum number of  coin upto n  needed to make sum s such that a coin can be used many times
{
    if(n==0)return inf;
    if(s==0)return 0;
    if(dp[s][n]!=-1)return dp[s][n];
    int ans1=f(s,n-1);
    int ans2=inf;
    if(s-c[n]>=0)ans2=f(s-c[n],n)+1;
    dp[s][n]=min(ans1,ans2);
    return dp[s][n];

}


int f2(int s,int n)//space efficient algo because we manually calculate the for loop
{
    if(s==0)return 0;
    if(adp[s]!=-1)return adp[s];
    int ans=inf;
    loop(i,1,n+1)
    {
        if(s>=c[i])ans=min(ans,f2(s-c[i],n)+1);
    }
    adp[s]=ans;
    return ans;
}



main()
{
    int n;
    cin>>n;
    loop(i,1,n+1)
    cin>>c[i];

    int s;
    cin>>s;

    loop(i,0,s+1)
    loop(j,0,n+1)
    {
        dpoo[i][j]=-1;
        dp[i][j]=-1;
        dpno[i][j]=-1;
    }
    loop(i,1,s+1)
    adp[i]=-1;
    // cout<<countways(s,n)<<endl;
    countbp(s,n);
//    cout<<f(s,n)<<" ";
//    cout<<f2(s,n)<<endl;
//    cout<<foo(s,n);
}

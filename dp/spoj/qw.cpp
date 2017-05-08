#include<bits/stdc++.h>

using namespace std;

#define ll long long

#define loop(i,k,n)    for(int i=k;i<n;i++)
#define loops(i,k,n)    for(int i=k;i<=n;i++)

#define begin int t;cin>>t;while(t--)



#define maxi(a,b)                     ( (a) > (b) ? (a) : (b))
#define mini(a,b)                     ( (a) < (b) ? (a) : (b))

ll w[1000001];
ll v[1000001];
ll dp[100][100];
int n1;
int s;

ll knapsack1()
{

    loop(i,0,101)
    {
        dp[i][0]=0;
        dp[0][i]=0;
    }
    cout<<n1<<" nn\n";

    loop(i,1,n1+1)
    {
        cout<<"1"<<endl;
        loops(j,1,s)
        {
            if((j-w[i])>=0) dp[i][j]=maxi(dp[i-1][j],dp[i][j-w[i]]+v[i]);
            else dp[i][j]=dp[i-1][j];
            cout<<"i "<<"j "<<dp[i][j]<<endl;;
        }
    }
    return(dp[n1][s]);
}


int main()
{
    //int n1;
    cin>>s>>n1;
    loops(i,1,n1)
    {
        // cout<<"jrllo"<<endl;
        cin>>w[i]>>v[i];
    }

    cout<<n1<<" nn\n";
    ll ans= knapsack1();
    cout<<ans;
}

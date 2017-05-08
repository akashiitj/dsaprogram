#include<bits/stdc++.h>
using namespace std;

#define loop(i,a,b) for(ll i=a;i<b;i++)
#define ll long long

ll a[100001];

ll dp[6][100001];

void seive()
{  // cout<<"q1"<<endl;
    a[0]=0;
    a[1]=0;

    loop(i,2,100001)
    {
        if(a[i]==0)
        {
            a[i]=1;
            for(ll j=(2*i);j<=100000;j=j+i)
           {
               a[j]++;

           }
         //  cout<<"q2"<<endl;
        }
    }
}

main()
{
    seive();
    //cout<<" q"<<endl;

    loop(i,2,100001)
    {
        loop(j,1,6)
        {
            dp[j][i]=dp[j][i-1]+(j==a[i]);
        }
    }
    ll t,a,b,k;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>k;
        cout<<dp[k][b]-dp[k][a-1]<<endl;
    }

}

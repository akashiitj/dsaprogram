#include<bits/stdc++.h>
using namespace std;

int n , m , B , M , ans , a[501] , dp[501][501] ;

int main()
{
    cin >> n >> m >> B >> M ;
    for(int i=1 ; i<=n ; i++)
    {
        cin >> a[i] ;
        for(int j=0 ; j<=m ; j++)
            for(int k=0 ; k<=B ; k++)
            {
                if(i==1)
                {
                    if(j*a[i] <= B ) dp[j][j*a[i]]=1 ;
                }
                else if(j>0 && k >= a[i]) dp[j][k] += dp[j-1][k-a[i]] ;
                // if(dp[j][k] >= M) dp[j][k] -= M ;
            }


        if(i==n)
        {
            for(int k=0 ; k<=B ; k++)
            {
                ans += dp[m][k] ;
                if(ans >= M) ans -= M ;
            }
        }
        cout<<endl<<endl;
    }

    for(int j=0 ; j<=m ; j++) for(int k=0 ; k<=B ; k++)

            cout << ans ;

    return 0;
}

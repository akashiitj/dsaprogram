#include <iostream>
using namespace std;
int n , m ,k;
long long p[5009] , dp [5009][5009] ;
int main ( )
{    cin >> n >> m >> k ;
     for ( int i=1 ; i<=n ; i++ )
    {
        cin >> p[i] ;
        p[i]+=p[i-1] ;
    }
    for ( int i=1; i<=k ; i++ )
        for ( int j=i*m ; j<=n ; j++ )
            dp[i][j] = max (dp[i][j-1],(dp[i-1][j-m]+p[j]-p[j-m]));//i no of pairs j-1 element se mile gaye ho yaa phir i-1 pair j-m element se mile+j element ko bhi include kara koi set me

    cout<<dp[k][n]<<endl;
    return 0;
}

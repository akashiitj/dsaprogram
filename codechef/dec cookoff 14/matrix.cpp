# include <bits/stdc++.h>
using namespace std;

int main()
{
    // char set[]={'a','b'};
    long long n,m;
    cin>>n>>m;
//    char set[n];
   long long ma[n][m];
    for(long long i=0; i<n; i++)
        for(long long j=0; j<m; j++)
            cin>>ma[i][j];
    long long sum=1,sum1;
    for(long long i=0; i<m; i++)
    {  sum1=0;
        for(long long j=0; j<n; j++)
        {
             sum1=sum1+ma[j][i];

        }
        while(sum1<0)sum1=sum1+10000007;
        sum=sum*sum1;
        if(sum>=10000007)
            sum=sum%10000007;
    }
    cout<<sum<<endl;
    return 0;
}

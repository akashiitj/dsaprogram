#include<bits/stdc++.h>
using namespace std;

#define loop(i,a,b)      for(int i=a;i<b;i++)

int arrange(string A, int B)
{
    int n=A.length();
    if(n<B)
        return -1;

    int cs[A.length()+1];
    cs[0]=0;
    for(int i=0; i<A.length(); i++)
    {
        cs[i+1]=cs[i]+(A[i]=='W');
    }
    int dp[n+1][B+1];
    for(int i=0; i<=n; i++)
        dp[i][0]=INT_MAX;
    for(int i=0; i<=B; i++)
        dp[0][i]=INT_MAX;

    dp[0][0]=0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=B; j++)
        {
            dp[i][j]=INT_MAX;
            int h=i-1;
            while(h>=0)
            {
                if(dp[h][j-1]<INT_MAX)dp[i][j]=min(dp[i][j],dp[h][j-1]+(cs[i]-cs[h])*(i-h-(cs[i]-cs[h])));
                h--;

            }
//cout<<dp[i][j]<<" "<<i<<" "<<j<<"   ";
        }
  //      cout<<"\n";
    }
    return dp[n][B];
}
int main()
{
    arrange("BWBW",2);
    // cout<<arrange("BWBW",2)<<"\n";


}

#include<bits/stdc++.h>
using namespace std;
int evaluatetrue(int  a1,int a2, int b1,int b2, char c)
{
    if(c=='&')
        return a1*b1;
    if(c=='|')
        return (a1+a2)*(b1+b2)-(a2*b2);
    if(c=='^')
        return a1*b2+a2*b1;
}

int evaluatefalse(int  a1,int a2, int b1,int b2, char c)
{
    if(c=='&')
        return (a1+a2)*(b1+b2)-a1*b1;
    if(c=='|')
        return (a2*b2);
    if(c=='^')
        return a1*b1+a2*b2;
}
int countParenth(char symbols[],char operators[],int n)
{
    int dp[n][n][2];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            dp[i][j][0]=0;
            dp[i][j][1]=0;
        }
    }
    for(int i=0; i<n; i++)
    {

        if(symbols[i]=='T')
            dp[i][i][1]=1;
        else
            dp[i][i][0]=1;
    }

    for(int L=2; L<=n; L++)
    {
        for(int i=0; i<n-L+1; i++)
        {
            int j=i+L-1;


            for(int k=i; k<j; k++)
            {
                dp[i][j][0]+=evaluatefalse(dp[i][k][1],dp[i][k][0],dp[k+1][j][1],dp[k+1][j][0],operators[k]);
                dp[i][j][1]+=evaluatetrue(dp[i][k][1],dp[i][k][0],dp[k+1][j][1],dp[k+1][j][0],operators[k]);

            }
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<dp[i][j][1]<<" ";
            }
            cout<<endl;
        }
        cout<<endl<<endl;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<dp[i][j][0]<<" ";
            }
            cout<<endl;
        }
        cout<<endl<<endl;
    }
    // for(int i=0; i<n; i++)for(int j=0; j<n; j++) cout<<dp[i][j][1]<<endl;
    return dp[0][n-1][1];
}
int main()
{
    char symbols[] = "TTFT";
    char operators[] = "|&^";
    int n = strlen(symbols);

    // There are 4 ways
    // ((T|T)&(F^T)), (T|(T&(F^T))), (((T|T)&F)^T) and (T|((T&F)^T))
    cout << countParenth(symbols, operators, n);

    return 0;
}

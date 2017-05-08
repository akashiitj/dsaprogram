#include<bits/stdc++.h>
using namespace std;
int dp(string s1,string s2,int ic,int dc,int rc)
{   int m=s1.length(),n=s2.length();
    int a[m+1][n+1];
    for(int i=0;i<m+1;i++)
        a[i][0]=i*dc;//base case for conveting s1 of various length to 0
    for(int i=0;i<n+1;i++)
        a[0][i]=i*ic;//base case for conveting s1 of 0 length to i length
    for (int i=1;i<m+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            a[i][j]=min(min(a[i-1][j]+dc,a[i][j-1]+ic),a[i-1][j-1]+(s1[i]==s2[j] ? 0 : rc));
        }
    }
    return a[m][n];
}
int main()
{
    string s1,s2;
    int ic,rc,dc;
     cin>>s1;
     cin>>s2;
     cin>>ic>>dc>>rc;
    cout<<dp(s1,s2,ic,rc,dc);
}


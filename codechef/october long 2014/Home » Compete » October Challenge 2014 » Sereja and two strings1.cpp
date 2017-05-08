#include<bits/stdc++.h>
using namespace std;

#define loop(i,a,b)      for(int i=a;i<b;i++)
#define rloop(i,a,b)     for(int i=b-1;i>=a;i--)

#define frmlty     int test_case;cin>>test_case;while(test_case--)

string s1;
string s2;

int ic,dc,rc;

int dp[2001][2001];

int td(int i,int j)
{
    if(i==0)
        return j*ic;
    else if(j==0)
        return i*dc;
    int deletion=td(i-1,j)+dc;
    int insertion=td(i,j-1)+ic;
    int replace=td(i-1,j-1)+(rc*(s1[i]!=s2[j]));
    return min(min(deletion,insertion),replace);
}

int tddp(int i,int j)
{
    if(dp[i][j]!=-1)return dp[i][j];
    if(i==0)
    {
        dp[i][j]=j*ic;
        return dp[i][j];
    }
    else if(j==0)
    {
        dp[i][j]=i*dc;
        return dp[i][j];
    }
    int deletion=tddp(i-1,j)+dc;
    int insertion=tddp(i,j-1)+ic;
    int replace=tddp(i-1,j-1)+(rc*(s1[i]!=s2[j]));
    dp[i][j]= min(min(deletion,insertion),replace);
    return dp[i][j];
}

void bup()
{
    int l1=s1.length();
    int l2=s2.length();
    loop(i,0,l2+1)//converting 0 length string into i length string s2 just insertion
    dp[0][i]=i*ic;

    loop(i,0,l1+1)//converting i length strinh into 0 length string s2 by deletion
    dp[i][0]=i*dc;

    loop(i,1,l1+1)
    {
        // cout<<i<<endl;
        loop(j,1,l2+1)
        {
            dp[i][j]=min(min(dp[i-1][j]+dc,dp[i][j-1]+ic),dp[i-1][j-1]+rc*(s1[i-1]!=s2[j-1]));
            //       cout<<dp[i][j]<<" ";
        }
        //cout<<endl;
    }
    cout<<dp[l1][l2];


}

void bupusing2arrayonly()
{
    int l1=s1.length();
    int l2=s2.length();
    loop(i,0,l2+1)//converting 0 length string into i length string s2 just insertion
    dp[0][i]=i*ic;
    int i1;
    dp[1][0]=dc;
    loop(i,1,l1+1)
    {
        i1=i%2;
        dp[i1][0]=i*dc;//you forget this
        loop(j,1,l2+1)
        {
            int pi;
            if(i1==1)pi=0;
            if(i1==0)pi=1;
            dp[i1][j]=min(min(dp[pi][j]+dc,dp[i1][j-1]+ic),dp[pi][j-1]+rc*(s1[i-1]!=s2[j-1]));
            cout<<dp[i1][j]<<" ";
        }
        cout<<endl;
    }
    cout<<dp[i1][l2]<<"\n";

}

int main()
{
    frmlty
    {
        loop(i,0,2001)
        loop(j,0,2001)
        dp[i][j]=-1;
        // cout<<"enter 2 string "<<endl;
        cin>>s1>>s2;

        // cin>>ic>>dc>>rc;
        ic=1;
        dc=1;
        rc=1;

        bupusing2arrayonly();
    }
    return 0;
}

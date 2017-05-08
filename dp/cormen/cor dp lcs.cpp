#include<bits/stdc++.h>
using namespace std;

#define loop(i,a,b)      for(int i=a;i<b;i++)
#define rloop(i,a,b)     for(int i=b-1;i>=a;i--)

string s1,s2;
int dp[1000][1000]= {-1};
int lcsr(int i,int j)//length of strings
{

    if(i==0||j==0)return 0;
    else if(s1[i-1]==s2[j-1])//if last index is same
    {
        return lcsr(i-1,j-1)+1;
    }
    else return max(lcsr(i,j-1),lcsr(i-1,j));

}
int lcstddp(int i,int j)//length of strings,with memoziation
{
    if (dp[i][j]!=-1)return dp[i][j];
    if(i==0||j==0)
    {
        dp[i][j]=0;
        return 0;
    }
    else if(s1[i-1]==s2[j-1])//if last index is same
    {
        dp[i][j]=lcstddp(i-1,j-1)+1;
        cout<<s1[i-1];//for printing lcs
        return dp[i][j];
    }
    else
    {
        return max(lcstddp(i,j-1),lcstddp(i-1,j));
    }
}

void lcsbup()
{
    int l1=s1.length();
    int l2=s2.length();
    loop(i,0,l1)//making base
    dp[i][0]=0;
    loop(j,0,l2)
    dp[0][j]=0;

    loop(i,1,l1+1)
    loop(j,1,l2+1)
    {
        if(s1[i]==s2[j])dp[i][j]=dp[i-1][j-1]+1;
        else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
    cout<<dp[l1][l2]<<endl;

    // printing lcs

    int i=l1;
    int j=l2;
    string s;
    while(i>=0&&j>=0)
    {
        if(s1[i]==s2[j])
        {

            s=s+s1[i];
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1])
            i--;
        else j--;
    }
    reverse(s.begin(),s.end());
    cout<<s<<"\n";
}

main()
{

    loop(i,0,1000)
    loop(j,0,1000)
    dp[i][j]=-1;
    cout<<"enter 2 string"<<endl;
    cin>>s1>>s2;
   // cout<<lcstddp(s1.length(),s2.length());//top down

  lcsbup();
}

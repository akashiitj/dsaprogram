#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

#define fast      ios_base::sync_with_stdio(false)
#define frmlty     int test_case;cin>>test_case;while(test_case--)

#define vi        vector<int>
#define vs        vector<string>
#define vll       vector<LL>
#define pii       pair<int,int>

#define msi       map<string,int>
#define msit      map<string,int>::iterator
#define pb        push_back
#define mp        make_pair



#define loop(i,a,b)      for(int i=a;i<b;i++)
#define rloop(i,a,b)     for(int i=b-1;i>=a;i--)

#define gcd(a,b)  __gcd(a,b)
#define mod       1000000007

#define inf       1000000

int dp[100][100];
int print[100][100];

int a[102];



void bottomup(int n)
{
    loop(i,1,n+1)
    dp[i][i]=0;

    loop(l,2,n+1)
    {
        loop(i,1,n-l+2)
        {
            loop(j,i,i+l-1)
            dp[i][i+l-1]=min(dp[i][i+l-1],dp[i][j]+dp[j+1][i+l-1]+a[i]*a[j+1]*a[i+l]);
        }
    }
    cout<<dp[1][n];
}

int tddp(int i,int j)//multiplying matrix no from i to j
{   if(dp[i][j]!=inf)return dp[i][j];
    if(i==j){ dp[i][i]=0;return 0;}
    int hv=dp[i][j];
    loop(k,i,j)
    {
        hv=min(hv,tddp(i,k)+tddp(k+1,j)+(a[i]*a[k+1]*a[j+1]));
        if(dp[i][j]>hv)
        {
            dp[i][j]=hv;
            print[i][j]=k;
        }


    }
    return dp[i][j];
}

void print1(int i,int j)
{
    if(i==j){
        cout<<"a"<<i;
        return;
    }
    cout<<"(";
    print1(i,print[i][j]);
    print1(print[i][j]+1,j);
    cout<<")";
}

int main()
{
    fast;
    cout<<"enter no of matrix"<<endl;
    int n;
    cin>>n;
    cout<<"enter n+1 no "<<endl;// a[1] a[2] are row and colomb of first matrix a[2] and a[3] are row and colomb of 2 matrix
    loop(i,1,n+2)
    cin>>a[i];

    loop(i,1,n+1)
    loop(j,1,n+1)
    dp[i][j]=inf;

    bottomup(n);
   //cout<<tddp(1,n)<<endl;
   //print1(1,6);

    }




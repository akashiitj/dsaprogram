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

int a[1000];
int dp[1000];
int printcut[1000];
int dptd(int n)
{   int cutpoint=n;
    if(dp[n]!=0)return dp[n];
    int ans=a[n];
    int preans=a[n];
    loop(i,1,(n/2)+1 )
    {
        ans=max(ans,dptd(i)+dptd(n-i));
       //  if(n==10) cout<<preans<<" "<<ans<<endl;
        if(preans<ans)
           {

            cutpoint=i;
            preans=ans;
           }
    }
    dp[n]=ans;
    printcut[n]=cutpoint;
   // cout<<cutpoint<<" ";
    return ans;
}

void printcut1(int n)
{
    while(n>0){
        cout<<printcut[n]<<" ";
        n=n-printcut[n];
    }
    cout<<endl;
}

int main()
{
    fast;
    //declare variable here
    cout<<"enter i for i different cost"<<endl;
    int i1;
    cin>>i1;
    loop(i,1,i1+1)
    cin>>a[i];

    cout<<"enter rod length"<<endl;

    int n;
    cin>>n;

    loop(i,1,n+1)
    dp[i]=0;

    int ans=dptd(n);
    cout<<ans<<endl;

    printcut1(n);
}

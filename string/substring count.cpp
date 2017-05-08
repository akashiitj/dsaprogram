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

ll o[100001];//total one
ll z[100001];//total zero
ll pre[100001];//store index(phele vala) of ith index upto which it contain maximum k 0 or 1
ll cs[100001];//total no of string upto index i satisfying the given condition

int main()
{
    fast;
    //declare variable here
    ll n,k,q;
    string s;
    frmlty
    {
       cin>>n>>k>>q;
       cin>>s;
       o[0]=0;
       z[0]=0;
       pre[0]=0;
       cs[0]=0;
       //preprocessing
       int l=n;
       int hv=0;//help for finding limit of particular index one by one
       loop(i,1,l+1)
       {
           o[i]=o[i-1]+(s[i-1]=='1');
           z[i]=z[i-1]+(s[i-1]=='0');
       }
        loop(i,1,l+1)
       {
           if(i>k)
           {
               while(o[i]-o[hv]>k||z[i]-z[hv]>k)
                hv++;
           }
           pre[i]=hv+1;
           cs[i]=cs[i-1]+i-hv;
       }
       loop(i,1,l+1)
       cout<<cs[i]<<" ";
       cout<<endl;
       ll ans;
       while(q--)
       {
           int l,r;
           cin>>l>>r;
           int lo=l,hi=r;
           int x=l-1;
           while(lo<=hi)
           {
               int mid=(lo+hi)/2;
               if(pre[mid]<l)
               {
                   x=mid;
                   lo=mid+1;
               }
               else hi=mid-1;
           }
           ans=cs[r]-cs[x];
           ll left=x-l+1;
           ans=ans+(left*(left+1))/2;
           cout<<ans<<endl;

       }

    }
      return 0;
}


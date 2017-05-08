#include <bits/stdc++.h>
#define loop(i, a, b) for(int i=a;i<b;i++)
#define ll long long
#define MAX 1000000007
using namespace std;
ll pnum[100002];
ll z[100002]={0};
set <ll> v;
ll fastexp(ll a,ll b){ll x=1,y=a;while(b>0){if(b%2 == 1)x=x*y;y=y*y;b=b>>1;}return x;}
float fsqrt(float x){float xhalf=0.5f*x;int32_t i=*(int32_t*)&x;i=0x5f375a86-(i>>1);x=*(float*)&i;x=x*(1.5f-xhalf*x*x);return 1/x;}
void clears( set<ll> &q )
{
   set<ll> empty;
   swap( q, empty );
}
void clearz( ll q[] )
{
   q=z;
}
ll pow1(ll i,ll j,ll k )
{  if(j==0)return 1;
    ll i1=i;
    while(j>1)
    {  if(i>=k)i=i%k;
        i=i*i1;
        j--;
    }
    return i%k;
}
void primef(ll n)
{  ll n1=n;
    ll pnumt = 0;
    while(n%2==0)
    {   v.insert(2);
        pnumt++;
        n = n>>1;
    }
    pnum[2] = pnum[2]+pnumt*n1;
    for(int i=3;i<=fsqrt(n);i=i+2)
    {
        pnumt = 0;
        while(n%i==0)
        {   v.insert(i);
            pnumt++;
            n = n/i;
        }
        pnum[i] = pnum[i]+pnumt*n1;
    }
    if (n > 2 && 1>pnum[n])
      {   v.insert(n);
          pnum[n] = pnum[n]+n1;
      }
}

void primefs(ll n)
{  ll n1=n;
    ll pnumt = 0;
    while(n%2==0)
    {
        pnumt++;
        n = n>>1;
    }
    pnum[2] = pnum[2]-pnumt*n1;
    for(int i=3;i<=fsqrt(n);i=i+2)
    {
        pnumt = 0;
        while(n%i==0)
        {
            pnumt++;
            n = n/i;
        }
        pnum[i] = pnum[i]-pnumt*n1;
    }
    if (n > 2 && 1>pnum[n])
        pnum[n] = pnum[n]-n1;
}

int main()
{  //cout<<(10*10*10*10)%24<<" "<<(((((10*10)%24)*10)%24)*10)%24<<endl;
    ios_base::sync_with_stdio(false);
    ll n,m,q,pro=1;
    ll r,x;
    ll ar[5]={1,4,108,27648,86400000};
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>q;
        while(q--)
        {
          cin>>r;
          x=n-r;
      /*    if(r<x)swap(r,x);

              for(ll i=r+1;i<=n;i++)
              {
                  primef(i);
              }
             // cout<<pnum[2]<<" "<<pnum[3]<<" "<<pnum[5]<<endl;
              for(ll i=1;i<=x;i++)
              {
                  primefs(i);
              }
               //cout<<pnum[2]<<" "<<pnum[3]<<" "<<pnum[5]<<endl;
               set<ll>::iterator it=v.begin();
               for (it=v.begin(); it!=v.end(); ++it){
            //   cout<<*it<<" "<<pnum[*it]<<endl;
                pro=pro*pow1(*it,pnum[*it],m);
              //  pro =pro*pow(*it,pnum[*it]);
                if(pro>=m)pro=pro%m;
               }
*/
         pro=ar[n-1]/(ar[r-1]*ar[n-r-1]);

          cout<<pro%m<<endl;

        }
    }
    return 0;
}

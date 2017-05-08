#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector < int >
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define TR(it,v) for( __typeof((v).begin())it = (v).begin() ; it != (v).end() ; it++ )
#define ll long long
#define llu unsigned long long
#define MOD 1000000007
#define INF 2000000000
#define dbg(x) { cout<< #x << ": " << (x) << endl; }
#define all(x) x.begin(),x.end()

#define maxi(a,b)                     ( (a) > (b) ? (a) : (b))
#define mini(a,b)                     ( (a) < (b) ? (a) : (b))


int a[1001];
int main()
{
    int t,n;
    cin>>t;
    ll ans=0;
        ll c=n*12;
        int s=0,k=0;
        int sum=0;
    while(t--)
    {
        cin>>n;
         ans=0;
         c=n*12;
         s=0;k=0;
         sum=0;
        for(int i=0; i<26; i++)
        {
            cin>>a[i];
            if(i<12) s+=a[i];
            if(i<24) k+=a[i];
            sum+=a[i];
        }
        if(n==1) cout<<s<<endl;
        else if(n==2) cout<<k<<endl;
        else
        {
            ans+=(sum)*1LL*(c/26);
            for(int i=1;i<c/26;i++)
            {
                ans+=26*i*1LL;
            }

            for(int i=0; i<(c%26); i++)
            {
                ans+=(a[i]+(c/26))*1LL;
                // cout<<ans<<endl;
            }
            cout<<ans<<endl;
        }
    }
}

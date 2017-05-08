#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll fact[10]= {0};
ll a[26]={0};
ll mod1(ll x)
{
    return x%1000000007;
}
int main()
{
    fact[0]=1;
    fact[1]=1;
    for(int i=2; i<=10; i++)
    {
        fact[i]=fact[i-1]*i;
       // fact[i]=(fact[i]);
    }
    string s;
    cin>>s;
     for(int i=0; i<s.length(); i++)
    {
        a[s[i]-97]++;
       // fact[i]=(fact[i]);
    }
    ll ans=fact[s.length()];
     for(int i=0; i<26; i++)
    {
        ans=ans/fact[a[i]];
    }

    cout<<ans<<endl;
return 0;
}


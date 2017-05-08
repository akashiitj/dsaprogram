#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    std::ios_base::sync_with_stdio(false);
    ll N;
    ll K;
    ll T;
    ll val;

    //scanf("%d", &T);
    //T = 20;
   while(true){
    cin>>N>>K;
    ll A[N];
    for(int i=0; i<N; i++)
        cin>>A[i];
    ll B[K];
    for(int i=0; i<K; i++)
    {
        B[i]=0;
    }
    B[0]++;
    ll s = 0;
    for(int i=0; i<N; i++)
    {
        s = (s + A[i]) % K;
        B[s]++;
    }
    ll ans = 0;
     for(int i=0; i<3; i++)
        cout<<B[i]<<" ";
     cout<<endl;
    for(int i=0; i<K; i++)
        ans += (B[i]*(B[i]-1))/2;
               // prllf("%lld\n", answer);
               cout<<ans<<endl;}
    return 0;
}

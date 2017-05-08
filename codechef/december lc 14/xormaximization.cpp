#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
int count(int x)
{
    int c=0;
    while(x>0)
    {
        c++;
        x>>=1;
    }
    return c;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N,k;
        cin>>N>>k;
        N++;
        vll dt;
        dt.reserve(N*2);
        dt.push_back(k);
        int c1=count(dt.front());
       // cout<<c1<<endl;
        for (int q=0; q<N-1; ++q)
        {
            ll x;
            scanf("%lld",&x);
            dt.push_back(x);
        }
        sort( dt.rbegin(), --dt.rend() );
        /*while(dt.size()>=2&&count(dt[1])==c1)
        {
            dt.erase(dt.begin()+1);
            N--;
        }*/
        ll sig = 1;
        while (sig <= dt[0]) sig<<=1;
        sig>>=1;
        for (int st = 0; sig>=1; sig>>=1)
        {
            int i = st;
            while (i<N && (dt[i]&sig)==0) i++;
            if (i>=N) continue;
            swap( dt[st], dt[i] );
            for (int j=0; j<N; ++j) if (j!=st && (dt[j]&sig)!=0)
                    dt[j] ^= dt[st];
            st++;
        }
        ll ret = 0;

        for (int q=0; q<N; ++q) ret ^= dt[q];
        printf("%lld\n",ret);
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define loop(i,a,b) for(ll i = a; i < b; i++)

ll mod = 1000000007;

float fsqrt(float x)
{
    float xhalf=0.5f*x;
    int32_t i=*(int32_t*)&x;
    i=0x5f375a86-(i>>1);
    x=*(float*)&i;
    x=x*(1.5f-xhalf*x*x);
    return 1/x;
}
ll mod1(ll x)
{
    return x%mod;
}

ll fast_mul(ll A,ll pow)
{
    ll C=1;


    while(pow>0)
    {
        if(pow&1)
        {
            C=mod1(C)*mod1(A);
            C=mod1(C);
            // cout<<C<<" "<<mod1(A)<<endl;
        }
        A=mod1(mod1(A)*mod1(A));
        pow>>=1;
    }
    return mod1(C);
}
vector<ll> v;
void prime(ll n)
{
    v.clear();
    ll c = 0;
    while(n%2==0)
    {
        c++;
        n = n>>1;
    }
    if(c!=0)  v.push_back(fast_mul(2,c));
    for(ll i=3; i<=sqrt((float)n); i=i+2)
    {
        c = 0;
        while(n%i==0)
        {
            c++;
            n = n/i;
        }
        if(c!=0)v.push_back(fast_mul(i,c));
    }
    if (n > 2 )
        v.push_back(n);

}
int main()
{
    // cout<<fast_mul(10000000,10000000)<<endl;
    //cout<<fast_mul(0,3);

    ll t;
    cin>>t;

    ll n,m,l,r,sub,sub1=0,common,rem;
    ll ans2=0;
    while(t--)
    {
        ll sum=0;
        //  sub1=0;
        cin>>n>>m>>l>>r;

        loop(i,l,r+1)
        {
            ans2=0;
            sub1=0;
            prime(i);
            sub=m/i;
            common=0;
            if(v.size()<=n)
            {

                loop(j,0,v.size())
                {
                    v[j]=(m/v[j])-sub;
                    common=common+v[j];
                }

                rem=m-sub;
                common=rem-common;
                ll cd=0,sub3;
                loop(j,0,v.size())
                {
                    ll ans4=fast_mul(v[j]+common,n);
                    cd++;
                    if(ans4<0)  ans4=ans4+(mod*10);
                    ans4=mod1(ans4);

                    sub1=sub1+ans4;
                    sub1=mod1(sub1);
                    // while(sub1<0)sub1=sub1+mod;
                }
                //  if(v.size()>0)
                sub1=sub1+fast_mul(common,n)-fast_mul(common,n)*cd;;
                while(sub1<0)sub1=sub1+(mod*10);
                sub1=mod1(sub1);
                ans2=fast_mul(rem,n)-sub1;
                while(ans2<0)ans2=ans2+(mod*10);
                ans2=mod1(ans2);


            }
            ll ans3=fast_mul(m,n)-fast_mul(m-m/i,n);
            while(ans3<0)ans3=ans3+(mod*10);
            ans3=mod1(ans3);

            sum=sum+ans3+ans2;
            while(sum<0)sum=sum+mod;
            sum=mod1(sum);
            while(sum<0)sum=sum+mod;
        }

        cout<<sum<<endl;
    }
    return 0;
}

/*
13
10 12 1 1
10 12 2 2
10 12 3 3
10 12 4 4
10 12 5 5
10 12 6 6
10 12 7 7
10 12 8 8
10 12 9 9
10 12 10 10
10 12 11 11
10 12 12 12
10 12 1 12


917363797
856897621
843621980
430579417
917363867
784204380
979939378
979939378
979939378
866663316
979939378
417303776
953755603
*/


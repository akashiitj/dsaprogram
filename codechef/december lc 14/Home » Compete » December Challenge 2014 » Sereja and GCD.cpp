#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[10000001]= {0};
void intialize(int ml)
{
    for(int i=0; i<=ml; i++)
        a[i]=0;
}
ll mod1(ll x)
{
    return x%1000000007;
}

ll fast_mul(ll A,ll pow)
{
    ll C=1;


    while(pow>0)
    {
        if(pow&1)
        {
            C=C*A;
            C=mod1(C);
            // cout<<C<<" "<<mod1(A)<<endl;
        }
        A=mod1(A*A);
        pow>>=1;
    }
    return mod1(C);
}

main()
{
    int t;
    cin>>t;

    ll j,n,m,i,l,r,v1,c1,c,sum=0,hv,x,tn,nl;
    while(t--)
    {
        sum=0;
        cin>>n>>m>>l>>r;
        sum=0;
        intialize(m);
        ll p=m/2;
        ll pi=-1;
        a[1]=1;
        if(m>=2)
        {
            for( i=m/p; p>=1; p--)//starts from mid(p) find number of its multiple = to i;
            {
                i=m/p;
                if(pi!=i)//avoid precomputation
                {
                    ll sub=0;


                    for( j=2; j<=i/2; j++)//removes such number whose gcd is 2*i and so on...
                    {
                        sub=sub+a[i/j];
                        sub=mod1(sub);
                    }
                    sub=sub+(i-i/2);//removing number greater than middle since their twice is beyond i
                    //so we can get only 1 array ehich consist of that element only and its gcd is also that element
                    a[i]=fast_mul(i,n)-sub;
                    a[i]=mod1(a[i]);
                    while(a[i]<0)
                        a[i]=a[i]+1000000007;
                }
                pi=i;
            }

        }
        for(ll i=l; i<=r; i++)
        {
            sum=sum+a[m/i];//ans depends only on number of its multiple
            sum=mod1(sum);
        }
        cout<<sum<<endl;
    }
}

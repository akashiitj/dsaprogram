#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define mod 1000000007

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
            if(C>mod) C=mod1(C);
            // cout<<C<<" "<<mod1(A)<<endl;
        }
        A=A*A;
        if(A>mod) A=mod1(A);
        pow>>=1;
    }
    return mod1(C);
}

ll rm(ll x)
{
    return fast_mul(x,mod-2);
}

main()
{
    long long t,n,x,hv,ans,on,ans1,ans2;
    cin>>t;
    while(t--)
    {
        ans=1;
        ans1=1;
        ans2=1;
        cin>>n;
        if(n==1)
		{
			printf("0\n");
			continue;
		}
        x=n;
        hv=0;
        while(x%2==0)
        {
            hv=1;
            x=x/2;
        }
        if(hv==1)
        {
            ans=ans*(1-2);

            ans1=ans1*(2-1);
            ans2=ans2*2;
        }
        for(long long i=3; i*i<=x; i=i+2)
        {
            hv=0;
            while(x%i==0)
            {
                hv=1;
                x=x/i;
            }
            if(hv==1)
            {
                ans=ans*(1-i);
                ans1=ans1*(i-1);
                ans2=ans2*i;
            }
        }
        if(x>2)
         {

            ans=ans*(1-x);
            ans1=ans1*(x-1);
                ans2=ans2*x;

         }
         on=mod1(n*ans1);
         on=mod1(on*rm(ans2));

         ans1=mod1(mod1(n*n)*on);
         ans1=mod1(ans1*rm(3));

         ans2=ans;
         if(ans2>mod)ans2=mod1(ans2);
         while(ans2<0)ans2=ans2+mod;
         ans2=mod1(ans2);
         ans2=mod1(ans2*rm(6));
         ans2=mod1(ans2*n);
         cout<<mod1(ans1+ans2)<<endl;


    }
}

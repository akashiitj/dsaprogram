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
            C=mod1(C)*mod1(A);
            C=mod1(C);
            // cout<<C<<" "<<mod1(A)<<endl;
        }
        A=mod1(mod1(A)*mod1(A));
        pow>>=1;
    }
    return mod1(C);
}
main()
{
    // cout<<fast_mul(10000000,10000000)<<endl;
    int t;
    cin>>t;
    /*   a[1]=1;
       for(ll i=2; i<1000; i++)
       {
           ll sub=0;
           for(ll j=2; j<=i/2; j++)
           {
               sub=sub+a[i/j];
               sub=mod1(sub);
           }
           sub=sub+(i-i/2);
           a[i]=fast_mul(i,10000000)-sub;
           a[i]=mod1(a[i]);
           while(a[i]<0)
               a[i]=a[i]+i;

       }
       for(ll i=1; i<=10; i++)
       {
           cout<<a[i]<<" ";

       }*/
    ll j,n,m,i,l,r,v1,c1,c,sum=0,hv,x,tn,nl;
    while(t--)
    {
        sum=0;
        cin>>n>>m>>l>>r;



/*        intialize(m);
        a[1]=1;

        for( i=2; i<=m; i++)
        {
            ll sub=0;
            for( j=2; j<=i/2; j++)
            {
                sub=sub+a[i/j];
                sub=mod1(sub);
            }
            sub=sub+(i-i/2);
            a[i]=fast_mul(i,n)-sub;
            a[i]=mod1(a[i]);
            while(a[i]<0)
                a[i]=a[i]+i;

        }
        for(ll i=0; i<=12; i++)
            cout<<a[i]<<" ";
        cout<<endl;
        for(ll i=l; i<=r; i++)
        {
            sum=sum+a[m/i];
            sum=mod1(sum);

        }

        cout<<sum<<endl;

        /*
         for(ll i=0; i<=12; i++)
            cout<<a[i]<<" ";
        cout<<endl;
        */

        sum=0;
        intialize(m);
        ll p=m/2;
        ll pi=-1;
        a[1]=1;
        if(m>=2){
        for( i=m/p; p>1; p--)
        {
            //cout<<"bef "<<p<<" "<<pi<<" "<<i<<endl;
            i=m/p;
            if(pi!=i)
            {
                // cout<<pi<<" "<<i<<endl;
                ll sub=0;
                for( j=2; j<=i/2; j++)
                {
                    sub=sub+a[i/j];
                    sub=mod1(sub);
                }
                sub=sub+(i-i/2);
                a[i]=fast_mul(i,n)-sub;
                a[i]=mod1(a[i]);
                while(a[i]<0)
                    a[i]=a[i]+1000000007;

            }
            pi=i;
        }
        for(i=m; i<=m; i++)
        {
            ll sub=0;
            for( j=2; j<=i/2; j++)
            {
                sub=sub+a[i/j];
                sub=mod1(sub);
            }
            sub=sub+(i-i/2);
            a[i]=fast_mul(i,n)-sub;
            a[i]=mod1(a[i]);
            while(a[i]<0)
                a[i]=a[i]+1000000007;

        }
        }
        for(ll i=l; i<=r; i++)
        {
            sum=sum+a[m/i];
            sum=mod1(sum);

        }

        cout<<sum<<endl;


    }
}

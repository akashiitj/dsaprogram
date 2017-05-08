#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define loop(i,a,b)      for(int i=a;i<b;i++)

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

ll mp(ll x)
{
    while(x<0)x=x+10*mod;
    return x;
}

main()
{
    // cout<<fast_mul(10000000,10000000)<<endl;
    int t;
    scanf("%d",&t);
    //  cin>>t;
    ll n,k;
    ll a1,a2,a3,a4,a5,a6,a7,t1,t2,ans1;
    ll o=1;
    while(t--)
    {
        cin>>n>>k;
        //scanf("%lld%lld",&n,&k);
        a1=fast_mul(k,n+n)-o+mod;
        if(a1>mod)a1=mod1(a1);
        a1=a1*((k*k)+(k*k*k));
        if(a1>mod)a1=mod1(a1);
        a1=a1*rm((k*k)-o);
        if(a1>mod)a1=mod1(a1);

        a2=fast_mul(k,n)-o+mod;
        if(a2>mod)a2=mod1(a2);
        a3=(6*k);
        a4=((2*k)+2)*rm(fast_mul(k,n));
        if(a4>mod)a4=mod1(a4);
        a2=a2*(a3+a4);
        if(a2>mod)a2=mod1(a2);
        a2=a2*rm(k-o);
        if(a2>mod)a2=mod1(a2);

        a1=a1+a2;
        if(a1>mod)a1=mod1(a1);


        a7=n*3;
        if(a7>mod)a7=mod1(a7);
        t1=(n-1)*(k-1);
         if(t1>mod)t1=mod1(t1);
         t1=t1+k-3+mod;
         t1=mod1(t1);
        a7=a7*t1;
        if(a7>mod)a7=mod1(a7);


        a1=a1+a7;
        if(a1>mod)a1=mod1(a1);

        a5=n*fast_mul(k,n);
        if(a5>mod)a5=mod1(a5);
        a5=a5*6*k;

       // a5=6*k*n*fast_mul(k,n);
        if(a5>mod)a5=mod1(a5);

        a1=a1-a5+mod;
       if(a1<0) a1=mp(a1);
        a1=mod1(a1);
        a1=a1*fast_mul(k,n+o);
        if(a1>mod)a1=mod1(a1);

         a1=a1*rm((k-1)*(k-1));
         if(a1>mod)a1=mod1(a1);

        if(a1>mod)a1=mod1(a1);
        cout<<a1<<endl;


    }
}




/*
20
1 1
1 2
1 3
2 1
2 2
2 3
3 1
3 2
3 3
100 100
1000 1000
20 20
1 4
2 4
3 4
1000000000 26
1000000000 24
10000000 26
10000 20
20000 22

0
0
6
0
36
834
0
996
42360
721093675
732735402
816487704
24
5256
506376
32017256
831960507
72031950
736636710
303582835

26
1000000000 1
1000000000 2
1000000000 3
1000000000 4
1000000000 5
1000000000 6
1000000000 7
1000000000 8
1000000000 9
1000000000 10
1000000000 11
1000000000 12
1000000000 13
1000000000 14
1000000000 15
1000000000 16
1000000000 17
1000000000 18
1000000000 19
1000000000 20
1000000000 21
1000000000 22
1000000000 23
1000000000 24
1000000000 25
1000000000 26
*/

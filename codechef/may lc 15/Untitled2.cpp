#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define loop(i,a,b)      for(int i=a;i<b;i++)

#define mod       1000000007

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
    cin>>t;
    ll n,k;
    ll a1,a2,a3,a4,a5,a6;
    while(t--)
    {
       cin>>n>>k;
       a1=fast_mul(k,2)+fast_mul(k,3);
       a2=fast_mul(k,2*n);
       a2=a2-1;
       a2=mp(a2);
       a2=a2*rm((k*k)-1);
       if(a2>mod)a2=mod1(a2);
       a1=a1*a2;
       if(a1>mod)a1=mod1(a1);//
      // cout<<a1<<endl;
       a3=(7*k)-(5*k*k);
       a4=fast_mul(k,n);
       a4=a4-1;
       a4=mp(a4);
       a4=a4*rm(k-1);

       if(a4>mod)a4=mod1(a4);

       a3=a3*a4;
       if(a3>mod)a3=mod1(a3);//
      // cout<<a3<<" "<<a4<<endl;
       a1=a1+a3;
      // cout<<a1<<endl;

       a5=n*fast_mul(k,n);
       if(a5>mod)a5=mod1(a5);
       a4=fast_mul(k,n);
       a4=a4-1;
       a4=mp(a4);
       a4=a4*k;
       a4=a4*rm(k-1);
       if(a4>mod)a4=mod1(a4);
      // cout<<a5<<"  54 "<<a4<<endl;
 //      while(a5<a4)a5=a5+mod;
        a5=a5-a4;
      a5=mp(a5);
       a5=a5*6*k;

       if(a5>mod)a5=mod1(a5);
      // cout<<a5<<endl;
       a6=(2*k+2)*n;
       if(a6>mod)a6=mod1(a6);

       a5=a6+a5;


        while(a1<a5)a1=a1+mod;

        a1=a1-a5;

        a1=a1*fast_mul(k,n+1);
        if(a1>mod)a1=mod1(a1);

        a1=a1*rm((k-1)*(k-1) );
         if(a1>mod)a1=mod1(a1);

       // cout<<a1<<endl;

        a2=k*k;
        a2=a2+k*k*k;
        a4=fast_mul(k,n);
        a4=a4-1;
        a4=mp(a4);
        //a4=a4*k;
        a4=a4*rm(k-1);
        if(a4>mod)a4=mod1(a4);
        a2=a2*a4;
        if(a2>mod)a2=mod1(a2);
      //  cout<<a2<<"  24 "<<a4<<endl;
        a2=a2+((7*k)-(5*k*k))*n;
        if(a2<0)a2=mp(a2);
        if(a2>mod)a2=mod1(a2);
    //    cout<<a2<<" 1  "<<endl;
        a2=a2-(3*k*n*(k-1)*(n-1));
        //cout<<a2<<" 2  "<<endl;
       if(a2<0)a2=mp(a2);
        a3=(2*k)+2;
        a4=fast_mul(k,n);
        a4=a4-1;
        a4=mp(a4);
        //a4=a4*k;
        a4=a4*rm(k-1);
        if(a4>mod)a4=mod1(a4);
       // cout<<fast_mul(k,n-1)<<" fm "<<rm(fast_mul(k,n-1))<<endl;
        a3=a3*rm(fast_mul(k,n-1));
         if(a3>mod)a3=mod1(a3);
     //   cout<<a3<<" 34 "<<a4<<endl;
         a3=a3*a4;
          if(a3>mod)a3=mod1(a3);
       // cout<<a2<<" 3  "<<a3<<endl;
      while(a2<a3)a2=a2+mod;
          a2=a2-a3;

          a2=a2*fast_mul(k,n);
          if(a2>mod)a2=mod1(a2);
         // cout<<a2<<" 4  "<<endl;
          a2=a2*rm((k-1)*(k-1));
           if(a2>mod)a2=mod1(a2);
        //     cout<<a2<<" 4  "<<endl;
          while(a1<a2)a1=a1+mod;

          a1=a1-a2;

          cout<<mod1(a1)<<endl;

 }
}

#include<iostream>
using namespace std;
unsigned long long gcd(unsigned long long a,unsigned long long b)
{
    unsigned long long rem;
    if(b==0)
        return a;
    if(a==0)
        return b;
    if(b>a)
    {
        a=a+b;
        b=a-b;
        a=a-b;
    }
    rem=a%b;
    while(rem>b)
    {
        a=b;
        b=rem;
        rem=a%b;
    }
    if(rem==0)
        return b;
    else
        return rem;
}
unsigned long long f(unsigned long long a[],unsigned long long i,unsigned long long *c,unsigned long long vai)//value at i
{
    unsigned long long x=a[i-1];
    (*c)++;
    if(vai==x)
        return *c;
    f(a,x,c,vai);

}
 main()
{   std::ios_base::sync_with_stdio(false);
    unsigned long long t;
    cin>>t;
    while(t>0)
    {
        unsigned long long c=0;
        unsigned long long n;
        cin>>n;
        unsigned long long a[n];
        for(unsigned long long i=0; i<n; i++)
            cin>>a[i];
        if(n==1)
        {
            cout<<1<<endl;

        }
        else{f(a,1,&c,1);
        unsigned long long x=c;

        c=0;
        f(a,1+1,&c,1+1);
        unsigned long long y=c;
        unsigned long long lcm=(x%(1000000007))*((y/gcd(x,y))%(1000000007));
        for(unsigned long long i=0; i<n; i++)
        {
            c=0;f(a,i+1,&c,1+i);
            unsigned long long nn=c;
          // cout<<nn<<endl;
            lcm=(lcm%(1000000007))*((nn/gcd(lcm,nn))%1000000007);

        }
        cout<<lcm%(1000000007)<<endl;
        }
        t--;
    }

}

#include<bits/stdc++.h>
using namespace std;

#define ll long long




#define loop(i,a,b) for(ll i=a;i<b;i++)

#define mod       1000000007
//_____starts____here_______
ll arr[10000002], N,K;
ll a1[10000002];//store minimun in chunk of k from staring of chunk to end of chunk
ll b1[10000002];//store minimun in chunk of k from ending of chunk to starting of chunk

int ceil1(int x,int y)
{
    int  q = (x + y - 1) / y;
    return q;
}


void preprocess(int n)
{
    int c=0;
    int i=1;
    ll min1;
    while(i<=n)
    {
        c=1;
        min1=arr[i];
        while(c<=K&&i<=n)
        {
            if(arr[i]<=min1)
            {
                min1=arr[i];
                a1[i]=min1 ;
            }
            else if(arr[i]>min1)
            {
                a1[i]=min1;
            }
            c++;
            i++;
        }
    }
    ll lb=n/K;
    i=lb*K;
    ll i1=i;
    min1=arr[n];
    for(ll x1=n; x1>=i1+1; x1--)
    {
        if(arr[x1]<=min1)
        {
            min1=arr[x1];
            b1[x1]=min1 ;
        }
        else if(arr[x1]>min1)
        {
            b1[x1]=min1;
        }
    }

    while(i>=1)
    {
        c=1;
        min1=arr[i];
        while(c<=K)
        {
            if(arr[i]<=min1)
            {
                min1=arr[i];
                b1[i]=min1 ;
            }
            else if(arr[i]>min1)
            {
                b1[i]=min1;
            }
            c++;
            i--;
        }
    }

}

ll f1(int l,int r)
{
    int rb=ceil1(r,K);
    int lb=ceil1(l,K);
    if(rb-lb<=1)
    {
        return min(a1[r],b1[l]);
    }
    else if(rb-lb>1)
    {
        return min(min(a1[r],b1[l]),a1[(rb-1)*K]);
    }
}



ll pow12[10000001];
int main()
{
    ll Q;
    // cin>>N>>K>>Q;
    scanf("%lld %lld %lld",&N,&K,&Q);
    ll a,b,c,d,e,f,r,s,t,m;
    ll  L1, La, Lc, Lm, D1, Da, Dc, Dm;
    scanf("%lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld",&a,&b,&c,&d,&e,&f,&r,&s,&t,&m,&arr[1], &L1,&La,&Lc,&Lm,&D1,&Da,&Dc,&Dm);

    pow12[1]=t;

    loop(x,2,N+1)
    {
        pow12[x]=pow12[x-1]*t;
        if(pow12[x]>=s)pow12[x]=pow12[x]%s;
    }
    ll t1,t2,t3;
    loop(x,2,N+1)
    {
        if(pow12[x]  <= r)        // Here t^x signifies "t to the power of x"
        {
            t1=arr[x-1]*arr[x-1];
            //   cout<<t1<<" ";
            if(t1>=m)t1=t1%m;

            t1=t1*a;

            if(t1>=m)t1=t1%m;

            t2=b*arr[x-1];

            if(t2>=m)t2=t2%m;

            t3=t1+t2+c;

            if(t3>=m)t3=t3%m;

            arr[x]=t3;


        }
        else

        {
            t1=arr[x-1]*arr[x-1];
            if(t1>=m)t1=t1%m;
            t1=t1*d;
            if(t1>=m)t1=t1%m;
            t2=e*arr[x-1];
            if(t2>=m)t2=t2%m;
            t3=t1+t2+f;
            if(t3>=m)t3=t3%m;
            arr[x]=t3;
        }
    }

    preprocess(N);


    ll y,sum=0,mul=1;
    ll L,R;
    loop(x,1,Q+1)
    {
        L1 = (La * L1 + Lc) % Lm;
        D1 = (Da * D1 + Dc) % Dm;
        L = L1 + 1;
        R = min(L + K - 1 + D1, N);
        y=f1(L,R);
        sum=sum+y;
        mul=mul*y;

        if(mul>=mod)
            mul=mul%mod;

    }
    printf("%lld %lld\n",sum,mul);
    //cout<<sum<<" "<<mul<<endl;
    return 0;
}

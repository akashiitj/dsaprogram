#include<bits/stdc++.h>
using namespace std;

#define ll int




#define loop(i,a,b) for(ll i=a;i<b;i++)

#define mod       1000000007
//_____starts____here_______
ll arr[10000002], N;

ll st1[60000005];//for min query

void build(ll i,ll si,ll ei)//i node of segment tree hold sum from start index  to end index of original array
{
    if(si==ei)
    {

        st1[i]=arr[si];
        return;
    }
    ll mid=(si+ei)/2;
    build(2*i,si,mid);
    build((2*i)+1,mid+1,ei);

    st1[i]=min(st1[2*i],st1[(2*i)+1]);//for min query

}

ll minq(ll i,ll j,ll sti,ll si,ll ei)
{
    if(i<=si&&j>=ei)//this imply whole part from si to ei must be going to add up for required sum
        return st1[sti];
    if((si>j)||(i>ei))//this is not going to be included
        return 10000000000;
    ll mid =(si+ei)/2;
    return min(minq(i,j,2*sti,si,mid),minq(i,j,(2*sti)+1,mid+1,ei));
}


ll pow12[10000001];
int main()
{
    ll K,Q;
    // cin>>N>>K>>Q;
    scanf("%d %d %d",&N,&K,&Q);
    ll a,b,c,d,e,f,r,s,t,m;
    ll  L1, La, Lc, Lm, D1, Da, Dc, Dm;
    scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",&a,&b,&c,&d,&e,&f,&r,&s,&t,&m,&arr[1], &L1,&La,&Lc,&Lm,&D1,&Da,&Dc,&Dm);

    pow12[1]=t;

    loop(x,2,N+1)
    {
        pow12[x]=pow12[x-1]*t;
        if(pow12[x]>=s)pow12[x]=pow12[x]%s;
    }
    long long t1,t2,t3;
    loop(x,2,N+1)
    {
        if(pow12[x]  <= r)        // Here t^x signifies "t to the power of x"
        {

            // arr[x] = (a*(arr[x-1]*arr[x-1]) + b*arr[x-1] + c) % m;

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



    build(1,1,N);
    long long  y,sum=0,mul=1;
    ll L,R;
    loop(x,1,Q+1)
    {
        L1 = (La * L1 + Lc) % Lm;
        D1 = (Da * D1 + Dc) % Dm;
        L = L1 + 1;
        R = min(L + K - 1 + D1, N);
        y=minq(L,R,1,1,N);
        sum=sum+y;
        mul=mul*y;

        if(mul>=mod)
            mul=mul%mod;

    }
    printf("%lld %lld\n",sum,mul);
    //cout<<sum<<" "<<mul<<endl;
    return 0;
}

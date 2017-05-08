#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void buildft(int a[],int f[],int ml)
{
    int j;
    for(int i=1; i<ml; i++)
    {
        j=i;
        while(j<ml)
        {
            f[j]=f[j]+a[i];
            j=j+(j&(-j));
        }
    }
}
void update(int a[],int f[],int ml,int p,int dx)
{
    a[p]=a[p]+dx;
    while(p<ml)
    {
        f[p]=f[p]+dx;
        p=p+(p&(-p));
    }

}
int sum(int f[],int i)
{
    int s=0;
    while(i>0)
    {
        s=s+f[i];
        i=i-(i&(-i));
    }
    return s;
}
void print(int a[],int ml)
{
    for(int i=0; i<ml; i++ )
        cout<<a[i]<<" ";
    cout<<endl;
}

main()
{
    std::ios_base::sync_with_stdio(false);
    int n,i,q;
    //  cout<<"enter size of ft or array +1"<<endl;
    cin>>n>>q;
    string s;
    cin>>s;
    n;
    int a[n],f[n];
    //a[0]=0;
    //f[0]=0;
    for(i=0; i<n; i++ )
    {
        a[i]=s[i]-48;
        //f[i]=0;
    }

    //buildft(a,f,n);

    int wq;
    unsigned long long c=0;
    int x,y,j;
    if(n<=1000)
    {
        while(q--)
        {
            cin>>wq;
            if(wq==1)
            {
                cin>>x>>y;
                a[x-1]=y;

            }
            else
            {
                //c=0;
                cin>>x>>y;
                ll B[3];
                for(int i=0; i<3; i++)
                {
                    B[i]=0;
                }
                B[0]++;
                ll s = 0;
                for(int i=x-1; i<y; i++)
                {
                    s = (s + a[i]) % 3;
                    B[s]++;
                }
                ll ans = 0;
                for(int i=0; i<3; i++)
                    ans += (B[i]*(B[i]-1))/2;
                // prllf("%lld\n", answer);
                cout<<ans<<endl;
            }
        }

    }
    else{
             ll B[3];
                for(int i=0; i<3; i++)
                {
                    B[i]=0;
                }
                B[0]++;
                ll s = 0;
                for(int i=0; i<n; i++)
                {
                    s = (s + a[i]) % 3;
                    B[s]++;
                }
                ll ans = 0;
                for(int i=0; i<3; i++)
                    ans += (B[i]*(B[i]-1))/2;


    }
}


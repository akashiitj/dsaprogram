#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

ll mod= 1000000007;

//cout<<fixed<<setprecision(6)<<ans<<"\n";

#define frmlty     int test_case;cin>>test_case;while(test_case--)

#define vi        vector<int>
#define vs        vector<string>
#define vll       vector<ll>
#define pii       pair<int,int>

#define msi       map<string,int>
#define msit      map<string,int>::iterator
#define pb        push_back
#define mp        make_pair

#define loop(i,a,b)      for(int i=a;i<b;i++)
#define rloop(i,a,b)     for(int i=b-1;i>=a;i--)

#define gcd(a,b)  __gcd(a,b)
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))

#define le(x) scanf("%d",&x);
#define le2(x,y) scanf("%d%d",&x,&y);
#define lell(x) scanf("%lld",&x);
#define le2ll(x,y) scanf("%lld%lld",&x,&y);

#define F first
#define S second

int a[201];

int bti[201];
int dpi[201];

int btd[201];
int dpd[201];

int ht[201];
int hta[201];

int main()
{
    int n;
    while(true)
    {
        le(n);
        if(n==-1)
            break;

        loop(i,1,n+1)
        le(a[i]);

        loop(i,1,n+1)
        {
            dpi[i]=1;
            bti[i]=i;
            loop(j,1,i)
            {
                if(a[j]<a[i]&&dpi[i]<dpi[j]+1)
                {
                    dpi[i]=dpi[j]+1;
                    bti[i]=j;
                }
            }
        }

        loop(i,1,n+1)
        cout<<dpi[i]<<" ";
        cout<<"\n";

        loop(i,1,n+1)
        cout<<bti[i]<<" ";
        cout<<"\n";



        loop(i,1,n+1)
        {
            dpd[i]=1;
            btd[i]=i;
            loop(j,1,i)
            {
                if(a[j]>a[i]&&dpd[i]<=dpd[j]+1)
                {
                    dpd[i]=dpd[j]+1;
                    btd[i]=j;
                }
            }
        }
        cout<<"\n";
        loop(i,1,n+1)
        cout<<dpd[i]<<" ";
        cout<<"\n";

        loop(i,1,n+1)
        cout<<btd[i]<<" ";
        cout<<"\n";




        int di,dj;
        int fa=0;
        int ans;
        loop(i,1,n+1)
        {
            memset(ht,0,sizeof(ht));
            di=i;
            while(di!=bti[di])
            {
                ht[di]=1;
                di=bti[di];
            }
            ht[di]=1;

            //cout<<"c1\n";

            loop(j,1,n+1)
            {
                loop(k,1,n+1)
                hta[k]=ht[k];



                dj=j;

                while(dj!=btd[dj])
                {
                    hta[dj]=1;
                    dj=btd[dj];



                }


                hta[dj]=1;
                ans=0;

                loop(k,1,n+1)
                if(hta[k]==1)ans++;

                fa=maX(fa,ans);





            }
        }

        cout<<n-fa<<"\n";

    }
    return 0;
}



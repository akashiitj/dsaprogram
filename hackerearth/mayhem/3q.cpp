#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

ll mod= 1000000007;

#define fast      ios_base::sync_with_stdio(false);
#define frmlty     int test_case;cin>>test_case;while(test_case--)

#define vi        vector<int>
#define vs        vector<string>
#define vll       vector<ll>
#define pii       pair<int,int>

#define msi       map<string,int>
#define msit      map<string,int>::iterator
#define pb        push_back
#define mp        make_pair

#define loop(i,a,b)      for(ll i=a;i<b;i++)
#define rloop(i,a,b)     for(int i=b-1;i>=a;i--)

#define gcd(a,b)  __gcd(a,b)
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))

#define le(x) scanf("%d",&x);
#define le2(x,y) scanf("%d%d",&x,&y);
#define lell(x) scanf("%lld",&x);
#define le2ll(x,y) scanf("%lld%lld",&x,&y);

pair<int,int> a1[100001];
int b1[200005];
int mi[100001];
int ma[100001];
pair<int,int> la[100001];
pair<int,int> ra[100001];
int n;
ll inv=0;
void mergesort(int l,int r)
{
    if(l<r)
    {
        int m=(l+r)/2;
        mergesort(l,m);
        mergesort(m+1,r);
        int ln=m-l+1;
        int rn=r-m;
        int l11=l;
        loop(i,1,ln+1)
        {
            la[i].first=a1[l].first;
            la[i].second=a1[l++].second;
        }
        la[ln+1].first=INT_MAX;
        loop(i,1,rn+1)
        {
            ra[i].first=a1[++m].first;
            ra[i].second=a1[m].second;
        }
        ra[rn+1].first=INT_MAX;
        int i=1,j=1;
        loop(x,l11,r+1)//you forget it first time r written by you
        {
            // //cout<<x<<" "<<ln<<" "<<i<<" "<<inv<<endl;
            if(la[i].first<=ra[j].first)
            {

                a1[x].first=la[i].first;
                a1[x].second=la[i].second;
                i++;
            }
            else
            {
                a1[x].first=ra[j].first;
                a1[x].second=ra[j].second;
                inv=inv+ln-i+1;
                j++;
            }
            // //cout<<x<<" "<<ln<<" "<<i<<" "<<inv<<"after\n";
        }


    }
}
int main()
{
    int x;
    frmlty
    {
        inv=0;
        le(n);
        loop(i,1,n+1)
        {
            le(x);
            a1[i]=make_pair(x,i);
            b1[i]=x;
            mi[i]=0;
            ma[i]=0;
            b1[n+i]=x;
        }
        int flag=0;

        loop(i,1,n)
        {
            if(b1[i]!=b1[i+1])flag=1;
        }
        if(flag==0)
        {

            printf("0 0\n");
            continue;
        }
        mergesort(1,n);
        mi[a1[1].second]=0;
        ma[a1[n].second]=0;

        //  loop(i,1,n+1)
        //cout<<a1[i].first<<" "<<a1[i].second<<endl;


        loop(i,2,n+1)
        {
            if( a1[i].first>a1[i-1].first)
                mi[a1[i].second]=i-1;
            else  mi[a1[i].second]=mi[a1[i-1].second];

            if(a1[i].first>a1[i-1].first)
                ma[a1[i-1].second]=n-i+1;
        }

        /*  loop(i,1,n+1)
          //cout<<mi[i]<<" ";
          //cout<<endl;

          loop(i,1,n+1)
          //cout<<ma[i]<<" ";
          //cout<<endl<<endl;
         */
        for(int i=n-1; i>=1; i--)
            if(a1[i].first==a1[i+1].first) ma[a1[i].second]=ma[a1[i+1].second];

        // loop(i,1,n+1)
        //cout<<mi[i]<<" ";
        //cout<<endl;

        // loop(i,1,n+1)
        //cout<<ma[i]<<" ";
        //cout<<endl<<endl;

        // cout<<inv<<endl;


        vi v;
        v.clear();
        ll ninv;
        //cout<<endl<<endl;
        ll maxinv=inv;
        v.pb(1);
        loop(i,1,n)
        {
            ninv=inv+ma[i]-mi[i];
            if(ninv>maxinv)
            {
                maxinv=ninv;
                v.clear();
                v.pb(i+1);
            }
            else  if(ninv==maxinv) v.pb(i+1);

            inv=ninv;
        }
//        cout<<maxinv<<endl;
//        loop(i,0,v.size())
//        cout<<v[i]<<" ";
//        cout<<" end v"<<endl;
        vi t;
        if(v.size()==0)
        {
            printf("0 %lld\n",maxinv);
            continue;
        }
        loop(j,0,n)
        {
            int mini=INT_MAX;
            loop(i,0,v.size())
            if(b1[v[i]+j]<mini)mini=b1[v[i]];
            t.clear();
            loop(i,0,v.size())
            {
                if(b1[v[i]+j]==mini)t.pb(v[i]);
            }
            v.clear();
            loop(i,0,t.size())
            {
               v.pb(t[i]);
            }
        }



        printf("%d %lld\n",v[0]-1,maxinv);


    }
    return 0;
}

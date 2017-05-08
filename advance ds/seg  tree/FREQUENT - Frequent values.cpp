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

int a[100001];
int st[1000000];//contain required ans within range
int st_start[1000000];//start element of that interval jise this node represent kar raha hai
int st_end[1000000];//end element of that interval jise this node represent kar raha hai
int st_ls[1000000];//no of consecutive start element us interval ke
int st_le[1000000];//no of consecutive end element us particular interval ke jise yah node represent kar raha hai

void build(int sti,int i,int j)
{
    if(i==j)
    {
        st_start[sti]=a[i];
        st_end[sti]=a[i];
        st_ls[sti]=1;
        st_le[sti]=1;
        st[sti]=1;
        return;
    }
    int mid=(i+j)/2;
    int lc=2*sti;
    int rc=(2*sti+1);
    build(lc,i,mid);
    build(rc,mid+1,j);

    if(st_end[lc]==st_start[rc])
    {
        st[sti]=max(max(st[lc],st[rc]),st_le[lc]+st_ls[rc]);
        st_start[sti]=st_start[lc];
        st_end[sti]=st_end[rc];
        if(st_end[rc]==st_start[rc])st_le[sti]=st_le[rc]+st_le[lc];
        else st_le[sti]=st_le[rc];
        if(st_end[lc]==st_start[lc])st_ls[sti]=st_ls[rc]+st_ls[lc];
        else st_ls[sti]=st_ls[lc];
    }
    else
    {
        st[sti]=max(st[lc],st[rc]);
        st_start[sti]=st_start[lc];
        st_end[sti]=st_end[rc];
        st_le[sti]=st_le[rc];
        st_ls[sti]=st_ls[lc];
    }
}

int query(int l,int r,int sti,int i,int j)
{
    if(l>j||r<i)return 0;
    if(l<=i&&r>=j)return st[sti];
    int lc=2*sti;
    int rc=2*sti+1;
    int m=(i+j)/2;

    int ansl=query(l,r,lc,i,m);
    int ansr=query(l,r,rc,m+1,j);
    //m1s
    if(st_end[lc]==st_start[rc]&&ansl!=0&&ansr!=0)//middle and middle+1 are same they may contribute to final ans
    {
        int x=min(st_le[lc],m-l+1)+min(st_ls[rc],r-m);//min for checking if its(length of end element of lc) is in range of given query
        return max(max(ansl,ansr),x);
    }
    //m1e
    else return max(ansl,ansr);//if middle and middle+1 are not same
}


int main()
{
    int n,q,l, r;
    while(true)
    {
        le(n);
        if(n==0)
            break;
        le(q);
        loop(i,1,n+1)
        le(a[i]);

        build(1,1,n);
//        loop(i,1,16)
//        cout<<st[i]<<" ";
//        cout<<endl;
        //  cout<<" s"<<endl;
        loop(i,0,q)
        {
            le2(l,r);
            printf("%d\n",query(l,r,1,1,n));
        }
    }
    return 0;
}

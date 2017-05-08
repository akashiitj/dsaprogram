#include<bits/stdc++.h>
using namespace std;



int mod= 1000000007;

#define fast      ios_base::sync_with_stdio(false);
#define frmlty     int test_case;cin>>test_case;while(test_case--)

#define vi        vector<int>
#define vs        vector<string>
#define vint       vector<int>
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
#define leint(x) scanf(" %I64d",&x);
#define le2int(x,y) scanf(" %I64d%I64d",&x,&y);

#define F first;
#define S second;

int a[100005];
int st[1000005];//for sum query
int st1[1000005];//for min query

void build(int sti,int si,int ei)//sti node of segment tree hold sum from start index  to end index of original array
{
    if(si==ei)
    {
        st[sti]=a[si];
        st1[sti]=a[si];
        return;
    }
    int mid=(si+ei)/2;
    build(2*sti,si,mid);
    build((2*sti)+1,mid+1,ei);
    st[sti]=st[2*sti]+st[(2*sti)+1];//for sum query
    st1[sti]=min(st1[2*sti],st1[(2*sti)+1]);//for min query

}

int minq(int i,int j,int sti,int si,int ei)
{
    if(i<=si&&j>=ei)//this imply whole part from si to ei must be going to add up for required sum
        return st1[sti];
    if((si>j)||(i>ei))//this is not going to be included
        return INT_MAX;
    int mid =(si+ei)/2;
    return min(minq(i,j,2*sti,si,mid),minq(i,j,(2*sti)+1,mid+1,ei));
}


int main()
{
    // std::ios_base::sync_with_stdio(false);
    int n,q;
    int hv;
    int l,r;
    int hc=0;
    frmlty
    {
        hc++;
        le2(n,q);
        loop(i,1,n+1)
        le(a[i]);
        build(1,1,n);
        printf("Scenario #%d:\n\n",hc);
        loop(i,0,q)
        {
            le2(l,r);
            hv = minq(l,r,1,1,n);
            printf("%d\n",hv);
        }
    }
    return 0;
}


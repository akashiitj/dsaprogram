#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

#define fast      ios_base::sync_with_stdio(false);
#define frmlty     int test_case;cin>>test_case;while(test_case--)

#define vi        vector<int>
#define vs        vector<string>
#define vll       vector<LL>
#define pii       pair<int,int>

#define msi       map<string,int>
#define msit      map<string,int>::iterator
#define pb        push_back
#define mp        make_pair



#define loop(i,a,b)      for(ll i=a;i<b;i++)
#define rloop(i,a,b)     for(int i=b-1;i>=a;i--)

#define gcd(a,b)  __gcd(a,b)
#define mod       10000009

int a[501][501];
int ma[501];

//ll a[1000005];

ll st1[10005];//for min query

void build(ll i,ll si,ll ei)//i node of segment tree hold sum from start index  to end index of original array
{
    if(si==ei)
    {

        st1[i]=ma[si];
        return;
    }
    ll mid=(si+ei)/2;
    build(2*i,si,mid);
    build((2*i)+1,mid+1,ei);

    st1[i]=max(st1[2*i],st1[(2*i)+1]);//for min query

}

void updatemin(ll i,ll newvalue,ll sti,ll si,ll ei)//sti means index in seg tree representing si to ei interval,si starting index of segment of original array
{
    if(i<si||i>ei)return;
   // if(st1[sti]<newvalue)st1[sti]=newvalue;//if that index lie in between si to ei then update st node representing that interval

     if(si==ei)
        st1[sti]=newvalue;

    if(si!=ei)//condition for base case
    {
        ll mid=(si+ei)/2;
        updatemin(i,newvalue,sti*2,si,mid);
        updatemin(i,newvalue,(sti*2)+1,mid+1,ei);
        st1[sti]=max(st1[2*sti],st1[(2*sti)+1]);
    }


}


ll minq(ll i,ll j,ll sti,ll si,ll ei)
{
    if(i<=si&&j>=ei)//this imply whole part from si to ei must be going to add up for required sum
        return st1[sti];
    if((si>j)||(i>ei))//this is not going to be included
        return -1;
    ll mid =(si+ei)/2;
    return max(minq(i,j,2*sti,si,mid),minq(i,j,(2*sti)+1,mid+1,ei));
}

int main()
{
    fast;
    int n,m,q;
    cin>>n>>m>>q;
    loop(i,1,n+1)
    {
        ma[i]=0;
        loop(j,1,m+1)
        {
            cin>>a[i][j];
        }
    }

    loop(i,1,n+1)
    {
        int man=0;
        int j=1;
        while(j<=m)
        {
            int cv=0;
            if(a[i][j]==1)
            {
                while(a[i][j]==1)
                {
                    cv++;
                    j++;
                }
                if(cv>man)man=cv;
            }
            j++;
        }
        ma[i]=man;
    }
    build(1,1,n);
    int x,y;
    loop(i,0,q)
    {
        cin>>x>>y;
        a[x][y]=(a[x][y]+1)%2;
        int man=0;
        int j=1;
        while(j<=m)
        {
            int cv=0;
            if(a[x][j]==1)
            {
                while(a[x][j]==1)
                {
                    cv++;
                    j++;
                }
                if(cv>man)man=cv;
            }
            j++;
        }
        ma[x]=man;
       // cout<<x<<" x "<<ma[x]<<endl;
        updatemin(x,man,1,1,n);
        ll max1=minq(1,n,1,1,n);
        cout<<max1<<endl;
    }


}


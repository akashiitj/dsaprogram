#include <bits/stdc++.h>
using namespace std;

#define loop(i,a,b) for(ll i = a; i < b; i++)

typedef long long ll;
typedef unsigned long long ull;

//s ans;
ll a[200005];
ll st[10000000]= {0}; //for sum query
//s sa[10000000]= {0}; //struct array

void build(ll i,ll si,ll ei)//i node of segment tree hold sum from start index  to end index of original array
{
    if(si==ei)
    {

        st[i]=a[si];

        return;
    }
    ll mid=(si+ei)/2;
    build(2*i,si,mid);
    build((2*i)+1,mid+1,ei);
    st[i]=st[2*i]+st[(2*i)+1];//for sum query

    //cout<<sa[i].x[0]<<" "<<sa[i].x[1]<<" "<<sa[i].x[2]<<endl;
}

ll cs;
ll sum(ll i,ll j,ll sti,ll si,ll ei)
{
    if(i<=si&&j>=ei)//this imply whole part from si to ei must be going to add up for required sum
    {
        //cout<<sa[sti].x[0]<<" "<<sa[sti].x[1]<<" "<<sa[sti].x[2]<<endl;

        //cout<<cs<<" cs "<<endl;
        return st[sti];
    }
    if((si>j)||(i>ei))//this is not going to be included
        return 0;
    ll mid =(si+ei)/2;
    return sum(i,j,2*sti,si,mid)+sum(i,j,(2*sti)+1,mid+1,ei);//search for sum in left and rigth subtree
}
void update(ll i,ll j,ll sti,ll si,ll ei)//sti means index in seg tree representing si to ei interval,si starting index of segment of original array
{
    if(i>ei||j<si)return;
    // st[sti]=dx+st[sti];
    if(si==ei&&((si-i)%2)==0)
    {
        swap(a[si],a[si+1]);
        st[sti]=a[si];
        // cout<<sa[sti].x[0]<<" "<<sa[sti].x[1]<<" "<<sa[sti].x[2]<<endl;

    }
    if(si==ei&&((si-i)%2)!=0)
    {
        //swap(a[si],a[si+1]);
        st[sti]=a[si];
        // cout<<sa[sti].x[0]<<" "<<sa[sti].x[1]<<" "<<sa[sti].x[2]<<endl;

    }
    if(si!=ei)//condition for base case
    {
        ll mid=(si+ei)/2;
        update(i,j,sti*2,si,mid);
        update(i,j,(sti*2)+1,mid+1,ei);
        st[sti]=st[sti*2]+st[(sti*2)+1];
    }

}
int main()
{
    std::ios_base::sync_with_stdio(false);
    ll n,i,q;
    //  cout<<"enter size of ft or array +1"<<endl;
    cin>>n>>q;

    // n++;
    //ll a[n];

    for(i=1; i<=n; i++ )
    {
        cin>> a[i];

    }

    build(1,1,n);

    ll wq;
    // unsigned long long c=0;
    ll x,y,j;
    while(q--)
    {
        cin>>wq;
        if(wq==1)
        {
            cin>>x>>y;

            update(x,y,1,1,n);
            //a[x]=y;
        }
        else
        {
            cin>>x>>y;

            cout<<sum(x,y,1,1,n)<<endl;

        }


    }
    return 0;
}


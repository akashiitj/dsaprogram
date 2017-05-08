#include <bits/stdc++.h>
using namespace std;

#define loop(i,a,b) for(ll i = a; i < b; i++)

typedef long long ll;
typedef unsigned long long ull;
struct s
{
    ll x[3];
};
s ans;
ll a[100005];
ll st[10000000]= {0}; //for sum query
s sa[10000000]= {0}; //struct array

void build(ll i,ll si,ll ei)//i node of segment tree hold sum from start index  to end index of original array
{
    if(si==ei)
    {
        sa[i].x[0]=1;
        sa[i].x[1]=0;
        sa[i].x[2]=0;
        st[i]=a[si];
        if(a[si]%3==0)sa[i].x[0]++;
        else if(a[si]%3==1)sa[i].x[1]++;
        else if(a[si]%3==2)sa[i].x[2]++;
        //  cout<<sa[i].x[0]<<" "<<sa[i].x[1]<<" "<<sa[i].x[2]<<endl;
        return;
    }
    ll mid=(si+ei)/2;
    build(2*i,si,mid);
    build((2*i)+1,mid+1,ei);
    st[i]=st[2*i]+st[(2*i)+1];//for sum query
    sa[i].x[(st[2*i]+0)%3]=sa[2*i].x[(st[2*i]+0)%3]+sa[(2*i)+1].x[0]-1;
    sa[i].x[(st[2*i]+1)%3]=sa[2*i].x[(st[2*i]+1)%3]+sa[(2*i)+1].x[1];
    sa[i].x[(st[2*i]+2)%3]=sa[2*i].x[(st[2*i]+2)%3]+sa[(2*i)+1].x[2];

    //cout<<sa[i].x[0]<<" "<<sa[i].x[1]<<" "<<sa[i].x[2]<<endl;
}

ll cs;
ll sum(ll i,ll j,ll sti,ll si,ll ei)
{
    if(i<=si&&j>=ei)//this imply whole part from si to ei must be going to add up for required sum
    {
        //cout<<sa[sti].x[0]<<" "<<sa[sti].x[1]<<" "<<sa[sti].x[2]<<endl;
        ans.x[(cs+0)%3]=sa[sti].x[0]+ ans.x[(cs+0)%3]-1;
        ans.x[(cs+1)%3]=sa[sti].x[1]+ ans.x[(cs+1)%3];
        ans.x[(cs+2)%3]=sa[sti].x[2]+ ans.x[(cs+2)%3];
        //  cout<<ans.x[0]<<" "<<ans.x[1]<<" "<<ans.x[2]<<endl;
        cs=cs+st[sti];
        //cout<<cs<<" cs "<<endl;
        return st[sti];
    }
    if((si>j)||(i>ei))//this is not going to be included
        return 0;
    ll mid =(si+ei)/2;
    return sum(i,j,2*sti,si,mid)+sum(i,j,(2*sti)+1,mid+1,ei);//search for sum in left and rigth subtree
}
void update(ll i,ll dx,ll sti,ll si,ll ei)//sti means index in seg tree representing si to ei interval,si starting index of segment of original array
{
    if(i<si||i>ei)return;
    st[sti]=dx+st[sti];
    if(si==ei)
    {
        sa[sti].x[0]=1;
        sa[sti].x[1]=0;
        sa[sti].x[2]=0;
        st[sti]=a[si];
        if(a[si]%3==0)sa[sti].x[0]++;
        else if(a[si]%3==1)sa[sti].x[1]++;
        else if(a[si]%3==2)sa[sti].x[2]++;
        // cout<<sa[sti].x[0]<<" "<<sa[sti].x[1]<<" "<<sa[sti].x[2]<<endl;

    }
    if(si!=ei)//condition for base case
    {
        ll mid=(si+ei)/2;
        update(i,dx,sti*2,si,mid);
        update(i,dx,(sti*2)+1,mid+1,ei);
        sa[sti].x[(st[2*sti]+0)%3]=sa[2*sti].x[(st[2*sti]+0)%3]+sa[(2*sti)+1].x[0]-1;
        sa[sti].x[(st[2*sti]+1)%3]=sa[2*sti].x[(st[2*sti]+1)%3]+sa[(2*sti)+1].x[1];
        sa[sti].x[(st[2*sti]+2)%3]=sa[2*sti].x[(st[2*sti]+2)%3]+sa[(2*sti)+1].x[2];
        //  cout<<sa[sti].x[0]<<" "<<sa[sti].x[1]<<" "<<sa[sti].x[2]<<endl;
    }

}
main()
{
    std::ios_base::sync_with_stdio(false);
    ll n,i,q;
    //  cout<<"enter size of ft or array +1"<<endl;
    cin>>n>>q;
    string s;
    cin>>s;
    // n++;
    //ll a[n];

    for(i=1; i<=n; i++ )
    {
        a[i]=s[i-1]-48;

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
            ll tv=a[x];
            a[x]=y;
            update(x,a[x]-tv,1,1,n);
            //a[x]=y;
        }
        else
        {
            cin>>x>>y;
            ans.x[0]=1;
            ans.x[1]=0;
            ans.x[2]=0;
            cs=0;
            sum(x,y,1,1,n);
            ull ans1=0;

            for(ll i=0; i<3; i++)
                ans1 += (ans.x[i]*(ans.x[i]-1))/2;
            cout<<ans1<<endl;
        }


    }
}

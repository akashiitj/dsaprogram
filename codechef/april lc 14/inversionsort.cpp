#include<bits/stdc++.h>

using namespace std;

typedef int  ll;
#define loop(i,a,b)      for(ll i=a;i<b;i++)

#define fast      ios_base::sync_with_stdio(false)
#define frmlty     ll test_case;cin>>test_case;while(test_case--)

#define infi 1000000

struct node
{
    ll vn;//vertex no

    node* ptav;//polling to adjacent vertex
};



node v[210];

ll m;//total no of nodes

void addedge(ll i,ll j)// i and j are node number
{
    node *n1=new node;
    n1->ptav=v[i].ptav;
    n1->vn=j;

    v[i].ptav=n1;
}


ll visit[210]= {0};

ll dismatrix[210][210];

queue<ll> q;

void bfs(ll svn)//source vertex no
{

    visit[svn]=1;
    q.push(svn);
    dismatrix[svn][svn]=1;
    while(q.empty()!=1)
    {
        ll pvn=q.front();//present vertex no
        q.pop();
        node *n1=v[pvn].ptav;

        while(n1!=NULL)
        {
            ll cvn=n1->vn;//child vertex no
            if(visit[cvn]!=1)
            {
                dismatrix[svn][cvn]=1;

                q.push(cvn);
                visit[cvn]=1;
            }
            n1=n1->ptav;
        }
    }

}


void show()
{
    //graph prlling
    for(ll i=1; i<=m; i++)//see how to pass size since gp is poller so we cant use gp.length
    {
        node *hp=v[i].ptav;
        cout<<v[i].vn<<"  ";
        while(hp!=NULL)
        {
            cout<<hp->vn<<"  ";
            hp=hp->ptav;
        }
        cout<<endl;
    }
}



ll dp[2][210];

ll ae[200005];

ll dpm[2][210];

int main()
{
    fast;
    ll v1,v2;
    //  cout<<"enter total no of nodes"<<endl;
    ll k,n;
    frmlty
    {
        cin>>m>>k>>n;
//   cout<<"enter values of nodes"<<endl;
        loop(i,1,m+1)
        {
            //cout<<i<<": ";
            //cin>>v[i].vv;
            v[i].vn=i;
            v[i].ptav=NULL;
        }

        loop(i,0,k)
        {
            cin>>v1;
            cin>>v2;
            addedge(v1,v2);
            addedge(v2,v1);
        }

        loop(i,1,m+1)
        loop(j,1,m+1)
        dismatrix[i][j]=infi;


        loop(i,1,m+1)
        {
            dp[0][i]=0;
            dpm[0][i]=0;
            loop(i,1,m+1)
            visit[i]=0;

            bfs(i);
        }


        ll x;
        ll mini=infi;
        ll flag;
        ll ans=infi;
        ll crnt=1;
        loop(i,1,n+1)
        cin>>ae[i];
        ll i1=1;
        loop(i,1,n+1)
        {
            x=ae[i];
            flag=0;
            dpm[crnt][0]=infi;
            loop(j,1,m+1)
            {
                dp[i1][j]=infi;
                mini=infi;
                if(dismatrix[x][j]!=infi)
                {
                    if(j!=x)
                        dp[i1][j]=dpm[!crnt][j]+1;
                    else dp[i1][j]=dpm[!crnt][j] ;
                }
                dpm[crnt][j]=min(dpm[crnt][j-1],dp[i1][j]);
                if(dp[i1][j]>=infi)flag++;
            }
            crnt= !crnt;
            if(flag==m)//means you are not able to fill ith position such that upto this point it is sorted
            {
                ans=-1;
                break;
            }
            i1= crnt;
        }
        if(ans!=-1)
        {
            loop(i,1,m+1)
            ans=min(ans,dp[n%2][i]);
        }
        cout<<ans<<endl;



    }
    return 0;
}

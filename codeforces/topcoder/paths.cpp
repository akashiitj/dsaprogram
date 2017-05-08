#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll a[101][101];
ull c[101][101]= {0};

struct check
{
    vector<ll > x1;

};

check ca[101][101];
void llia(ll n1,ll n2)
{
    for(ll i=0; i<n1; i++)
    {
        for(ll j=0; j<n2; j++)
        {
            c[i][j]=0;
            a[i][j]=0;
        }
    }


}
ull count1(ll n1,ll n2)
{
    for(ll i=0; i<n1; i++)
    {
        for(ll j=0; j<n2; j++)
        {
            if(i>=0&&j-1>=0)
            {
                ll bo=0;
                for (std::vector<ll>::iterator it = ca[i][j].x1.begin() ; it != ca[i][j].x1.end(); it=it+2)
                {
                    //cout<<*it<<endl;
                    if(*it==i&&*(it+1)==j-1)
                        bo=1;
                }
                if(bo==0)
                    c[i][j]=c[i][j]+c[i][j-1];
            }
            if(i-1>=0&&j>=0)
            {
                ll bo=0;
                for (std::vector<ll>::iterator it = ca[i][j].x1.begin() ; it != ca[i][j].x1.end(); it=it+2)
                {
                    // cout<<*it<<endl;
                    if(*it==i-1&&*(it+1)==j)
                        bo=1;
                }
                if(bo==0)
                    c[i][j]=c[i][j]+c[i-1][j];
            }
            // cout<<c[i][j]<<" ";
        }
    }
    return c[n1-1][n2-1];
}
int main()
{

    ll t,w,h,n;
    ll x,y,a,b;
    cin>>t;
    while(t--)
    {
        c[0][0]=1;
        cin>>w>>h;
        w++;
        h++;
        llia(w,h);
        cout<<"enter no of edges to block";
        c[0][0]=1;
        cin>>n;
        while(n--)
        {

            cin>>x>>y>>a>>b;
            if(x>=a&&y>=b)
            {
                ca[x][y].x1.push_back(a);
                ca[x][y].x1.push_back(b);

            }
            else
            {
                ca[a][b].x1.push_back(x);
                ca[a][b].x1.push_back(y);

            }
        }
        cout<<count1(w,h)<<endl;


    }


    return 0;
}




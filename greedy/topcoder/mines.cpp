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

vector<int> getAllocation(vector<string> mines, int miners)
{
    int n=mines.size();
    double p[n+1][8];
    loop(i,0,n)
    {
        loop(w,0,7)
        {
            if(w==0)
            {
                p[i][w]=0.0;
                continue;
            }
            double profit=0.0;
            loop(mn,0,7)//mines no
            {
                double percent;


                //   cout<<mines[i].substr((mn*5),3)<<" ";
                percent=(double)((double)atoi(mines[i].substr((mn*5),3).c_str())/(double)100.0);

                //  cout<<mines[i].substr((mn*3+2),3)<<" ";
                //     cout.setf(ios::fixed);
                //       cout<<setprecision(2)<<percent<<" ";
                if(w<mn)
                    profit=profit+(double)(60.0*(double)w)*(double)percent;

                else if(w==mn)
                    profit=profit+50.0*(double)percent*(double)w;
                else
                    profit=profit+((50.0*(double)mn)-(double)(w-mn)*20.0)*(double)percent;


            }
            p[i][w]=profit;
            //cout.setf(ios::fixed);
            //  cout<<setprecision(2)<< p[i][w]<<" "<<cout<<endl;
        }
        //cout<<endl;
    }
    loop(i,0,n)
    {
        p[i][7]=-1000000000.0;
        for(int j=6; j>0; j--)
            p[i][j] = p[i][j]-p[i][j-1];
    }

//    loop(i,0,n)
//    {
//        loop(j,1,7)
//        cout<<p[i][j]<<" " ;
//
//        cout<<endl;
//    }
    int a[n];
    vector<int> ans;

    loop(i,0,n)
    {
        a[i]=1;
        ans.pb(0);
    }
    loop(i,0,miners)
    {
        double mini=-1000000000.0;
        int ci;
        loop(i,0,n)
        {
            if(p[i][a[i]]>mini)
            {
                mini=p[i][a[i]];
                ci=i;
            }
        }
        ans[ci]++;
        a[ci]++;

    }
    loop(i,0,n)
    cout<<ans[i]<<" ";
    cout<<endl;

    return ans;
}

int main()
{
    vector<string> s=

    {
        "100, 000, 000, 000, 000, 000, 000",
        "090, 010, 000, 000, 000, 000, 000",
        "080, 020, 000, 000, 000, 000, 000",
        "075, 025, 000, 000, 000, 000, 000",
        "050, 050, 000, 000, 000, 000, 000",
        "025, 075, 000, 000, 000, 000, 000",
        "020, 080, 000, 000, 000, 000, 000",
        "010, 090, 000, 000, 000, 000, 000",
        "000, 100, 000, 000, 000, 000, 000",
        "000, 090, 010, 000, 000, 000, 000",
        "000, 080, 020, 000, 000, 000, 000",
        "000, 075, 025, 000, 000, 000, 000",
        "000, 050, 050, 000, 000, 000, 000",
        "000, 025, 075, 000, 000, 000, 000",
        "000, 020, 080, 000, 000, 000, 000",
        "000, 010, 090, 000, 000, 000, 000",
        "000, 000, 100, 000, 000, 000, 000",
        "000, 000, 090, 010, 000, 000, 000",
        "000, 000, 080, 020, 000, 000, 000",
        "000, 000, 075, 025, 000, 000, 000",
        "000, 000, 050, 050, 000, 000, 000",
        "000, 000, 025, 075, 000, 000, 000",
        "000, 000, 020, 080, 000, 000, 000",
        "000, 000, 010, 090, 000, 000, 000",
        "000, 000, 000, 100, 000, 000, 000",
        "000, 000, 000, 100, 000, 000, 000",
        "000, 000, 000, 090, 010, 000, 000",
        "000, 000, 000, 080, 020, 000, 000",
        "000, 000, 000, 075, 025, 000, 000",
        "000, 000, 000, 050, 050, 000, 000",
        "000, 000, 000, 025, 075, 000, 000",
        "000, 000, 000, 020, 080, 000, 000",
        "000, 000, 000, 010, 090, 000, 000",
        "000, 000, 000, 000, 100, 000, 000",
        "000, 000, 000, 000, 090, 010, 000",
        "000, 000, 000, 000, 080, 020, 000",
        "000, 000, 000, 000, 075, 025, 000",
        "000, 000, 000, 000, 050, 050, 000",
        "000, 000, 000, 000, 025, 075, 000",
        "000, 000, 000, 000, 020, 080, 000",
        "000, 000, 000, 000, 010, 090, 000",
        "000, 000, 000, 000, 000, 100, 000",
        "000, 000, 000, 000, 000, 090, 010",
        "000, 000, 000, 000, 000, 080, 020",
        "000, 000, 000, 000, 000, 075, 025",
        "000, 000, 000, 000, 000, 050, 050",
        "000, 000, 000, 000, 000, 025, 075",
        "000, 000, 000, 000, 000, 020, 080",
        "000, 000, 000, 000, 000, 010, 090",
        "000, 000, 000, 000, 000, 000, 100"
    };
    getAllocation(s,150);
    return 0;
}


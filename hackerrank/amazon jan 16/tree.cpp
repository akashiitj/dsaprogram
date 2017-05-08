//author akashiitj
#include<bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

ll mod= 1000000007;

//cout<<fixed<<setprecision(6)<<ans<<"\n";

#define tc     int test_case;cin>>test_case;while(test_case--)

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

#define scn(x) scanf("%d",&x);
#define scn2(x,y) scanf("%d%d",&x,&y);
#define scnll(x) scanf("%lld",&x);
#define scn2ll(x,y) scanf("%lld%lld",&x,&y);

#define F first
#define S second

int h[10001];

int main(){
    int n;
    cin >> n;
    vector<int> degree(n);
     priority_queue<pii> q;
    for(int degree_i = 0;degree_i < n;degree_i++){
       cin >> degree[degree_i];
        q.push(mp(degree[degree_i],degree_i+1));
    }

    vector<pii> v;
    int c=0;
    while(q.size()!=0)
    {
        pii x=q.top();
        q.pop();
          c++;
          if(c==4)
            break;
            cout<<x.first<<" "<<x.second<<"\n";
            if(x.first>0)
            {
                loop(i,0,x.first)

                {
                    pii y=q.top();
                    q.pop();
                    cout<<y.first<<" "<<y.second<<"\n";
                    if(h[y.second]==0)
                    {
                        h[y.second]=x.second;
                        y.first--;
                        v.pb(y);
                    }


                }

                loop(i,0,v.size())

                {
                 q.push(v[i]);

                }
                v.clear();
            }
    }
    cout<<"ddf\n";
    loop(i,1,n+1)
    {
        cout<<h[v[i].second]<<"\n";
    }
    return 0;
}


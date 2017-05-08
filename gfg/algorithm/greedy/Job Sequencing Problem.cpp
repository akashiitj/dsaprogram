
#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

ll mod= 1000000007;


#define frmlty     int test_case;cin>>test_case;while(test_case--)

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

#define le(x) scanf("%d",&x);
#define le2(x,y) scanf("%d%d",&x,&y);
#define lell(x) scanf("%lld",&x);
#define le2ll(x,y) scanf("%lld%lld",&x,&y);

#define F first
#define S second

int main()
{
    int n;
    le(n);
    pii a[n];
    int maxdeadline=-1;
    loop(i,0,n)
    {
        le2(a[i].F,a[i].S);
        maxdeadline=max(maxdeadline,a[i].S);

    }

    int occupy[maxdeadline+1];
    loop(i,0,maxdeadline+1)
    occupy[i]=0;
    sort(a,a+n);
    reverse(a,a+n);

    loop(i,0,n)
    cout<<a[i].F<<" "<<a[i].S<<endl;

    int deadline;
    loop(i,0,n)
    {
        deadline=a[i].S;
        for(int j=deadline;j>=1;j--)
        {
            if(occupy[j]==0)
            {
                occupy[j]=1;
                cout<<a[i].F<<" "<<a[i].S<<endl;
                break;
            }
        }
    }

    return 0;
}

/*
5
100 2
19 1
27 2
25 1
15 3
*/

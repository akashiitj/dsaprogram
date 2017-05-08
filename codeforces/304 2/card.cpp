#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

#define fast      ios_base::sync_with_stdio(false)
#define frmlty     int test_case;cin>>test_case;while(test_case--)

#define vi        vector<int>
#define vs        vector<string>
#define vll       vector<LL>
#define pii       pair<int,int>

#define msi       map<string,int>
#define msit      map<string,int>::iterator
#define pb        push_back_back
#define mp        make_pair



#define loop(i,a,b)      for(ll i=a;i<b;i++)
#define rloop(i,a,b)     for(int i=b-1;i>=a;i--)

#define gcd(a,b)  __gcd(a,b)
#define mod       10000009


int main()
{
    fast;
    //declare variable here
    int n;
    cin>>n;
    deque<int> v1,v1d;
    deque<int> v2,v2d;

    int v1n;
    cin>>v1n;
    int x;
    loop(i,0,v1n)
    {
        cin>>x;
        v1.push_back(x);
        v1d.push_back(x);
    }

    int v2n;
    cin>>v2n;

    loop(i,0,v2n)
    {
        cin>>x;
        v2.push_back(x);
        v2d.push_back(x);
    }
    ll c=0;
    int t1,t2;
    // cout<<"c1 "<<endl;
    while(true)
    {   if(c>100010)
    {

        cout<<"-1"<<endl;
  break;
    }
        if(v1.size()==0||v2.size()==0)
        {
            if(v1.size()!=0)
                cout<<c<<" "<<1<<endl;
            else cout<<c<<" "<<2<<endl;
            break;
        }
        t1=v1.front();
        t2=v2.front();
        v1.pop_front();
        v2.pop_front();
        c++;
       // cout<<t1<<" t "<<t2<<endl;
        if(t1>t2)
        {
            v1.push_back(t2);
            v1.push_back(t1);
        }
        if(t2>t1)
        {
            v2.push_back(t1);
            v2.push_back(t2);
        }
       // cout<<v1.front()<<" ta "<<v2.front()<<endl;


        }


    }





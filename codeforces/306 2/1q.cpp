
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




int main()
{
    string s;
    cin>>s;
    int a[s.length()];
    loop(i,0,s.length())
    {
        a[i]=s[i]-48;
    }
    int n=s.length();
    loop(i,0,n)
    {
        if(a[i]%8==0)
        {

            cout<<"YES"<<"\n";
            cout<<a[i]<<"\n";
            return 0;
        }
    }
    int x;
    loop(i,0,n-1)
    {

        loop(j,i+1,n)
        {
            x=(a[i]*10)+a[j];
            if((x%8)==0)
            {
                cout<<"YES"<<"\n";
                cout<<x<<"\n";
                return 0;
            }
        }
    }
    loop(i,0,n-2)
    {

        loop(j,i+1,n-1)
        {
            loop(k,j+1,n)
            {
                x=(a[i]*100)+(a[j]*10)+a[k];

                if(x%8==0)
                {
                    cout<<"YES"<<"\n";
                    if(x==0)
                    {
                       x=a[0]*1000;
                    }
                    cout<<x<<"\n";
                    return 0;

                }
            }
        }
    }
    cout<<"NO"<<"\n";
    return 0;
}


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
#define pb        push_back
#define mp        make_pair



#define loop(i,a,b)      for(int i=a;i<b;i++)
#define rloop(i,a,b)     for(int i=b-1;i>=a;i--)

#define gcd(a,b)  __gcd(a,b)
#define mod       1000000007



int main()
{
    fast;
    //declare variable here
    frmlty
    {
        int n;
        cin>>n;
        int a[n];
        loop(i,0,n)
        cin>>a[i];
        int d=-1,r=-1;
        if(a[1]-a[0]==a[2]-a[1])
            d=a[1]-a[0];

       else if(a[1]%a[0]==0&&a[2]%a[1]==0&&a[1]/a[0]==a[2]/a[1])
        {

                r=a[1]/a[0];
        }
        //let assume 2 term to be ap

       else if(a[3]-a[1]==a[1]-a[0])
            d=a[1]-a[0];

       else if(a[1]%a[0]==0&&a[3]%a[1]==0&&a[1]/a[0]==a[3]/a[1])
        {

                r=a[1]/a[0];
        }
       else if(a[3]-a[2]==a[2]-a[0])
            d=a[2]-a[0];

     else   if(a[2]%a[0]==0&&a[3]%a[2]==0&&a[2]/a[0]==a[3]/a[2])
        {
                r=a[2]/a[0];
        }

        cout<<d<<" "<<r;
    }
    return 0;
}


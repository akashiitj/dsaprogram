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
    int n,j;
    string s,ans,t1,t2;
    frmlty
    {
        cin>>n;
        cin>>s;
        ans=s;
        int j,k;
        loop(i,0,n)
        {   t1=s;
            t2=s;
            j=i;

            k=i;
            while(j-1>=0)
            {
                swap(t1[j],t1[j-1]);
                if(t1<ans)ans=t1;
                j--;
            }
            while(k+1<n)
            {
                swap(t2[k],t2[k+1]);
                if(t2<ans)ans=t2;
                k++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}


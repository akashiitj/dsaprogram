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

char a[100][100];

int main()
{
    fast;
    //declare variable here
    loop(i,0,100)
    loop(j,0,100)
    a[i][j]='S';

    int n,k;
    cin>>n>>k;

    int tc=n*n;
    if(tc%2==1)tc=(tc/2)+1;
    else tc=tc/2;

    if(k>tc)
    {

        cout<<"NO"<<endl;
        return 0;
    }
    int c=0;

    cout<<"YES"<<endl;
    loop(i,0,n)
    {
        for(int j=(i)%2; j<n; j=j+2)
        {    if(c==k)goto qw;
            a[i][j]='L';
            c++;

        }
    }
qw:

    loop(i,0,n)
    {
        loop(j,0,n)
        {
            cout<<a[i][j];
        }
        cout<<endl;
    }




}


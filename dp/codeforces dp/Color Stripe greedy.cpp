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

#define loop(i,a,b)      for(int i=a;i<b;i++)
#define rloop(i,a,b)     for(int i=b-1;i>=a;i--)

#define gcd(a,b)  __gcd(a,b)
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))

#define le(x) scanf("%d",&x);
#define le2(x,y) scanf("%d%d",&x,&y);
#define lell(x) scanf(" %I64d",&x);
#define le2ll(x,y) scanf(" %I64d%I64d",&x,&y);

#define F first;
#define S second;

//cout<<fixed<<setprecision(6)<<ans<<"\n";

int main()
{
    int n,k;
    le2(n,k);
    string s,s1,s2;
    cin>>s;
    s1=s;
    s2=s;
    int pre=0, cur=1;
    if(k==2)
    {
        loop(i,0,n)
        {

            s1[i]=(char)('A'+pre);//first you are addintion of string hat gives tle
            s2[i]=(char)('A'+cur);

            swap(pre,cur);
        }
        int c1=0,c2=0;
        loop(i,0,n)
        {
            if(s[i]!=s1[i])c1++;
            if(s[i]!=s2[i])c2++;
        }
        cout<<min(c1,c2)<<"\n";
        if(min(c1,c2)==c1)  cout<<s1<<"\n";
        else cout<<s2<<"\n";
        return 0;
    }
    int i=0,j,c,ans=0;
    while(i<n)
    {
        j=i;
        c=0;
        while(j<n&&s[j]==s[i])
        {
            j++;
            c++;
        }
        if(c>1)
        {
            char hv;
            if(s[i]!='A'&&(i+c)==n)hv='A';
            else if(s[i+c]!='A'&&s[i]!='A')hv='A';
            else if(s[i+c]!='B'&&s[i]!='B')hv='B';
            else if(s[i+c]!='C'&&s[i]!='C')hv='C';

            for(int k=i+1; k<i+c; k=k+2)
            {
               ans++;
                s[k]=hv;
            }
        }
        i=i+c;
    }
    cout<<ans<<"\n";
    cout<<s<<"\n";
    return 0;
}


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
//#define lell(x) scanf("%lld",&x);
//#define le2ll(x,y) scanf("%lld%lld",&x,&y);
int cs[26][10000+2];//at each position of # in string tell us what is maximum number of each character from starting
int s[26][10000+1];//at each position of # in string tell us what is maximum number of each character from previous #position  or other words between 2 #position
int mcs[10000+1];//at each position of # in string tell us what is maximum number of character from starting
int mcsr[10000+1];//at each position of # in string tell us what is maximum number of character from end
int m[10000+1];//at each position of # in string tell us what is maximum number of character from privoius # position

int main()
{
    string str;
    frmlty
    {
        vector<int> v;//to store index of #
        v.clear();
        cin>>str;
        int n=str.length();

        loop(i,0,26)
        {
            cs[i][0]=0;
            s[i][0]=0;
            cs[i][n+1]=0;
        }
        int pi=0;
        int a[26]={};
        int dv,dv1;
        loop(i,1,n+1)
        {
            if(str[i-1]=='#')
            {
                v.pb(i);
                dv=-1;
                dv1=-1;
                loop(j,0,26)
                {
                    s[j][i]=a[j];
                    cs[j][i]=cs[j][pi]+s[j][i];
                    if(s[j][i]>dv)dv=s[j][i];
                    if(cs[j][i]>dv1)dv1=cs[j][i];
                    a[j]=0;
                }
                pi=i;
                mcs[i]=dv1;
                m[i]=dv;
            }
            else
            {

                a[str[i-1]-'a']++;
            }
        }
        pi=n+1;
//        loop(j,0,n+1)
//        cout<<mcs[j]<<" ";
//
//        cout<<endl;
//
//        loop(j,0,n+1)
//        cout<<m[j]<<" ";
//
//cout<<endl;
        loop(j,0,26)
        a[j]=0;
        for(int i=n; i>0; i--)
        {
            if(str[i-1]=='#')
            {
                dv=-1;
                dv1=-1;
                loop(j,0,26)
                {
                    s[j][i]=a[j];
                    cs[j][i]=cs[j][pi]+s[j][i];
                    //     if(s[j][i]>dv)dv=s[j][i];
                    if(cs[j][i]>dv1)dv1=cs[j][i];
                    a[j]=0;
                }
                pi=i;
                mcsr[i]=dv1;

            }
            else
            {

                a[str[i-1]-'a']++;
            }
        }

//        loop(j,1,n+1)
//        cout<<mcsr[j]<<" "<<str[j-1]<<endl;
//        cout<<endl;
        int ans=-1;
        int ca;
        if(v.size()<=2)
            cout<<"0\n";
        else{
            loop(i,0,v.size()-2)
            {
                if(v[i+1]-v[i]==1||v[i+2]-v[i+1]==1||mcs[v[i]]<=0||mcsr[v[i+2]]<=0)continue;//see defination
                ca=mcs[v[i]]+m[v[i+1]]+m[v[i+2]]+mcsr[v[i+2]];
                if(ca>ans)ans=ca;
            }
            if(ans==-1)cout<<"0\n";
            else cout<<ans+3<<"\n";
        }
    }
    return 0;
}


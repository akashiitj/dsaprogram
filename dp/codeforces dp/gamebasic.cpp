

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


#define F first
#define S second

int main()
{
    frmlty
    {
        string s;
        cin>>s;
        int n=s.length();
        vi v;
        int flag;
        loop(i,1,12+1)
        {
            if(i==5||i==8||i==9||i==10||i==11||i==7)continue;


            for(int j=0; j<i; j++)
            {
                flag=0;
                // if(i==3)cout<<j<<"\n";
                for(int k=j; k<n; k=k+i)
                {
                    //    if(i==3)cout<<s[k]<<" ";
                    if(s[k]=='O')
                    {
                        flag=1;
                        break;
                    }
                }
                // if(i==3)  cout<<"\n"<<flag<<" "<<12/i<<"\n";
                if(flag==0)
                {

                    v.pb(12/i);
                    break;
                }
            }
        }

        sort(v.begin(),v.end());
        cout<<v.size()<<" ";
        loop(i,0,v.size())
        {
            if(v[i]==1)cout<<"1x12 ";
            if(v[i]==2)cout<<"2x6 ";
            if(v[i]==3)cout<<"3x4 ";
            if(v[i]==4)cout<<"4x3 ";
            if(v[i]==6)cout<<"6x2 ";
            if(v[i]==12)cout<<"12x1 ";
        }
        cout<<"\n";
    }
    return 0;
}



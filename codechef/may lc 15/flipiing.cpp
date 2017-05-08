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
    int n,k;
    int si, li,c,ans;
    string s;
    frmlty
    {
        cin>>n>>k;
        cin>>s;
        si=0;
        li=0;
        c=0;
        ans=0;
        // cout<<n<<" "<<k<<endl;
        if(k==1)
        {
            char c1='0';
            char c2='1';
            int ans1=0;
            int ans2=0;
            loop(i,0,n)

            {
                if(s[i]!=c1)ans1++;
                c1=(c1+1)%2+48;

                if(s[i]!=c2)ans2++;
                c2=(c2+1)%2+48;

            }
            cout<<min(ans1,ans2)<<endl;
            int x1=0,x2=1;
            if(ans1==min(ans1,ans2))
            {

                loop(i,0,n)
                {
                    cout<<x1;
                    x1=(x1+1)%2;

                }
            }
            else
            {

                loop(i,0,n)
                {
                    cout<<x2;
                    x2=(x2+1)%2;

                }
            }
            cout<<endl;
        }
        else{
            c=0;
            while(li<n){
                c=0;
                while(s[si]==s[li]&&li<n)
                {
                    c++;
                    li++;
                }
               // cout<<si<<" "<<li<<"\n";
                c=floor(c/(k+1));
                 ans=ans+c;
                if(c>=1)
                {
                    int si1=si;
                    int c2=1;
                    while(c2<c)
                    {
                        s[si1+k]=((s[si1+k]+1)%2)+48;
                        c2++;
                        si1=si1+k+1;
                    }
                    s[(si1+li-1)/2]= ((s[(si1+li-1)/2]+1)%2)+48;//for last block....

                }

                si=li;
                c=0;
            }
            cout<<ans<<endl;
            cout<<s<<endl;
        }
        }

    return 0;
}


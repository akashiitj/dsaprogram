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



#define loop(i,a,b)      for(ll i=a;i<b;i++)
#define rloop(i,a,b)     for(int i=b-1;i>=a;i--)

#define gcd(a,b)  __gcd(a,b)
#define mod       10000009


int main()
{
    fast;
    string s;
    int maxc,sec;
    frmlty
    {
        cin>>s;
        // cout<<s<<endl;
        vector<pair<int,int> > v;
        loop(i,0,26)
        {
            v.push_back(make_pair(0,i));
        }
        loop(i,0,s.length())
        v[s[i]-97].first++;

        sort(v.begin(),v.end());

 //loop(i,0,26)
 //cout<<v[i].first<<" "<<v[i].second<<endl;
 //cout<<endl;


        maxc=v[25].first;
        sec=0;
        loop(i,0,25)
        sec=sec+v[i].first;
   //   cout<<maxc<<" "<<sec<<endl;
        if(maxc-1>sec)
        {
            cout<<-1<<endl;
            continue;
        }

        int si=0;
        string s1;1
        loop(i,0,26)
        if(v[i].first!=0)
        {
            si=i;
            break;
        }
        char c[1];
        for(int i=25; i>=si; i--)
        {
            // s1=s1+v[i].second+97;
            c[0]=v[i].second+97;
            s1=s1+c[0];
        }
        int c1=0;
        int diff=0;
        string ans;
        loop(i,si,26)
        {
            string  s2=s1.substr(0,s1.length()-c1);

            loop(j,0,v[i].first-diff)
            ans=ans+s2;
            diff= v[i].first;
            c1++;
        }
        cout<<ans<<endl;




    }



}

